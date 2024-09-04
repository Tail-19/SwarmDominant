#include "./mainwindow.h"
#include "ui_mainwindow.h"
#include <QProcess>

void MainWindow::gamma_readBashStandardOutput() {
    QByteArray _gamma_out = gamma_process->readAllStandardOutput();
    if(!_gamma_out.isEmpty())   ui->gammaTerminal->append(QString::fromLocal8Bit(_gamma_out));
}

void MainWindow::gamma_readBashStandardError() {
    QByteArray _gamma_out = gamma_process->readAllStandardError();
    if(!_gamma_out.isEmpty())   ui->gammaTerminal->append(QString::fromLocal8Bit(_gamma_out));
}
