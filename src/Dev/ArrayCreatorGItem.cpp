#include "ArrayCreatorGItem.h"

#include <QPainter>
#include <QApplication>
#include <QtWidgets>

namespace
{
const int c_penWidth{ 3 };
}

ArrayCreatorGItem::ArrayCreatorGItem(QGraphicsItem* parent)
    : QGraphicsItem(parent)
{
    setAcceptDrops(true);
    setFlags(QGraphicsItem::ItemIsMovable);
}

ArrayCreatorGItem::~ArrayCreatorGItem()
{}

void ArrayCreatorGItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    painter->save();

    painter->setPen(QPen{ Qt::blue, 0});
    painter->setBrush(Qt::yellow);

    QPainterPath path;

	QPainterPath path1;

//     QPainterPath path2;
     path.addRect(50, 0, 100, 50);
// 
//     QPainterPath path3;
//     path.addRect(0, 50, 50, 100);
     path.closeSubpath();
	path.addRect(0, 0, 50, 50);
	path.closeSubpath();

//	path.addRect(0, 0, 50, 50);



//     path.addRect(10, 1, 100, 100);

    painter->drawPath(path);
//    painter->drawRoundedRect(-10, -10, 20, 20, 5, 5);

//     painter->drawRect(0, 0, 50, 50);
// 	painter->restore();
// 
// 	painter->save();
// 
// 	painter->setPen(QPen{ Qt::blue, 0 });
// 	painter->setBrush(Qt::yellow);
// 
//     painter->drawRect(50, 0, 100, 50);
// 	painter->restore();
// 
// 	painter->save();
// 
// 	painter->setPen(QPen{ Qt::blue, 0 });
// 	painter->setBrush(Qt::yellow);
// 
//     painter->drawRect(0, 50, 50, 100);
// 	painter->restore();
// 
//     painter->drawRect(50, 50, 100, 100);
//     painter->drawRect(0, 0, 100, 100);

    painter->restore();
}

QRectF ArrayCreatorGItem::boundingRect() const
{
    return QRectF{0, 0, 105, 105};
}

void ArrayCreatorGItem::mousePressEvent(QGraphicsSceneMouseEvent *e)
{
    QApplication::setOverrideCursor(Qt::PointingHandCursor);

    QGraphicsItem::mousePressEvent(e);
}

void ArrayCreatorGItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *e)
{
    QApplication::restoreOverrideCursor();

    QGraphicsItem::mouseReleaseEvent(e);
}
