#ifndef ELECTRONICCOMPONENTVALUEWINDOW_H
#define ELECTRONICCOMPONENTVALUEWINDOW_H

#include "MainWindow_global.h"

#include <memory>

#include <QWidget>

class QAbstractItemModel;

namespace Ui
{
    class ElectronicComponentValueWindow;
}

namespace  MainWindow
{

class MAINWINDOW_EXPORT ElectronicComponentValueWindow
        : public QWidget
{
    Q_OBJECT

public:
    ElectronicComponentValueWindow( QAbstractItemModel* model, QWidget* parent = nullptr);
    ~ElectronicComponentValueWindow();

private:
    Ui::ElectronicComponentValueWindow* m_ui;

    QAbstractItemModel* m_model;

};

}

#endif // ELECTRONICCOMPONENTVALUEWINDOW_H
