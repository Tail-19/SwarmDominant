#include "./mainwindow.h"
#include "ui_mainwindow.h"
#include "tabterminal.h"
#include <QProcess>
// #include <iostream>
void MainWindow::gamma_readBashStandardOutput() {
    QByteArray _gamma_out = gamma_process->readAllStandardOutput();
    // for (int i = 0; i < _gamma_out.length(); i++) {
    //     std::cout << _gamma_out[i] << std::endl;
    // }

    if(!_gamma_out.isEmpty()) {
         _gamma_out.removeLast();
        ui->gammaTerminal->append(QString::fromUtf8(_gamma_out));
    }
}

void MainWindow::gamma_readBashStandardError() {
    QByteArray _gamma_out = gamma_process->readAllStandardError();
    if(!_gamma_out.isEmpty())   ui->gammaTerminal->append(QString::fromUtf8(_gamma_out));
}

void MainWindow::on_gammaAdd_pushButton_clicked() {

    QWidget *_new_page = new QWidget();

    QHBoxLayout *horizontalLayout = new QHBoxLayout(_new_page);//新建布局
    horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));//为布局设置对象名
    TabTerminal *_tab_ptr = new TabTerminal(this, "gamma", "gamma-sr");
    _new_page->setLayout(horizontalLayout);//在此Widget中添加该布局
    horizontalLayout->addWidget(_tab_ptr);

    QString _gamma_name = "gamma" + QString::number(gamma_max_tab);
    ui->gamma_tabWidget->addTab(_new_page, _gamma_name);
    gamma_max_tab++;
}

void MainWindow::on_gammaRemove_pushButton_clicked() {
    ui->gamma_tabWidget->removeTab(ui->gamma_tabWidget->currentIndex());
}
