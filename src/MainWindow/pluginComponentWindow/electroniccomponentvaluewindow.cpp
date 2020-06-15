#include "electroniccomponentvaluewindow.h"

#include "ui_electronicComponentValueWindow.h"

using namespace MainWindow;

ElectronicComponentValueWindow::ElectronicComponentValueWindow(QAbstractItemModel* model, QWidget* parent)
    : QWidget(parent)
    , m_ui{ new Ui::ElectronicComponentValueWindow }
    , m_model{ model }
{
    m_ui->setupUi(this);

    m_ui->tableView->setModel(model);
}

ElectronicComponentValueWindow::~ElectronicComponentValueWindow()
{}
