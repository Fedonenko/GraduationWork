#ifndef MENUBAR_H
#define MENUBAR_H

#define DEBUG

#include <gui/widget.h>
#include <QPointer>

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
    QMenu* aboutMenu();

private:
    Ui::MenuBar* m_ui;

    IActionsMenuBar* m_actions;

    QPointer<QMenu> m_aboutMenu;
    QPointer<QMenu> m_toolsMenu;
};

}
#endif // MENUBAR_H
