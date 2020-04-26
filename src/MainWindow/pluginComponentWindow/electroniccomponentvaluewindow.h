#ifndef ELECTRONICCOMPONENTVALUEWINDOW_H
#define ELECTRONICCOMPONENTVALUEWINDOW_H

#include <QWidget>

#include "MainWindow_global.h"

namespace Ui {
    class ElectronicComponentValueWindow;
}

namespace  MainWindow {

class MAINWINDOW_EXPORT ElectronicComponentValueWindow
        : public QWidget
{
    Q_OBJECT

public:
    ElectronicComponentValueWindow(QWidget* parent = nullptr);
    ~ElectronicComponentValueWindow();

private:
    Ui::ElectronicComponentValueWindow* m_ui;
};

}

#endif // ELECTRONICCOMPONENTVALUEWINDOW_H
