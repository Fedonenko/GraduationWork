#ifndef MENUBAR_H
#define MENUBAR_H

#define DEBUG

#include <gui/widget.h>

class QMenu;

namespace Ui {
    class MenuBar;
}

namespace MainWindow {

class IActionsMenuBar;

class MenuBar : public Widget
{
    Q_OBJECT

public:
    explicit MenuBar(IActionsMenuBar* actions/* = nullptr*/, QWidget* parent = nullptr);
    ~MenuBar();

public slots:
    void onResistor();

private:
    QMenu* toolsMenu();

private:
    Ui::MenuBar* m_ui;

    IActionsMenuBar* m_actions;

};

}
#endif // MENUBAR_H
