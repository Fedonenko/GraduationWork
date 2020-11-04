#ifndef WIDGET_H
#define WIDGET_H

#include "GeneralAPI_global.h"

#include <QWidget>

class DebugWindow;

class GENERALAPI_EXPORT Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());

private Q_SLOTS:
    void showDebugWindow();

private:
    QAction* m_actionDebugWindow;
    DebugWindow* m_debugWindow;
};

#endif // WIDGET_H
