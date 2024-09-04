#include "tabterminal.h"
#include "ui_tabterminal.h"

TabTerminal::TabTerminal(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TabTerminal)
{
    ui->setupUi(this);
}

TabTerminal::~TabTerminal()
{
    delete ui;
}
