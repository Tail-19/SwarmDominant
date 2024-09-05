#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QProcess>
#include <QDebug>
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SwarmDominantWindow) {
    ui->setupUi(this);
    ui->alpha_tabWidget->clear();
    ui->beta_tabWidget->clear();
    ui->gamma_tabWidget->clear();
    ui->delta_tabWidget->clear();
    ui->epsilon_tabWidget->clear();

    alpha_process = new QProcess;
    alpha_process->start("bash");
    alpha_process->waitForStarted();
    connect(alpha_process, SIGNAL(readyReadStandardOutput()), this, SLOT(alpha_readBashStandardOutput()));
    connect(alpha_process, SIGNAL(readyReadStandardError()), this, SLOT(alpha_readBashStandardError()));

    beta_process = new QProcess;
    beta_process->start("bash");
    beta_process->waitForStarted();
    connect(beta_process, SIGNAL(readyReadStandardOutput()), this, SLOT(beta_readBashStandardOutput()));
    connect(beta_process, SIGNAL(readyReadStandardError()), this, SLOT(beta_readBashStandardError()));

    gamma_process = new QProcess;
    gamma_process->start("bash");
    gamma_process->waitForStarted();
    connect(gamma_process, SIGNAL(readyReadStandardOutput()), this, SLOT(gamma_readBashStandardOutput()));
    connect(gamma_process, SIGNAL(readyReadStandardError()), this, SLOT(gamma_readBashStandardError()));

    delta_process = new QProcess;
    delta_process->start("bash");
    delta_process->waitForStarted();
    connect(delta_process, SIGNAL(readyReadStandardOutput()), this, SLOT(delta_readBashStandardOutput()));
    connect(delta_process, SIGNAL(readyReadStandardError()), this, SLOT(delta_readBashStandardError()));

    // epsilon_process = new QProcess;
    // epsilon_process->start("bash");
    // epsilon_process->waitForStarted();
    // connect(epsilon_process, SIGNAL(readyReadStandardOutput()), this, SLOT(epsilon_readBashStandardOutput()));
    // connect(epsilon_process, SIGNAL(readyReadStandardError()), this, SLOT(epsilon_readBashStandardError()));
}

MainWindow::~MainWindow() {
    delete ui;
    delete beta_process;
    delete gamma_process;
}

void MainWindow::on_lineEdit_returnPressed() {
    QString _str = ui->lineEdit->text();

    if (ui->beta_checkBox->isChecked()) {
        ui->betaTerminal->append("beta@beta-sr:~$ " + _str);
        beta_process->write(_str.toLocal8Bit() + '\n');
    }

    if (ui->gamma_checkBox->isChecked()) {
        ui->gammaTerminal->append("gamma@gamma-sr:~$ " + _str);
        gamma_process->write(_str.toLocal8Bit() + '\n');
    }

    ui->lineEdit->clear();
}


void MainWindow::on_connectButton_clicked() {
    ui->connectButton->setText("Connecting");

    if (ui->beta_checkBox->isChecked()) {
        QString _beta_ssh = "ssh -tt beta@beta-sr";
        ui->betaTerminal->append("beta@beta-sr:~$ " + _beta_ssh);
        beta_process->write(_beta_ssh.toLocal8Bit() + '\n');
    }

    if (ui->gamma_checkBox->isChecked()) {
        QString _gamma_ssh = "ssh -tt gamma@gamma-sr";
        ui->gammaTerminal->append("gamma@gamma-sr:~$ " + _gamma_ssh);
        gamma_process->write(_gamma_ssh.toLocal8Bit() + '\n');
    }

    ui->connectButton->setText("Connect");
    return;
}



