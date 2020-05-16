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

void GeneralAPI::init()
{
    m_dataEComponents = std::make_unique<Common::Components::DataEComponent>();
}
