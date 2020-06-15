#include "abstractdataecomponent.h"

#include <QtSql>

namespace settings
{

const auto& pathDb()
{
    const static QString path{ QDir::homePath() + "/.ecBuildingSystem/db/" };

    QDir dir(path);
    if(dir.exists())
    {
       return path;
    }

    if(dir.mkpath(path))
    {
        return path;
    }

    qDebug() << "Error!" << "Database file path cannot be created or opened";
    assert(0);

    return  path;
}

//const QStringList& listTables()
//{
//    const static auto list = QStringList() << "componets" << ;
//}

const QString& components()
{
    const static QString value{ "components" };

    return value;
}

const QString& componentGroups()
{
    const static QString groups{ "component_groups" };

    return groups;
}

}

using namespace Common::Components;

AbstractDataEComponent::AbstractDataEComponent()
    //: m_dataBase(QSqlDatabase::addDatabase("QSQLITE"))
{
//    initDB();
//    readingTables();
}

AbstractDataEComponent::~AbstractDataEComponent()
{}

QString AbstractDataEComponent::nameDB() const
{
    return QString();
}

QString AbstractDataEComponent::pathDb() const
{
    return settings::pathDb();
}

void AbstractDataEComponent::init()
{
    initDB();
    checkTables();
}

void AbstractDataEComponent::initDB()
{
    QString path = pathDb();
    QString name = nameDB();

    m_dataBase = QSqlDatabase::addDatabase("QSQLITE", nameDB());

    m_dataBase.setDatabaseName(pathDb() + nameDB());

    if(!m_dataBase.open())
    {
        qDebug() << QString("db %1 is NOT open").arg(nameDB());
        assert(0);
    }

}

void AbstractDataEComponent::checkTables()
{
    const auto tableList = QStringList() << settings::components() << settings::componentGroups();

    m_dataBase.setDatabaseName(pathDb() + nameDB());
    QStringList dbTableList = m_dataBase.tables();
    QSqlQuery query(m_dataBase);

    for(const auto& item : tableList)
    {
        if(!dbTableList.contains(item))
        {
            auto fields{ QString() };

            if(item == settings::componentGroups())
            {
                fields = { QString("%1, %2, %3, %4")
                            .arg("id INTEGER PRIMARY KEY AUTOINCREMENT")
                            .arg("name_group TEXT")
                            .arg("path_image_path TEXT")
                            .arg(QString("id_groups INTEGER NOT NULL REFERENCES ") + settings::components() + "(id)")
                             };
            }
            else if (item == settings::components())
            {
                fields = { QString("%1, %2, %3, %4")
                           .arg("id INTEGER PRIMARY KEY AUTOINCREMENT")
                           .arg("name TEXT")
                           .arg("path_to_image_component TEXT")
                           .arg("id_property INTEGER NOT NULL")
                };
            }

            auto queryString{ QString("CREATE TABLE %1 (%2);").arg(item).arg(fields) };

            query.exec(queryString);
        }
    }
}

void AbstractDataEComponent::createDefaultComponentTables()
{
    QSqlQuery sqlQuery(m_dataBase);
    QString componentName;

    const auto resistor = QString("resistor");
    const auto capacitor = QString("capacitor");
    const auto diod = QString("diod");

    const QStringList componentList{ QStringList() << resistor << capacitor << diod };

    for(const auto& name : componentList)
    {
        //sqlQuery.exec(QString("SELECT FROM %"));
    }

    QString fields;
//resistor
    {
        fields = QString("%1, %2, %3")
                .arg("id INTEGER PRIMARY KEY AUTOINCREMENT")
                .arg("resistance INTEGER")
                .arg("voltage REAL")
                .arg(QString("id_component INTEGER NOT NULL REFERENCES ") + settings::components() + "(id)");

        QString create = QString ("CREATE TABLE %1 (%2);")
                .arg(resistor)
                .arg(fields);

        if(!sqlQuery.exec(create))
        {
            qDebug() << "Unable to create a table " << resistor;
        }

        QString insertF = "INSERT INTO resistor (resistance, voltage, id_component)"
                         "%1, %2, %3);";
        QString insert = insertF
                .arg("10")
                .arg("220")
                .arg("0");
        if(!sqlQuery.exec(insert))
        {
            qDebug() << "Unable to make insert operation " << resistor;
        }
    }
}

