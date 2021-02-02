#pragma once

#include <QPointer>

namespace Common
{
class PropertiesObject;

class ControlConnector
{
public:
    ControlConnector(const QByteArray& propetyName);
    ~ControlConnector();

public:
    virtual QVariant value() const;
    virtual void setValue(const QVariant& val);
    void bind(PropertiesObject* page, QObject* control);
    virtual void connect(PropertiesObject* page);
    virtual void connectToControl(PropertiesObject* page);
    virtual void connectFromControl(PropertiesObject* page);

protected:
    QByteArray m_propertyName;
    QPointer<QObject> m_control;
    PropertiesObject* m_page;
};

}
