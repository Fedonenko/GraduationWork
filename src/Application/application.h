#ifndef APPLICATION_H
#define APPLICATION_H

#include <memory>

#include <QApplication>
#include <QPointer>

#include "Application_global.h"

class MainApplicationWindow;
class GeneralAPI;

namespace Dev
{
class ArrayCreatorByImage;
}

namespace MainWindow
{
    class IActionMainWindow;
    class ElectronicComponentValueWindow;
    class ElectronicComponentsModel;
}

class APPLICATION_EXPORT Application
        : public QApplication
{
    Q_OBJECT
public:
    Application(int, char*[]);
    ~Application();

private slots:
    void onResistorComponents();
    void onArrayCreator();

private:
    void init();

private:
    std::unique_ptr<MainWindow::ElectronicComponentValueWindow> m_componentsWindow;
    std::unique_ptr<MainWindow::ElectronicComponentsModel> m_componentsModel;

    std::unique_ptr<MainWindow::IActionMainWindow> m_actions;
    std::unique_ptr<GeneralAPI> m_generalAPI;

    QPointer<Dev::ArrayCreatorByImage> m_arrayCreatorWindow;
    QPointer<MainApplicationWindow> m_winui;
};

#endif // APPLICATION_H
