#include "electroniccomponentsmodel.h"

//#include <dataecomponent.h>

using namespace MainWindow;

ElectronicComponentsModel::ElectronicComponentsModel(Common::Components::IDataEComponent* data, QObject *parent)
    : QSqlRelationalTableModel(parent)
    , m_data{ data }
{

}

ElectronicComponentsModel::~ElectronicComponentsModel()
{}
