#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tabterminal.h"
#include <QProcess>
#include <iostream>

void MainWindow::beta_readBashStandardOutput() {
    QByteArray _beta_out = beta_process->readAllStandardOutput();
    if(!_beta_out.isEmpty())   ui->betaTerminal->append(QString::fromLocal8Bit(_beta_out));
}

void MainWindow::beta_readBashStandardError() {
    QByteArray _beta_out = beta_process->readAllStandardError();
    if(!_beta_out.isEmpty())   ui->betaTerminal->append(QString::fromLocal8Bit(_beta_out));
}

void MainWindow::on_betaAdd_pushButton_clicked() {
    QWidget *_new_page = new QWidget();

    QHBoxLayout *horizontalLayout = new QHBoxLayout(_new_page);//新建布局
    horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));//为布局设置对象名

    TabTerminal *_tab_ptr = new TabTerminal(ui->beta_tabWidget, "beta", "beta-sr");

    _new_page->setLayout(horizontalLayout);//在此Widget中添加该布局
    horizontalLayout->addWidget(_tab_ptr);

    QString _name = "beta" + QString::number(ui->beta_tabWidget->count());
    ui->beta_tabWidget->addTab(_new_page, _name);
}

void MainWindow::on_betaRemove_pushButton_clicked() {
    ui->beta_tabWidget->removeTab(ui->beta_tabWidget->currentIndex());
}
