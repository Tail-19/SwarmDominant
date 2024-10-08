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

    alpha_username = ui->alpha_comboBox->currentText();
    beta_username= ui->beta_comboBox->currentText();
    gamma_username = ui->gamma_comboBox->currentText();
    delta_username = ui->delta_comboBox->currentText();
    epsilon_username = ui->epsilon_comboBox->currentText();

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

    epsilon_process = new QProcess;
    epsilon_process->start("bash");
    epsilon_process->waitForStarted();
    connect(epsilon_process, SIGNAL(readyReadStandardOutput()), this, SLOT(epsilon_readBashStandardOutput()));
    connect(epsilon_process, SIGNAL(readyReadStandardError()), this, SLOT(epsilon_readBashStandardError()));
}

MainWindow::~MainWindow() {
    delete ui;
    delete alpha_process;
    delete beta_process;
    delete gamma_process;
    delete delta_process;
    delete epsilon_process;
}

void MainWindow::on_lineEdit_returnPressed() {
    QString _str_rev = ui->lineEdit->text();
    QByteArray _str = _str_rev.toLocal8Bit() + '\n';
    //work on ctrl-c
    if (_str_rev == QString("cc")) {
        _str = "\x03";
    }

    if (ui->alpha_checkBox->isChecked()) {
        ui->alphaTerminal->append("alpha@alpha-sr:~$ " + _str);
        alpha_process->write(_str);
    }

    if (ui->beta_checkBox->isChecked()) {
        ui->betaTerminal->append("beta@beta-sr:~$ " + _str);
        beta_process->write(_str);
    }

    if (ui->gamma_checkBox->isChecked()) {
        ui->gammaTerminal->append("gamma@gamma-sr:~$ " + _str);
        gamma_process->write(_str);
    }

    if (ui->delta_checkBox->isChecked()) {
        ui->deltaTerminal->append("delta@delta-sr:~$ " + _str);
        delta_process->write(_str);
    }

    if (ui->epsilon_checkBox->isChecked()) {
        ui->epsilonTerminal->append("epsilon@epsilon-sr:~$ " + _str);
        epsilon_process->write(_str);
    }

    ui->lineEdit->clear();
}


void MainWindow::on_connectButton_clicked() {
    ui->connectButton->setText("Connecting");

    //check the current user
    alpha_username = ui->alpha_comboBox->currentText();
    beta_username= ui->beta_comboBox->currentText();
    gamma_username = ui->gamma_comboBox->currentText();
    delta_username = ui->delta_comboBox->currentText();
    epsilon_username = ui->epsilon_comboBox->currentText();


    if (ui->alpha_checkBox->isChecked()) {
        QString _alpha_ssh = "ssh -tt " + alpha_username + "@alpha-sr";
        ui->alphaTerminal->append(alpha_username + "@alpha-sr:~$ " + _alpha_ssh);
        alpha_process->write(_alpha_ssh.toLocal8Bit() + '\n');
    }

    if (ui->beta_checkBox->isChecked()) {
        QString _beta_ssh = "ssh -tt " + beta_username + "@beta-sr";
        ui->betaTerminal->append(beta_username + "@beta-sr:~$ " + _beta_ssh);
        beta_process->write(_beta_ssh.toLocal8Bit() + '\n');
    }

    if (ui->gamma_checkBox->isChecked()) {
        QString _gamma_ssh = "ssh -tt " + gamma_username + "@gamma-sr";
        ui->gammaTerminal->append(gamma_username + "@gamma-sr:~$ " + _gamma_ssh);
        gamma_process->write(_gamma_ssh.toLocal8Bit() + '\n');
    }

    if (ui->delta_checkBox->isChecked()) {
        QString _delta_ssh = "ssh -tt " + delta_username + "@delta-sr";
        ui->deltaTerminal->append(delta_username + "@delta-sr:~$ " + _delta_ssh);
        delta_process->write(_delta_ssh.toLocal8Bit() + '\n');
    }

    if (ui->epsilon_checkBox->isChecked()) {
        QString _epsilon_ssh = "ssh -tt " + epsilon_username + "@epsilon-sr";
        ui->deltaTerminal->append(epsilon_username + "@epsilon-sr:~$ " + _epsilon_ssh);
        epsilon_process->write(_epsilon_ssh.toLocal8Bit() + '\n');
    }

    ui->connectButton->setText("Connect");
    return;
}



