#pragma once

#include "Dev_global.h"

#include <memory>
#include <QtWidgets>
#include <Properties/PropertiesObject.h>

namespace Ui
{
class ArrayCreatorByImage;
}

namespace Dev
{

class DEV_EXPORT ArrayCreatorByImage
        : public QWidget
        , public Common::PropertiesObject
{
    Q_OBJECT

public:
    ArrayCreatorByImage(QWidget* parent = nullptr);
    virtual ~ArrayCreatorByImage();

private:
    std::unique_ptr<Ui::ArrayCreatorByImage> m_ui;
//    Ui::ArrayCreatorByImage* m_ui;
};

}
