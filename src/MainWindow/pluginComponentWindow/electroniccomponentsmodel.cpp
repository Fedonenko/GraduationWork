#include "electroniccomponentsmodel.h"

#include <QSqlRecord>

#include <QDebug>
#include <QSqlError>

using namespace MainWindow;

ElectronicComponentsModel::ElectronicComponentsModel(Common::Components::IDataEComponent* data, QObject *parent)
    : QSqlRelationalTableModel(parent, data->activeAppDB())
    , m_data{ data }
{
    qDebug() << "ElectronicComponentsModel constructor " << lastError();

    m_data->activeAppDB();

//    setTable("resistor");
//    select();

//    qDebug() << "ElectronicComponentsModel constructor after setTable \"resistor\""
//             << " Error Type: " << lastError().type()

//             << " is NoError: " << lastError().NoError
//             << " lastError().text(): " << lastError().text();

//    qDebug() << "record(0).value(0).toString(): " << record(0).value(0).toString();
//    qDebug() << "record(0).value(1).toString(): " << record(0).value(1).toString();
//    qDebug() << "record(0).value(2).toString(): " << record(0).value(2).toString();

    qDebug();

//    qDebug() << "record(1).value(0).toString(): " << record(1).value(0).toString();
//    qDebug() << "record(1).value(1).toString(): " << record(1).value(1).toString();
//    qDebug() << "record(1).value(2).toString(): " << record(1).value(2).toString();


//    qDebug() << "data in table "
//             << query.value(0).toString()
//             << query.value(rec.indexOf("resistance")).toString()
//             << query.value(rec.indexOf("voltage")).toString();

    //setTable("resistor");

}

ElectronicComponentsModel::~ElectronicComponentsModel()
{}
