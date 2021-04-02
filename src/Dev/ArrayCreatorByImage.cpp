#include "ArrayCreatorByImage.h"

#include "ui_ArrayCreatorByImage.h"
#include "GraphicsScene.h"
#include "BackgroundFieldGItem.h"
#include "GraphicsScene.h"
#include "ArrayCreatorGItem.h"

using namespace Dev;

ArrayCreatorByImage::ArrayCreatorByImage(QWidget* parent)
    : QWidget(parent, Qt::Window)
    , m_ui{ std::make_unique<Ui::ArrayCreatorByImage>() }
{
    m_ui->setupUi(this);
    PropertiesObject::setObject(this);
    init();

    auto gScene = new GraphicsScene;

//    gScene->addItem(gItem);

 //   gItem->setPos(0, 0);

    //m_ui->graphicsView->setScene(gScene);

    auto scene = m_ui->graphicsView->scene();

    if(scene)
    {
        qDebug() << "ok";
    }

    setFormattedArray("Hello ");

	auto gItem = new ArrayCreatorGItem;


    gScene->addItem(gItem);
	m_ui->graphicsView->setScene(gScene);

// 	auto gItem2 = new ArrayCreatorGItem;
//     gScene->addItem(gItem2);
    

    m_ui->graphicsView->update();
    m_ui->graphicsView->scene()->update();
	setFormattedArray("Hello World!");
	setFieldHeight("8");
	setFieldWidth("8");


	gItem->setPos(100, 300);

	auto gItem2 = new ArrayCreatorGItem;
	gScene->addItem(gItem2);
    gItem2->setPos(300, 0);

}

ArrayCreatorByImage::~ArrayCreatorByImage()
{
}

QString ArrayCreatorByImage::formattedArray() const
{
    return m_formatedArray;
}

void ArrayCreatorByImage::setFormattedArray(const QString& value)
{
    if(m_formatedArray == value)
    {
        return;
    }

    m_formatedArray = value;

    emit formattedArrayChanged(value);
}

QString ArrayCreatorByImage::fieldHeight() const
{
    return m_fieldHeight;
}

void ArrayCreatorByImage::setFieldHeight(const QString& value)
{
    bool isNumber;
    int number = value.toInt(&isNumber);

    Q_ASSERT(isNumber);
    Q_ASSERT(number > 0);

    if(m_fieldHeight == value)
    {
        return;
    }
    m_fieldHeight = value;

    emit fieldHeightChanged(value);
}

QString ArrayCreatorByImage::fieldWidth() const
{
    return m_fieldWidth;
}

void ArrayCreatorByImage::setFieldWidth(const QString& value)
{
	bool isNumber;
	int number = value.toInt(&isNumber);

	Q_ASSERT(isNumber);
	Q_ASSERT(number > 0);

    if(m_fieldWidth == value)
    {
        return;
    }
    m_fieldWidth = value;

    emit fieldWidthChanged(value);
}
