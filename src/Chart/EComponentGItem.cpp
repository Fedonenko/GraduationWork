#include "EComponentGItem.h"

#include <QPainter>

namespace
{
QRect figureSize{ 0, 0, 10, 30 };

const QVector<QLine> c_resistorOfLines{ {0, 10, 20, 10}
, { 60 , 10, 80, 10 }
, { 20, 0, 20, 20 }
, { 60, 0, 60, 20 }
, { 20, 0, 60, 0 }
, { 20, 20, 60, 20 }
};

}

using namespace Chart;

QVector<QLine> Resistor::path(int scale) const
{
    return 
    { 
        {0 * scale, 10 * scale, 20 * scale, 10 * scale}
        , { 60 * scale , 10 * scale, 80 * scale, 10 * scale }
        , { 20 * scale, 0 * scale, 20 * scale, 20 * scale}
        , { 60 * scale, 0 * scale, 60 * scale, 20 * scale}
        , { 20 * scale, 0 * scale, 60 * scale, 0 * scale}
        , { 20 * scale, 20 * scale, 60 * scale, 20 * scale}
    };
}

QVector<QLine> Capacitor::path(int scale) const
{
    return
    {
        { 0 * scale, 10 * scale, 20 * scale, 10 * scale}
        , { 30 * scale, 10 * scale, 50 * scale, 10 * scale}
        , { 20 * scale, 0 * scale, 20 * scale, 20 * scale}
        , { 30 * scale, 0 * scale, 30 * scale, 20 * scale}
    };
}

QVector<QLine> Diod::path(int scale) const
{
    return
    {
        { 0 * scale, 10 * scale, 20 * scale, 10 * scale }
        , { 40 * scale, 10 * scale, 60 * scale, 10 * scale }
        , { 20 * scale, 0 * scale, 20 * scale, 20 * scale }
        , { 20 * scale, 0 * scale, 40 * scale, 10 * scale }
        , { 20 * scale, 20 * scale, 40 * scale, 10 * scale }
    };
}

QVector<QLine> Battery::path(int scale) const
{
    return
    {
        { 0 * scale, 20 * scale, 20 * scale, 20 * scale }
        , { 30 * scale, 20 * scale, 50 * scale, 20 * scale }
        , { 20 * scale, 5 * scale, 20 * scale, 35 * scale }
        , { 30 * scale, 15 * scale, 30 * scale, 25 * scale }
    };
}
