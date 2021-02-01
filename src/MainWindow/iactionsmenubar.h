#ifndef IACTIONSMENUBAR_H
#define IACTIONSMENUBAR_H

class QAction;

namespace MainWindow{

class IActionsMenuBar
{

public:
    IActionsMenuBar() = default;
    virtual ~IActionsMenuBar() = default;

    virtual QAction* resistor() const = 0;

    virtual QAction* arrayCreator() const = 0;

};

}

#endif // IACTIONSMENUBAR_H
