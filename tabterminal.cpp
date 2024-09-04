#include "tabterminal.h"
#include "ui_tabterminal.h"

TabTerminal::TabTerminal(QWidget *parent, QString username, QString hostname)
    : QWidget(parent)
    , ui(new Ui::TabTerminal)
{
    user = username;
    host = hostname;
    start_line = username + "@" + hostname + ":~$ ";

    ui->setupUi(this);
    tab_process = new QProcess;
    tab_process->start("bash");
    tab_process->waitForStarted();

    connect(tab_process, SIGNAL(readyReadStandardOutput()), this, SLOT(readBashStandardOutput()));
    connect(tab_process, SIGNAL(readyReadStandardError()), this, SLOT(readBashStandardError()));

    tab_process->write(QString("ssh -tt " + username + "@" + hostname).toLocal8Bit());
}

void TabTerminal::readBashStandardOutput() {
    QByteArray _out = tab_process->readAllStandardOutput();
    if(!_out.isEmpty())   ui->tabBrowser->append(QString::fromLocal8Bit(_out));

}

void TabTerminal::readBashStandardError() {
    QByteArray _out = tab_process->readAllStandardError();
    if(!_out.isEmpty())   ui->tabBrowser->append(QString::fromLocal8Bit(_out));
}

void TabTerminal::on_tabLineEdit_returnPressed() {
    QString _str = ui->tabLineEdit->text();

    ui->tabBrowser->append(start_line + _str);
    tab_process->write(ui->tabLineEdit->text().toLocal8Bit() + '\n');

    ui->tabLineEdit->clear();
}

void TabTerminal::setUser(QString username) {
    this->user = username;
}

void TabTerminal::setHost(QString hostname) {
    this->user = host;
}

QString TabTerminal::getHost() {
   return host;
}

QString TabTerminal::getUser() {
    return user;
}

TabTerminal::~TabTerminal()
{
    delete ui;
}
