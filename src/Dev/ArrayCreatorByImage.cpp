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
