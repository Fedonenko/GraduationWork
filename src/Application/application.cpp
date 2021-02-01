#include "application.h"

#include <QDebug>
#include <QSplashScreen>
#include <QSqlError>
#include <QSqlRecord>

#include <generalapi.h>
#include <mainapplicationwindow.h>
#include <actionmainwindow.h>
#include <pluginComponentWindow/electroniccomponentvaluewindow.h>
#include <pluginComponentWindow/electroniccomponentsmodel.h>
#include <ArrayCreatorByImage.h>

Application::Application(int argc, char* argv[])
    : QApplication(argc, argv)
    , m_componentsWindow{ nullptr }
    , m_componentsModel{ nullptr }
    , m_actions{ std::make_unique<MainWindow::ActionMainWindow>() }
    , m_generalAPI{ std::make_unique<GeneralAPI>() }

{
    QSplashScreen splashScreen(QPixmap(":/imageDownloadApp.jpg"));

    splashScreen.show();
    splashScreen.showMessage(tr("Подождите! Идёт загрузка приложения"), Qt::AlignJustify | Qt::AlignCenter, Qt::gray);

#ifdef DEBUG
    qDebug() << "Hello Application"
#endif

    {
        QString path {
            ":/styles.css"};
        QFile file(path);
        if(file.open(QIODevice::ReadOnly))
        {
            QString style{file.readAll()};
            setStyleSheet(style);
        }
    }

    {
        Q_ASSERT(connect(m_actions->menuBar()->resistor(), &QAction::triggered, this, &Application::onResistorComponents));
        Q_ASSERT(connect(m_actions->menuBar()->arrayCreator(), &QAction::triggered, this, &Application::onArrayCreator));
    }

    m_winui = new MainApplicationWindow( m_actions.get(), 320, 240);

    init();

    splashScreen.finish(m_winui);

    m_winui->show();
}

Application::~Application()
{
    m_componentsWindow.reset();
}

void Application::onResistorComponents()
{
    assert(m_componentsWindow.get());

    m_componentsWindow->setWindowTitle(tr("Resistors"));

    m_componentsModel->setTable("resistor");
    m_componentsModel->select();

    qDebug() << "setTable(\"resistor\");" << m_componentsModel->lastError();
    qDebug() << "ElectronicComponentsModel constructor after setTable \"resistor\""
             << " Error Type: " << m_componentsModel->lastError().type()

             << " is NoError: " << m_componentsModel->lastError().NoError
             << " lastError().text(): " << m_componentsModel->lastError().text();

    qDebug() << "record(0).value(0).toString(): " << m_componentsModel->record(0).value(0).toString();
    qDebug() << "record(0).value(1).toString(): " << m_componentsModel->record(0).value(1).toString();
    qDebug() << "record(0).value(2).toString(): " << m_componentsModel->record(0).value(2).toString();

    qDebug();

    qDebug() << "record(1).value(0).toString(): " << m_componentsModel->record(1).value(0).toString();
    qDebug() << "record(1).value(1).toString(): " << m_componentsModel->record(1).value(1).toString();
    qDebug() << "record(1).value(2).toString(): " << m_componentsModel->record(1).value(2).toString();


    if(m_componentsWindow->isHidden())
    {
        m_componentsWindow->show();
    }
}

void Application::onArrayCreator()
{
    if(!m_arrayCreatorWindow)
    {
        m_arrayCreatorWindow = new Dev::ArrayCreatorByImage(m_winui);
    }

    m_arrayCreatorWindow->show();
}

void Application::init()
{
    m_componentsModel = std::make_unique<MainWindow::ElectronicComponentsModel>(m_generalAPI->dataComponents());

    m_componentsWindow = std::make_unique<MainWindow::ElectronicComponentValueWindow>(m_componentsModel.get());
}

