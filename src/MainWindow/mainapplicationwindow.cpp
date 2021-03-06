#include "mainapplicationwindow.h"
#include "menubar.h"
#include "iactionmainwindow.h"

using namespace MainWindow;

MainApplicationWindow::MainApplicationWindow(IActionMainWindow* actions, int width, int height, QWidget* parent)
    : QMainWindow(parent)
    , m_actions{ actions }
{
    addToolBar(Qt::TopToolBarArea, createToolBar());

    initToolBar();
    initMenuBar();

    m_chartWidget = new Chart::ChartWidget;
    QHBoxLayout* layout = new QHBoxLayout;
    layout->addWidget(new QLabel("Hello World!"));
    m_chartWidget->setLayout(layout);

    m_mdiArea = new QMdiArea;

    auto mdiSubWindow = m_mdiArea->addSubWindow(m_chartWidget, Qt::ToolTip);

    setCentralWidget(m_mdiArea);

    resize(width, height);

    m_chartWidget->show();
    m_chartWidget->setWindowFlag(Qt::SubWindow);
}

MainApplicationWindow::~MainApplicationWindow()
{

}

void MainApplicationWindow::slotNotImpl(){
    QMessageBox::information(nullptr, "Message", "Not Implemented");
}

QToolBar* MainApplicationWindow::createToolBar(){
    QToolBar* toolBar = new QToolBar("Linker ToolBar");
    toolBar->addAction(QPixmap(":/img1.png"), "1", this, SLOT(slotNotImpl()));
    toolBar->addSeparator();
    toolBar->addAction(QPixmap(":/img2.png"), "2", this, SLOT(slotNotImpl()));

    return toolBar;
}

void MainApplicationWindow::initToolBar()
{

}

void MainApplicationWindow::initMenuBar()
{
    auto menuBar = new MenuBar(m_actions->menuBar());
    setMenuWidget(menuBar);
    //setMenuBar(new MenuBar());
}
