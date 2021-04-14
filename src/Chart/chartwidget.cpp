#include "chartwidget.h"

#include "ui_ChartWidget.h"
#include "ChartGraphicsScene.h"
#include "EComponentGItem.h"

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

    auto scene = new ChartGraphicsScene;
    auto gItem = new EComponentGItem;

    scene->addItem(gItem);

    m_ui->chartView->setScene(scene);
}

ChartWidget::~ChartWidget()
{}
