#include "debugwindow.h"

#include "ui_debugwidget.h"

DebugWindow::DebugWindow(QWidget* parent)
    : QWidget(parent, Qt::Drawer )
    , m_ui{ std::make_unique<Ui::DebugWidget>()}
{
    this->setWindowModality(Qt::WindowModal);//ApplicationModal);
    m_ui->setupUi(this);
}

DebugWindow::~DebugWindow()
{}

void DebugWindow::currentStyleSheet(const QString& value)
{
    m_ui->currentText->setText(value);
}

QString DebugWindow::textStyleSheet() const
{
    return m_ui->textEdit->toPlainText();
}
