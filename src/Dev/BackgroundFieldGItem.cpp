#include "BackgroundFieldGItem.h"

BackgroundFieldGItem::BackgroundFieldGItem(QGraphicsItem* parent)
    : QGraphicsItem(parent)
{

}

BackgroundFieldGItem::~BackgroundFieldGItem()
{
}

void BackgroundFieldGItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

}

QRectF BackgroundFieldGItem::boundingRect() const
{
    return QRectF{};
}
