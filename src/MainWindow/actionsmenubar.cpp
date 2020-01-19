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
{
    m_resistor->setIcon(QPixmap(pathResistorIMG()));
    m_resistor->setToolTip(QObject::tr("Resistor"));
}

QAction* ActionsMenuBar::resistor()
{
    return m_resistor.get();
}
