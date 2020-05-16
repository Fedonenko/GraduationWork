#ifndef APPLICATIONDATAECOMPONENT_H
#define APPLICATIONDATAECOMPONENT_H

#include "abstractdataecomponent.h"

namespace Common::Components
{

class ApplicationDataEComponent final
        : public AbstractDataEComponent
{
public:
    ApplicationDataEComponent();
    ~ApplicationDataEComponent() override;

private:
    virtual QString nameDB() const override;

};

}

#endif // APPLICATIONDATAECOMPONENT_H
