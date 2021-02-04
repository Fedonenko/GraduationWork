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
    Q_PROPERTY(QString fieldHeight READ fieldHeight WRITE setFieldHeight NOTIFY fieldHeightChanged)
    Q_PROPERTY(QString fieldWidth READ fieldWidth WRITE setFieldWidth NOTIFY fieldWidthChanged)

public:
    ArrayCreatorByImage(QWidget* parent = nullptr);
    virtual ~ArrayCreatorByImage();

    QString formattedArray() const;
    Q_SLOT void setFormattedArray(const QString&);
    Q_SIGNAL void formattedArrayChanged(const QString& value);

    QString fieldHeight() const;
    Q_SLOT void setFieldHeight(const QString&);
    Q_SIGNAL void fieldHeightChanged(const QString& value);

    QString fieldWidth() const;
    Q_SLOT void setFieldWidth(const QString&);
    Q_SIGNAL void fieldWidthChanged(const QString& value);

private:
    std::unique_ptr<Ui::ArrayCreatorByImage> m_ui;

    QString m_formatedArray;
    QString m_fieldHeight;
    QString m_fieldWidth;
};

}
