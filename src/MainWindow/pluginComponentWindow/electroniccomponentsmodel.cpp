#include "electroniccomponentsmodel.h"

#include <QDebug>
#include <QSqlError>

using namespace MainWindow;

ElectronicComponentsModel::ElectronicComponentsModel(Common::Components::IDataEComponent* data, QObject *parent)
    : QSqlRelationalTableModel(parent, data->activeAppDB())
    , m_data{ data }
{
    qDebug() << "model constructor " << lastError();

    m_data->activeAppDB();

    setTable("resistor");

    qDebug() << "model constructor after setTable " << lastError();
}

ElectronicComponentsModel::~ElectronicComponentsModel()
{}
