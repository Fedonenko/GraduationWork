#ifndef CHART_H
#define CHART_H

#include <QWidget>
#include <gui/widget.h>

#include "Chart_global.h"

namespace Chart{

class CHART_EXPORT ChartWidget
        : public Widget
{
    Q_OBJECT

public:
    ChartWidget();

};

}

#endif // CHART_H
