#include <QDebug>

#include "application.h"
#include "mainapplicationwindow.h"
#include "actionmainwindow.h"
#include "pluginComponentWindow/electroniccomponentvaluewindow.h"

Application::Application(int argc, char* argv[])
    : QApplication(argc, argv)
    , m_actions{ new MainWindow::ActionMainWindow() }//*/{ std::make_unique<MainWindow::ActionMainWindow>() }
{
    //m_actions = new MainWindow::ActionMainWindow();

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
        connect(m_actions->menuBar()->resistor(), &QAction::triggered, this, &Application::onResistorComponents);
    }

    m_winui = new MainApplicationWindow( m_actions.get(), 320, 240);
    m_winui->show();
}

Application::~Application()
{
}

void Application::onResistorComponents()
{
    if(!m_componentWindow.get())
    {
        m_componentWindow.reset( new MainWindow::ElectronicComponentValueWindow());//std::make_unique<MainWindow::ElectronicComponentValueWindow>();
    }

    assert(m_componentWindow.get());

    m_componentWindow->setWindowTitle(tr("Resistors"));

    if(m_componentWindow->isHidden())
    {
        m_componentWindow->show();
    }

}

