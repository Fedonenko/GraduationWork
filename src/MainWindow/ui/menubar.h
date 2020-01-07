#ifndef MENUBAR_H
#define MENUBAR_H

#define DEBUG

#include <QWidget>

class QMenu;
class QWidget;

namespace Ui {
    class MenuBar;
}

namespace MainWindow {

class IActionsMenuBar;

class MenuBar : public QWidget
{
    Q_OBJECT

public:
    explicit MenuBar(IActionsMenuBar* actions/* = nullptr*/, QWidget *parent = nullptr);
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
