#include <QAction>
#include <QObject>

#include "actionmainwindow.h"
#include "actionsmenubar.h"

using namespace MainWindow;

/// <summary>
///
/// </summary>
ActionMainWindow::ActionMainWindow()
    : IActionMainWindow()
    , m_menuBar{ std::make_unique<ActionsMenuBar>() }
{
}

ActionMainWindow::~ActionMainWindow()
{}

IActionsMenuBar* ActionMainWindow::menuBar()
{
    return m_menuBar.get();
}
