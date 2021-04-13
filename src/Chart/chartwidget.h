#pragma once

#include <QWidget>
#include <gui/widget.h>
#include <memory>

#include "Chart_global.h"

namespace Ui
{
class ChartWidget;
}

namespace Chart
{

class CHART_EXPORT ChartWidget
        : public Widget
{
    Q_OBJECT

public:
    ChartWidget();
    virtual ~ChartWidget();

private:
    std::unique_ptr<Ui::ChartWidget> m_ui;

};

}
