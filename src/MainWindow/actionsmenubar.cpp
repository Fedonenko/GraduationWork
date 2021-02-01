#include <QAction>

#include "actionsmenubar.h"

using namespace MainWindow;

QString pathResistorIMG()
{
    static const QString path(":/image/resistor.svg");
    return path;
}

ActionsMenuBar::ActionsMenuBar()
    : IActionsMenuBar()
    , m_resistor{ std::make_unique<QAction>(QObject::tr("Resistor")) }
    , m_arrayCreator{ std::make_unique<QAction>(QObject::tr("Array Creator")) }
{
    init();
}

ActionsMenuBar::~ActionsMenuBar()
{}

QAction* ActionsMenuBar::resistor() const
{
    Q_ASSERT(m_resistor);

    return m_resistor.get();
}

QAction* ActionsMenuBar::arrayCreator() const
{
    Q_ASSERT(m_arrayCreator);

    return m_arrayCreator.get();
}

void ActionsMenuBar::init()
{
    m_resistor->setIcon(QPixmap(pathResistorIMG()));
    m_resistor->setToolTip(QObject::tr("Resistor"));
}
