#pragma once

#include <QGraphicsScene>

namespace Chart
{

class ChartGraphicsScene
    : public QGraphicsScene
{
    Q_OBJECT

public:
    ChartGraphicsScene();
    virtual ~ChartGraphicsScene();
};

}
