#include "application.h"

#include <QDebug>
#include <QSplashScreen>
#include <QSqlError>

#include <generalapi.h>
#include <mainapplicationwindow.h>
#include <actionmainwindow.h>
#include <pluginComponentWindow/electroniccomponentvaluewindow.h>
#include <pluginComponentWindow/electroniccomponentsmodel.h>

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
        assert(connect(m_actions->menuBar()->resistor(), &QAction::triggered, this, &Application::onResistorComponents));
    }

    m_winui = new MainApplicationWindow( m_actions.get(), 320, 240);

    init();

    splashScreen.finish(m_winui);

    m_winui->show();
}

Application::~Application()
{
}

void Application::onResistorComponents()
{
    assert(m_componentsWindow.get());

    m_componentsWindow->setWindowTitle(tr("Resistors"));

    m_componentsModel->setTable("resistor");

    qDebug() << "setTable(\"resistor\");" << m_componentsModel->lastError();

    if(m_componentsWindow->isHidden())
    {
        m_componentsWindow->show();
    }
}

void Application::init()
{
    m_componentsModel = std::make_unique<MainWindow::ElectronicComponentsModel>(m_generalAPI->dataComponents());

    m_componentsWindow = std::make_unique<MainWindow::ElectronicComponentValueWindow>(m_componentsModel.get());
}

