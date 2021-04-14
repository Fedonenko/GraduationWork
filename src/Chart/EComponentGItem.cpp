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

EComponentGItem::EComponentGItem()
    : QGraphicsItem()
{

}

EComponentGItem::~EComponentGItem()
{}

QRectF Chart::EComponentGItem::boundingRect() const
{
    return figureSize;
}

void Chart::EComponentGItem::paint(QPainter* painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
    painter->save();

    painter->drawLines(c_resistorOfLines);

    painter->restore();
}
