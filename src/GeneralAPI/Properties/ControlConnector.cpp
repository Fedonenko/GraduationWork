#include "ControlConnector.h"

#include "PropertiesObject.h"

#include <QMetaProperty>

using namespace Common;

ControlConnector::ControlConnector(const QByteArray& propetyName)
    : m_propertyName{ propetyName }
{

}

ControlConnector::~ControlConnector()
{}

QVariant ControlConnector::value() const
{
    return m_control->property(m_propertyName.constData());
}

void ControlConnector::setValue(const QVariant& val)
{
    if (!val.isValid())
    {
        return;
    }
    m_control->setProperty(m_propertyName.constData(), val);
}

void ControlConnector::bind(Common::PropertiesObject* page, QObject* control)
{
    m_control = control;
    m_page = page;
    connect(page);
}

void ControlConnector::connect(Common::PropertiesObject* page)
{
    connectFromControl(page);
    connectToControl(page);
}

void ControlConnector::connectToControl(Common::PropertiesObject* page)
{
    const QMetaObject* metaPage = page->object()->metaObject();
    const QByteArray dataKey = m_control->property("dataKey").toString().toUtf8();
    const QMetaProperty metaPropertyPage = metaPage->property(metaPage->indexOfProperty(dataKey.constData()));

    if (!metaPropertyPage.hasNotifySignal())
    {
        return;
    }

    const QMetaMethod metaSignalPage = metaPropertyPage.notifySignal();
    const int indexSlotTo = page->objectHelper()->metaObject()->indexOfSlot(QMetaObject::normalizedSignature("setDataToControl()"));

    Q_ASSERT(-1 != indexSlotTo);

    const QMetaMethod metaSlotTo = page->objectHelper()->metaObject()->method(indexSlotTo);

    Q_ASSERT(QObject::connect(page->object(), metaSignalPage,
        page->objectHelper(), metaSlotTo));
}

void ControlConnector::connectFromControl(Common::PropertiesObject* page)
{
    const QMetaObject* metaControl = m_control->metaObject();
    const int index = metaControl->indexOfProperty(m_propertyName.constData());

    Q_ASSERT(-1 != index);

    QMetaProperty metaPropertyContol = metaControl->property(index);
    Q_ASSERT(metaPropertyContol.hasNotifySignal());
    QMetaMethod metaSignal = metaPropertyContol.notifySignal();

    const QMetaObject* metaPage = page->objectHelper()->metaObject();
    const int indexSlotFrom = metaPage->indexOfSlot(QMetaObject::normalizedSignature("setDataFromControl()"));

    Q_ASSERT(-1 != indexSlotFrom);

    QMetaMethod metaSlotFrom = page->objectHelper()->metaObject()->method(indexSlotFrom);

    Q_ASSERT(QObject::connect(m_control, metaSignal,
        page->objectHelper(), metaSlotFrom));
}
