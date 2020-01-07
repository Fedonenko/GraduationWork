#ifndef APPLICATION_H
#define APPLICATION_H

#include <memory>

#include <QApplication>

#include "Application_global.h"
//#include "../MainWindow/iactionmainwindow.h"
//#include "mainwindow.h"

class MainApplicationWindow;

namespace MainWindow {
    class IActionMainWindow;
}

class APPLICATION_EXPORT Application
        : public QApplication
{
    Q_OBJECT
public:
    Application(int, char*[]);
    ~Application();

private:
    MainApplicationWindow* m_winui;

    std::unique_ptr<MainWindow::IActionMainWindow> m_actions;
    //MainWindow::IActionMainWindow* m_actions;
};

#endif // APPLICATION_H
