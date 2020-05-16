#include "application.h"

#include <QDebug>
#include <QSplashScreen>

#include <generalapi.h>
#include <mainapplicationwindow.h>
#include <actionmainwindow.h>
#include <pluginComponentWindow/electroniccomponentvaluewindow.h>

Application::Application(int argc, char* argv[])
    : QApplication(argc, argv)
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

    splashScreen.finish(m_winui);

    m_winui->show();
}

Application::~Application()
{
}

void Application::onResistorComponents()
{
    if(!m_componentWindow.get())
    {
        m_componentWindow = std::make_unique<MainWindow::ElectronicComponentValueWindow>();
    }

    assert(m_componentWindow.get());

    m_componentWindow->setWindowTitle(tr("Resistors"));

    if(m_componentWindow->isHidden())
    {
        m_componentWindow->show();
    }
}

