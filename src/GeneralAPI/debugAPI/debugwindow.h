#ifndef DEBUGWINDOW_H
#define DEBUGWINDOW_H

#include "gui/widget.h"

class QTextEdit;

namespace Ui {
    class DebugWidget;
}

class DebugWindow
        : public QWidget
{
    Q_OBJECT

public:
    DebugWindow( QWidget* parent = nullptr );
    ~DebugWindow();

    void currentStyleSheet(const QString& value);
    QString textStyleSheet() const;

private:
    std::unique_ptr<Ui::DebugWidget> m_ui;
};

#endif // DEBUGWINDOW_H
