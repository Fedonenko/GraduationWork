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

    Q_PROPERTY(QString formattedArray READ formattedArray WRITE setFormattedArray NOTIFY formattedArrayChanged)

public:
    ArrayCreatorByImage(QWidget* parent = nullptr);
    virtual ~ArrayCreatorByImage();

    QString formattedArray() const;
    Q_SLOT void setFormattedArray(const QString&);
    Q_SIGNAL void formattedArrayChanged(const QString& value);

private:
    std::unique_ptr<Ui::ArrayCreatorByImage> m_ui;
    QString m_formatedArray;
};

}
