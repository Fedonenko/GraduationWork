#pragma once

#include "GeneralAPI_global.h"

#include <QPointer>

namespace Common
{
class PropertiesObject;
}

class GENERALAPI_EXPORT ControlConnector
{
public:
    ControlConnector(const QByteArray& propetyName);
    ~ControlConnector();

public:
    virtual QVariant value() const;
    virtual void setValue(const QVariant& val);
    void bind(Common::PropertiesObject* page, QObject* control);
    virtual void connect(Common::PropertiesObject* page);
    virtual void connectToControl(Common::PropertiesObject* page);
    virtual void connectFromControl(Common::PropertiesObject* page);

protected:
    QByteArray m_propertyName;
    QPointer<QObject> m_control;
    Common::PropertiesObject* m_page;
};

