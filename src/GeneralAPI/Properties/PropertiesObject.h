#pragma once

#include "GeneralAPI_global.h"

#include <QPointer>
#include <QMap>
#include <QVariant>
#include <QSet>

class ControlConnector;

namespace Common
{

//class ControlConnector;
class PropertiesObject;

class PropertiesHelper
        : public QObject
{
    Q_OBJECT

public:
    PropertiesHelper(PropertiesObject* pObject);
    virtual ~PropertiesHelper();

private Q_SLOTS:
    void setDataFromControl();
    void setDataToControl(const QByteArray& dataKey);
    void setDataToControl();

private:
    PropertiesObject* m_propertiesObject;

};

class GENERALAPI_EXPORT PropertiesObject
{
public:
    PropertiesObject(QObject* object = nullptr);
    virtual ~PropertiesObject();

    QObject* object();
    void setObject(QObject* object);
    QObject* objectHelper();

protected:
    void init();

public:
    virtual void setPropertyValue(const QByteArray& name, QVariant value);
    virtual void objectAttach() {};
    virtual void addMetaDefaultProperty(const QByteArray& nameProperty, const QVariant& value = QVariant{});

//private Q_SLOTS:
    void setDataFromControl(QObject* object);
    void setDataToControl(const QByteArray& dataKey);
    void setDataToControl(const int signalIndex);

    QVariant propertyValue(const QByteArray& propertyName);

    ControlConnector* createControlConnectorByType(QObject* control);

private:
    QMap<QByteArray, ControlConnector*> m_bindings;
    QSet<QByteArray> m_fieldsBeingSet;

    QPointer<QObject> m_object;
    std::unique_ptr<PropertiesHelper> m_pHelper;
};

}
