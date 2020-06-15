#ifndef GENERALAPI_H
#define GENERALAPI_H

#include "GeneralAPI_global.h"

#include <memory>

namespace Common::Components
{
class IDataEComponent;
}

class GENERALAPI_EXPORT GeneralAPI
{
public:
    GeneralAPI();
    ~GeneralAPI();

public:
    Common::Components::IDataEComponent* dataComponents();

private:
    void init();

private:
    std::unique_ptr<Common::Components::IDataEComponent> m_dataEComponents;
};

#endif // GENERALAPI_H
