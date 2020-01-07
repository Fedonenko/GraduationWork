#include "application.h"
#include "../MainWindow/mainapplicationwindow.h"
#include "../MainWindow/actionmainwindow.h"
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

    m_winui = new MainApplicationWindow( m_actions.get(), 320, 240);
    m_winui->show();
}

Application::~Application()
{
}

