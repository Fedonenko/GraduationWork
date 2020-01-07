#include "menubar.h"
#include "ui_menubar.h"

MenuBar::MenuBar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuBar)
{
    ui->setupUi(this);
}

MenuBar::~MenuBar()
{
    delete ui;
}
