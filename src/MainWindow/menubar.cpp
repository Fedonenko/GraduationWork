#include "menubar.h"

#include <QAction>
#include <QToolButton>
#include <QSpacerItem>
#include <QMenu>

#include "ui_menubar.h"
#include "iactionsmenubar.h"

using namespace MainWindow;

QString pathToResources()
{
    return QString(":/image");
}

QString pathToolsIMG()
{
    static const QString path{ QString("%1/tools.svg").arg(pathToResources()) };
    return path;
}

QString pathViewIMG()
{
    static const QString path{ QString("%1/view.svg").arg(pathToResources()) };
    return path;
}

QString pathSettingIMG()
{
    static const QString path{ QString("%1/setting_cogwheel.svg").arg(pathToResources()) };
    return path;
}

QString pathAboutIMG()
{
    static const QString path{ QString("%1/about.svg").arg(pathToResources()) };
    return path;
}

//QString pathResistorIMG()
//{
//    static const QString path("E:\\Diploma\\GraduationWork\\src\\MainWindow\\resources\\resistor.svg");
//    return path;
//}

MenuBar::MenuBar(IActionsMenuBar* actions, QWidget *parent)
    : Widget(parent)
    , m_ui{ new Ui::MenuBar }
    , m_actions{ actions }
{
    m_ui->setupUi(this);

    //tools menu
    {
        QPixmap img(pathToolsIMG());

//        QAction* action = new QAction(img, QString("Tools"));
//        action->setToolTip("Tools");
//        action->setMenu(toolsMenu());

        QToolButton* button = new QToolButton();

        button->setPopupMode(QToolButton::InstantPopup);
        button->setIcon(img);
        button->setToolTip("Tools");
        button->setMenu(toolsMenu());
        //button->addAction(action);


        m_ui->layoutMenuButton->addWidget(button);
    }

    //view menu
    {
        QPixmap img(pathViewIMG());

        QAction* action = new QAction(img, QString("View"));
        action->setToolTip("View");

        QToolButton* button = new QToolButton();

        button->setIcon(img);
        button->setToolTip("View");
        button->addAction(action);

        m_ui->layoutMenuButton->addWidget(button);
    }

    //setting menu
    {
        QPixmap img(pathSettingIMG());

        QAction* action = new QAction(img, QString("Application Setting"));
        action->setToolTip("Setting");

        QToolButton* button = new QToolButton();

        button->setPopupMode(QToolButton::InstantPopup);
        button->setIcon(img);
        button->setToolTip("Setting");
        button->addAction(action);

        m_ui->layoutMenuButton->addWidget(button);
    }

    //about menu
    {
        QPixmap img(pathAboutIMG());

        QAction* action = new QAction(img, QString(tr("About")));
        action->setToolTip("About");

        QToolButton* button = new QToolButton();

        button->setPopupMode(QToolButton::InstantPopup);
        button->setIcon(img);
        button->setToolTip("About");
        button->addAction(action);
        button->setMenu(aboutMenu());

        m_ui->layoutMenuButton->addWidget(button);
    }

    {
        m_ui->layoutMenuButton->addStretch(1);
    }
}

MenuBar::~MenuBar()
{
}

void MenuBar::onResistor()
{

}

QMenu* MenuBar::toolsMenu()
{
    if(m_toolsMenu)
    {
        return m_toolsMenu;
    }
    m_toolsMenu = new QMenu();

//    auto resistor = new QAction(tr("Resistor"));
//    resistor->setIcon(QPixmap(pathResistorIMG()));
//    resistor->setToolTip(tr("Resistor"));

    //connect();

    auto capacitor = new QAction(tr("Capacitor"));

    m_toolsMenu->addAction(m_actions->resistor());
    m_toolsMenu->addAction(capacitor);

    return m_toolsMenu;
}

QMenu* MenuBar::aboutMenu()
{
    if(m_aboutMenu)
    {
        return m_aboutMenu;
    }
    m_aboutMenu = new QMenu;//(this);

    m_aboutMenu->addAction(m_actions->arrayCreator());

    return m_aboutMenu;
}
