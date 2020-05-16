#ifndef DATAECOMPONENT_H
#define DATAECOMPONENT_H

#include "GeneralAPI_global.h"

#include <memory>

#include "idataecomponent.h"

namespace Common
{

namespace Components
{

class AbstractDataEComponent;

class DataEComponent
        : public IDataEComponent
{
public:
    DataEComponent();
    ~DataEComponent();

private:
    void init();

private:
    std::unique_ptr<AbstractDataEComponent> m_userData;
    std::unique_ptr<AbstractDataEComponent> m_applicationData;
};


inline IDataEComponent* instance()
{
    return nullptr;
}

}
}

#endif // DATAECOMPONENT_H
