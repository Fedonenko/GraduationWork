#ifndef DEV_H
#define DEV_H

#include "Dev_global.h"

#include <memory>
#include <QtWidgets>

namespace Ui
{
class ArrayCreatorByImage;
}

namespace Dev
{

class DEV_EXPORT ArrayCreatorByImage
        : public QWidget
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
#endif // DEV_H
