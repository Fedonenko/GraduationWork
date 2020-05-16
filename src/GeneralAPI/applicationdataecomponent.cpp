#include "applicationdataecomponent.h"

namespace
{

const auto& dbApplication()
{
    const static QString name{"applicationDataBase.sqlite"};

    return name;
}

}

using namespace Common::Components;

ApplicationDataEComponent::ApplicationDataEComponent()
{
    init();
}

ApplicationDataEComponent::~ApplicationDataEComponent()
{

}

QString ApplicationDataEComponent::nameDB() const
{
    return dbApplication();
}
