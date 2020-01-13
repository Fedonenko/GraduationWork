#include "electroniccomponentvaluewindow.h"
#include "ui_electronicComponentValueWindow.h"
using namespace MainWindow;

ElectronicComponentValueWindow::ElectronicComponentValueWindow(QWidget* parent)
    : QWidget(parent)
    , m_ui{ new Ui::ElectronicComponentValueWindow }
{
    m_ui->setupUi(this);
}
