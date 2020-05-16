#include "dataecomponent.h"

#include "userdataecomponent.h"
#include "applicationdataecomponent.h"

using namespace Common::Components;

DataEComponent::DataEComponent()
    : m_userData{ nullptr }
    , m_applicationData{ nullptr }
{
    init();
}

DataEComponent::~DataEComponent()
{}

void DataEComponent::init()
{
    m_userData = std::make_unique<UserDataEComponent>();
    m_applicationData = std::make_unique<ApplicationDataEComponent>();
}
