#include "widget.h"

#include <QAction>

#include "debugAPI/debugwindow.h"

Widget::Widget(QWidget *parent, Qt::WindowFlags f)
    : QWidget(parent, f)
    , m_actionDebugWindow{ new QAction(this) }
    , m_debugWindow{ new DebugWindow(this) }
{    
    Q_ASSERT(connect(m_actionDebugWindow, &QAction::triggered, this, &Widget::showDebugWindow));

    m_actionDebugWindow->setShortcut(Qt::CTRL + Qt::SHIFT + Qt::Key_Q);
    addAction(m_actionDebugWindow);

}

void Widget::showDebugWindow()
{
    QString styleString = this->styleSheet();

    m_debugWindow->currentStyleSheet(styleString);
    m_debugWindow->show();
}
