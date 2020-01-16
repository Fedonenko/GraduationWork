#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>

#include "MainWindow_global.h"
#include "draftWindow.h"

namespace MainWindow {
    class IActionMainWindow;
}

class MAINWINDOW_EXPORT MainApplicationWindow
        : public QMainWindow
{
    Q_OBJECT

public:
    MainApplicationWindow( MainWindow::IActionMainWindow* actions, int width = 800, int height = 600, QWidget* parent = nullptr);
    ~MainApplicationWindow();

public:
    Q_SLOT void slotNotImpl();

    QToolBar* createToolBar();

private:
    void initToolBar();
    void initMenuBar();

private:
    MainWindow::IActionMainWindow* m_actions;
    QMdiArea* m_mdiArea;
    Draft::DraftWindow* m_draftWindow;

};


#endif // MAINWINDOW_H
