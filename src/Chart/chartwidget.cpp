#include "chartwidget.h"

#include "ui_ChartWidget.h"

namespace
{
const QString c_titleName{ QObject::tr("Chart") };
}

using namespace Chart;

ChartWidget::ChartWidget()
    : m_ui{ std::make_unique<Ui::ChartWidget>() }
{
    m_ui->setupUi(this);

    setWindowTitle(c_titleName);
}

ChartWidget::~ChartWidget()
{}
