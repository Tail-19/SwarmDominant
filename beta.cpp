#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tabterminal.h"
#include <QProcess>


void MainWindow::beta_readBashStandardOutput() {
    QByteArray _beta_out = beta_process->readAllStandardOutput();
    if(!_beta_out.isEmpty()){
        _beta_out.removeLast();
        ui->betaTerminal->append(QString::fromUtf8(_beta_out));
    }
}

void MainWindow::beta_readBashStandardError() {
    QByteArray _beta_out = beta_process->readAllStandardError();
    if(!_beta_out.isEmpty())   ui->betaTerminal->append(QString::fromUtf8(_beta_out));
}

void MainWindow::on_betaAdd_pushButton_clicked() {

    QWidget *_new_page = new QWidget();

    QHBoxLayout *horizontalLayout = new QHBoxLayout(_new_page);//新建布局
    horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));//为布局设置对象名
    TabTerminal *_tab_ptr = new TabTerminal(this, beta_username, "beta-sr");
    _new_page->setLayout(horizontalLayout);//在此Widget中添加该布局
    horizontalLayout->addWidget(_tab_ptr);

    QString _beta_name = "beta" + QString::number(beta_max_tab);
    ui->beta_tabWidget->addTab(_new_page, _beta_name);
    beta_max_tab++;
}

void MainWindow::on_betaRemove_pushButton_clicked() {
    ui->beta_tabWidget->removeTab(ui->beta_tabWidget->currentIndex());
}
