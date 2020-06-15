#ifndef ELECTRONICCOMPONENTSMODEL_H
#define ELECTRONICCOMPONENTSMODEL_H

#include "MainWindow_global.h"

#include <memory>

#include <QSqlRelationalTableModel>

#include <idataecomponent.h>

namespace Common::Components
{
class IDataEComponent;
}

namespace  MainWindow
{

class MAINWINDOW_EXPORT ElectronicComponentsModel
        : public QSqlRelationalTableModel
{
    Q_OBJECT

public:
    ElectronicComponentsModel( Common::Components::IDataEComponent* data, QObject *parent = nullptr);
    virtual ~ElectronicComponentsModel();

private:
    Common::Components::IDataEComponent* m_data;
};

}
#endif // ELECTRONICCOMPONENTSMODEL_H
