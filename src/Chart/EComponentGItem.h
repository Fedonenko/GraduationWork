#pragma once

#include <QGraphicsItem>

namespace Chart
{

class EComponentGItem
    : public QGraphicsItem
{
//    Q_OBJECT

public:
    EComponentGItem();
    virtual ~EComponentGItem();

    virtual QRectF boundingRect() const override;
    virtual void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = 0) override;

};

}
