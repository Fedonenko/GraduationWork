#include "generalapi.h"

#include "dataecomponent.h"

GeneralAPI::GeneralAPI() :
    m_dataEComponents{ nullptr }
{
    init();
}

GeneralAPI::~GeneralAPI()
{

}

Common::Components::IDataEComponent *GeneralAPI::dataComponents()
{
    if(!m_dataEComponents)
    {
        m_dataEComponents = std::make_unique<Common::Components::DataEComponent>();
    }

    return m_dataEComponents.get();
}

void GeneralAPI::init()
{
}
