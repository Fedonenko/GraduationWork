#include "userdataecomponent.h"

namespace settings
{

const auto& versione()
{
    const static int value{ 1 };

    return value;
}

const auto& dbUser()
{
    const static QString name{ QString("userDataBase_%1.sqlite").arg(versione()) };

    return name;
}

}

using namespace Common::Components;

UserDataEComponent::UserDataEComponent()
{
    init();
}

UserDataEComponent::~UserDataEComponent()
{}

QString UserDataEComponent::nameDB() const
{
    return settings::dbUser();
}
