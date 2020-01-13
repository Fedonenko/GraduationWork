#ifndef IACTIONMAINWINDOW_H
#define IACTIONMAINWINDOW_H

#include <QAction>

#include "MainWindow_global.h"

#include "iactionsmenubar.h"

//class QAction;

namespace MainWindow {

//class IActionsMenuBar;

class IActionMainWindow
{

public:
    IActionMainWindow() = default;
    virtual ~IActionMainWindow() = default;

    virtual IActionsMenuBar* menuBar() = 0;

};

}

#endif // IACTIONMAINWINDOW_H
