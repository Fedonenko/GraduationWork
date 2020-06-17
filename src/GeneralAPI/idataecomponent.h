#ifndef IDATACOMPONENT_H
#define IDATACOMPONENT_H

#include <QSqlDatabase>

namespace Common
{

namespace Components
{

class IDataEComponent
{
public:
    virtual ~IDataEComponent() = default;

    virtual QSqlDatabase& activeUserDB() = 0;
    virtual QSqlDatabase& activeAppDB() = 0;
};

}
}

#endif // IDATACOMPONENT_H
