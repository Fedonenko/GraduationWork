#pragma once

#include <QGraphicsItem>

class BackgroundFieldGItem
    : public QGraphicsItem
{
public:
    BackgroundFieldGItem(QGraphicsItem *parent = nullptr);
    virtual ~BackgroundFieldGItem();

    virtual void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = nullptr) override;
    virtual QRectF boundingRect() const override;
};
