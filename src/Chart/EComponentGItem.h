#pragma once

#include <QGraphicsItem>
#include <QPainter>

namespace Chart
{

class Diod
{
public:
    QVector<QLine> path(int scale = 1) const;
};

class Capacitor
{
public:
	QVector<QLine> path(int scale = 1) const;
};

class Resistor
{
public:
    Resistor()
    {}

	QVector<QLine> path(int scale = 1) const;
};

class Battery
{
public:
	QVector<QLine> path(int scale = 1) const;
};

template<typename T>
class EComponentGItem
    : public QGraphicsItem
{
public:
    EComponentGItem(T componentInfo)
        : m_data{ componentInfo }
    {

    }
    virtual ~EComponentGItem()
    {
    }

    virtual QRectF boundingRect() const override
    {
		QRect figureSize{ 0, 0, 10, 30 };
		return figureSize;
    }

    virtual void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = 0) override
    {
		painter->save();

		painter->drawLines(m_data.path());

		painter->restore();
    }

private:
    void setFigureLine(const QVector<QLine>& value)
    {
// 		if (value == m_data.path())
// 		{
// 			return;
// 		}
// 		m_figureLine = value;
    }

private:
    T m_data;

};

}
