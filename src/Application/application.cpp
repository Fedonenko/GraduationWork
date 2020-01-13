#include "application.h"
#include "../MainWindow/mainapplicationwindow.h"
#include "../MainWindow/actionmainwindow.h"
#include "../MainWindow/pluginComponentWindow/electroniccomponentvaluewindow.h"
//#include "../MainWindow/iactionmainwindow.h"


Application::Application(int argc, char* argv[])
    : QApplication(argc, argv)
    , m_actions{ new MainWindow::ActionMainWindow() }//*/{ std::make_unique<MainWindow::ActionMainWindow>() }
{
    //m_actions = new MainWindow::ActionMainWindow();

    {
        QString path {
            "E:\\Diploma\\GraduationWork\\src\\Application\\resources\\styles.css"};
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

    m_componentWindow->show();
}

