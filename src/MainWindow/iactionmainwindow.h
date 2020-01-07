#ifndef IACTIONMAINWINDOW_H
#define IACTIONMAINWINDOW_H

#include <QAction>

#include "MainWindow_global.h"

//class QAction;

namespace MainWindow {

class IActionsMenuBar;

class MAINWINDOW_EXPORT IActionMainWindow
{
//    Q_OBJECT

public:
    IActionMainWindow() = default;
    virtual ~IActionMainWindow() = default;

    virtual IActionsMenuBar* menuBar() = 0;

};

}

#endif // IACTIONMAINWINDOW_H
