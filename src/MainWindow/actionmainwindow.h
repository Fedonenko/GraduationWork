#ifndef ACTIONMAINWINDOW_H
#define ACTIONMAINWINDOW_H

#include <memory>

#include <QPointer>

#include "iactionmainwindow.h"
#include "MainWindow_global.h"

namespace MainWindow{

class MAINWINDOW_EXPORT ActionMainWindow
        : public IActionMainWindow
{
public:
    ActionMainWindow();
    ~ActionMainWindow() override;

    virtual IActionsMenuBar* menuBar() override;

private:
    std::unique_ptr<IActionsMenuBar> m_menuBar;
    //IActionsMenuBar* m_menuBar;

};

}

#endif // ACTIONMAINWINDOW_H
