#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tabterminal.h"
#include <QProcess>

void MainWindow::beta_readBashStandardOutput() {
    QByteArray _beta_out = beta_process->readAllStandardOutput();
    if(!_beta_out.isEmpty())   ui->betaTerminal->append(QString::fromLocal8Bit(_beta_out));
}

void MainWindow::beta_readBashStandardError() {
    QByteArray _beta_out = beta_process->readAllStandardError();
    if(!_beta_out.isEmpty())   ui->betaTerminal->append(QString::fromLocal8Bit(_beta_out));
}

void MainWindow::on_betaAdd_pushButton_clicked()
{
    TabTerminal *_new_tab = new TabTerminal();

    ui->beta_tabWidget->addTab(_new_tab, QString("name"));
}
