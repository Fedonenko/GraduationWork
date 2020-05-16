#ifndef USERDATAECOMPONENT_H
#define USERDATAECOMPONENT_H

#include "abstractdataecomponent.h"

namespace Common::Components
{

class UserDataEComponent final
        : public AbstractDataEComponent
{
public:
    UserDataEComponent();
    ~UserDataEComponent() override;

private:
    virtual QString nameDB() const override;
};

}

#endif // USERDATAECOMPONENT_H
