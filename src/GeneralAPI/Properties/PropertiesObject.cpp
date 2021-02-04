#include "PropertiesObject.h"

#include "ControlConnector.h"

#include <QMetaType>
#include <QMetaProperty>
#include <QObject>

using namespace Common;

class ControlConnector_QCheckBox : public ControlConnector
{
public:
    ControlConnector_QCheckBox() : ControlConnector("checked") {}
};
Q_DECLARE_METATYPE(ControlConnector_QCheckBox);

class ControlConnector_QLineEdit : public ControlConnector
{
public:
    ControlConnector_QLineEdit() : ControlConnector("text"){}

    virtual void connect(PropertiesObject* page)
    {
        Q_ASSERT(QObject::connect(m_control, SIGNAL(editingFinished()), page->objectHelper(), SLOT(setDataFromControl())));
        connectToControl(page);
    }
};
Q_DECLARE_METATYPE(ControlConnector_QLineEdit);

class ControlConnector_QTextEdit : public ControlConnector
{
public:
    ControlConnector_QTextEdit() : ControlConnector("plainText") {}
    virtual void connect(PropertiesObject* page)
    {
        Q_ASSERT(QObject::connect(m_control, SIGNAL(textChanged()), page->objectHelper(), SLOT(setDataFromControl())));
        connectToControl(page);
    }
};
Q_DECLARE_METATYPE(ControlConnector_QTextEdit);

class ControlConnector_QRadioButton : public ControlConnector
{
public:
    ControlConnector_QRadioButton() : ControlConnector("checked"){}
};
Q_DECLARE_METATYPE(ControlConnector_QRadioButton);

bool registerStandardConnectors()
{
    qRegisterMetaType<ControlConnector_QLineEdit>();
    qRegisterMetaType<ControlConnector_QCheckBox>();
    qRegisterMetaType<ControlConnector_QRadioButton>();
    qRegisterMetaType<ControlConnector_QTextEdit>();

    return true;
}

////////////////////////////////////////////////////////////
/// \brief PropertiesHelper::PropertiesHelper
/// \param pObject
///

PropertiesHelper::PropertiesHelper(PropertiesObject* pObject)
    : m_propertiesObject{ pObject }
{

}

PropertiesHelper::~PropertiesHelper()
{}

void PropertiesHelper::setDataFromControl()
{
    m_propertiesObject->setDataFromControl(sender());
}

void PropertiesHelper::setDataToControl()
{
    const static QByteArray s_changed{ "Changed" };

    m_propertiesObject->setDataToControl(senderSignalIndex());
}


///////////////////////////////////////////////////////////////
/// \brief PropertiesObject::PropertiesObject
/// \param obj
///
/// ///////////////////////////////////////////////////////////
///
///


PropertiesObject::PropertiesObject(QObject* obj)
    : m_object{ obj }
    , m_pHelper{ std::make_unique<PropertiesHelper>(this) }//nullptr }
{

}

PropertiesObject::~PropertiesObject()
{}

QObject* PropertiesObject::object()
{
    return m_object;
}

void PropertiesObject::setObject(QObject* object)
{
    m_object = object;
}

QObject* PropertiesObject::objectHelper()
{
    return m_pHelper.get();
}

void PropertiesObject::init()
{
    m_fieldsBeingSet.clear();

    for(QObject * control : object()->findChildren<QObject*>())
    {
        const QString dataKeyString = control->property("dataKey").toString();

        const QByteArray dataKey = dataKeyString.toUtf8();

        if (dataKey.isEmpty())
        {
            continue;
        }

        ControlConnector* binding = createControlConnectorByType(control);

        if (!binding)
        {
            Q_ASSERT(!"Unregistered control type");
            continue;
        }

        binding->bind(this, control);
        m_bindings[dataKey] = binding;
    }

    objectAttach();
}

void PropertiesObject::setPropertyValue(const QByteArray& name, QVariant value)
{
    const auto isSet = object()->setProperty(name, value);

    Q_ASSERT(isSet);
}

void PropertiesObject::addMetaDefaultProperty(const QByteArray& propertyName, const QVariant& value)
{
    Q_ASSERT(m_bindings.contains(propertyName));

    if (!m_bindings.contains(propertyName))
    {
        return;
    }

    object()->setProperty(propertyName.constData(), value);
}

void PropertiesObject::setDataFromControl(QObject* object)
{
    const QByteArray dataKey = /*sender()*/object->property("dataKey").toString().toLatin1();

    Q_ASSERT(!dataKey.isEmpty());

    if (m_fieldsBeingSet.contains(dataKey) || !m_bindings.contains(dataKey))
    {
        return;
    }

    ControlConnector* binding = m_bindings[dataKey];

    m_fieldsBeingSet.insert(dataKey);

    setPropertyValue(dataKey, binding->value());
    m_fieldsBeingSet.remove(dataKey);
}

void PropertiesObject::setDataToControl(const QByteArray& key)
{
    if (key.isEmpty())
    {
        return;
    }

    for(QByteArray dataKey : m_bindings.keys())
    {
        if (!dataKey.startsWith(key))
        {
            continue;
        }

        if (m_fieldsBeingSet.contains(dataKey))
        {
            continue;
        }

        ControlConnector* binding = m_bindings[dataKey];

        m_fieldsBeingSet.insert(dataKey);

        binding->setValue(propertyValue(dataKey));

        m_fieldsBeingSet.remove(dataKey);
    }
}

void PropertiesObject::setDataToControl(const int signalIndex)
{
    const static QByteArray s_changed{ "Changed" };

    Q_ASSERT_X(-1 != signalIndex,"PropertiesObject::setDataToControl()", "invalid signal index");

    QByteArray signalName = object()->metaObject()->method(signalIndex).name();
    QByteArray propertyName = signalName.left(signalName.lastIndexOf(s_changed));

    setDataToControl(propertyName);
}

QVariant PropertiesObject::propertyValue(const QByteArray& propertyName)
{
    return object()->property(propertyName);
}

ControlConnector* PropertiesObject::createControlConnectorByType(QObject* control)
{
    static bool inited = registerStandardConnectors();

    Q_ASSERT(inited);

    const QMetaObject* metaObject = control->metaObject();
    const QByteArray controlClassName = metaObject->className();
    const QList<QByteArray> controlClassNameParts = controlClassName.split(':');

    Q_ASSERT(!controlClassNameParts.last().isEmpty());

    QMetaType mType = QMetaType::fromName(QByteArray("ControlConnector_") +
        controlClassNameParts.last());

    if (mType.isValid())
    {
       return static_cast<ControlConnector*>(mType.create());
    }

    Q_ASSERT(mType.isValid());

    return nullptr;
}
