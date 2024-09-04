#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QProcess>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SwarmDominantWindow) {
    ui->setupUi(this);
    ui->beta_tabWidget->clear();

    beta_process = new QProcess;
    beta_process->start("bash");
    beta_process->waitForStarted();

    gamma_process = new QProcess;
    gamma_process->start("bash");
    gamma_process->waitForStarted();

    connect(beta_process, SIGNAL(readyReadStandardOutput()), this, SLOT(beta_readBashStandardOutput()));
    connect(beta_process, SIGNAL(readyReadStandardError()), this, SLOT(beta_readBashStandardError()));

    connect(gamma_process, SIGNAL(readyReadStandardOutput()), this, SLOT(gamma_readBashStandardOutput()));
    connect(gamma_process, SIGNAL(readyReadStandardError()), this, SLOT(gamma_readBashStandardError()));
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
        beta_process->write(ui->lineEdit->text().toLocal8Bit() + '\n');
    }
    ui->gammaTerminal->append("gamma@gamma-sr:~$ " + _str);
    gamma_process->write(ui->lineEdit->text().toLocal8Bit() + '\n');

    ui->lineEdit->clear();
}


void MainWindow::on_connectButton_clicked() {
    QString _beta_ssh = "ssh -tt beta@beta-sr";
    QString _gamma_ssh = "ssh -tt gamma@gamma-sr";

    ui->connectButton->setText("Connecting");

    ui->betaTerminal->append("beta@beta-sr:~$ " + _beta_ssh);
    beta_process->write(_beta_ssh.toLocal8Bit() + '\n');
    beta_process->waitForReadyRead();
    ui->gammaTerminal->append("gamma@gamma-sr:~$ " + _gamma_ssh);
    gamma_process->write(_gamma_ssh.toLocal8Bit() + '\n');
    gamma_process->waitForReadyRead();

    QByteArray _beta_out = beta_process->readAllStandardOutput();
    QByteArray _gamma_out = gamma_process->readAllStandardOutput();
    ui->betaTerminal->append(QString::fromLocal8Bit(_beta_out));
    ui->gammaTerminal->append(QString::fromLocal8Bit(_gamma_out));

    ui->connectButton->setText("Connect");
    return;
}



