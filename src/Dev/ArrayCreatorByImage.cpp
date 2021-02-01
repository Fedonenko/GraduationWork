#include "ArrayCreatorByImage.h"

#include "ui_ArrayCreatorByImage.h"

using namespace Dev;

ArrayCreatorByImage::ArrayCreatorByImage(QWidget* parent)
    : QWidget(parent, Qt::Window)
    , m_ui{ std::make_unique<Ui::ArrayCreatorByImage>() }
{
    m_ui->setupUi(this);
}

ArrayCreatorByImage::~ArrayCreatorByImage()
{
}
