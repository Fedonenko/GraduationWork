#pragma once

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
    virtual QAction* resistor() const override;

    virtual QAction* arrayCreator() const override;

private:
    void init();

private:
    std::unique_ptr<QAction> m_resistor;
    std::unique_ptr<QAction> m_arrayCreator;

};

}
