#include "electroniccomponentvaluewindow.h"

#include "ui_electronicComponentValueWindow.h"

#include <QDebug>

using namespace MainWindow;

ElectronicComponentValueWindow::ElectronicComponentValueWindow(QAbstractItemModel* model, QWidget* parent)
    : Widget(parent)
    , m_ui{ std::make_unique<Ui::ElectronicComponentValueWindow>() }
    , m_model{ model }
{
    m_ui->setupUi(this);

    m_ui->tableView->setModel(model);

    setCursor(Qt::WaitCursor);
//    unsetCursor();

    qDebug() << "model->data(model->index(0,0)).toString(): " << model->data(model->index(0,0)).toString();
    qDebug() << "model->data(model->index(0,1)).toString(): " << model->data(model->index(0,1)).toString();
    qDebug() << "model->data(model->index(0,2)).toString(): " << model->data(model->index(0,2)).toString();
}

ElectronicComponentValueWindow::~ElectronicComponentValueWindow()
{}
