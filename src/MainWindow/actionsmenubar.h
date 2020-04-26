#ifndef ACTIONSMENUBAR_H
#define ACTIONSMENUBAR_H

#include <memory>

#include "iactionsmenubar.h"

namespace MainWindow {

class ActionsMenuBar
        : public IActionsMenuBar
{
public:
    ActionsMenuBar();
    ~ActionsMenuBar();

public:
    virtual QAction* resistor() override;

private:
    std::unique_ptr<QAction> m_resistor;
    //QAction* m_resistor;

};

}

#endif // ACTIONSMENUBAR_H
