#include "ArrayCreatorByImage.h"

#include "ui_ArrayCreatorByImage.h"

using namespace Dev;

ArrayCreatorByImage::ArrayCreatorByImage(QWidget* parent)
    : QWidget(parent, Qt::Window)
    , m_ui{ std::make_unique<Ui::ArrayCreatorByImage>() }
{
    m_ui->setupUi(this);
    PropertiesObject::setObject(this);
    init();

    setFormattedArray("Hello World!");
    setFieldHeight("8");
    setFieldWidth("8");
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
    if(m_fieldWidth == value)
    {
        return;
    }
    m_fieldWidth = value;

    emit fieldWidthChanged(value);
}
