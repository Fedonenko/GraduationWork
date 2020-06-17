#ifndef ABSTRACTDATAECOMPONENT_H
#define ABSTRACTDATAECOMPONENT_H

#include <QString>
#include <QSqlDatabase>
namespace Common::Components
{

class AbstractDataEComponent
{
public:
    AbstractDataEComponent();
    virtual ~AbstractDataEComponent();

    virtual QString nameDB() const;
    virtual QString pathDb() const;
    virtual void init();
    QSqlDatabase& activeConnect();

protected:
    void initDB();
    void checkTables();

private:
    void createDefaultComponentTables();

private:
    QSqlDatabase m_dataBase;

};

}
#endif // ABSTRACTDATAECOMPONENT_H
