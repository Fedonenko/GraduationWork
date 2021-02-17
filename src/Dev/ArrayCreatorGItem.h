#pragma once

#include <QGraphicsItem>

class ArrayCreatorGItem
    : public QGraphicsItem
{
public:
    ArrayCreatorGItem(QGraphicsItem *parent = nullptr);
    virtual ~ArrayCreatorGItem();

    virtual void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = nullptr) override;
    virtual QRectF boundingRect() const override;

    virtual void mousePressEvent(QGraphicsSceneMouseEvent* e) override;
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent* e) override;
};
