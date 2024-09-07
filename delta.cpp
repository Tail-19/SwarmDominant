#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tabterminal.h"
#include <QProcess>


void MainWindow::delta_readBashStandardOutput() {
    QByteArray _delta_out = delta_process->readAllStandardOutput();
    if(!_delta_out.isEmpty()){
        _delta_out.removeLast();
        ui->deltaTerminal->append(QString::fromUtf8(_delta_out));
    }
}

void MainWindow::delta_readBashStandardError() {
    QByteArray _delta_out = delta_process->readAllStandardError();
    if(!_delta_out.isEmpty())   ui->deltaTerminal->append(QString::fromUtf8(_delta_out));
}

void MainWindow::on_deltaAdd_pushButton_clicked() {

    QWidget *_new_page = new QWidget();

    QHBoxLayout *horizontalLayout = new QHBoxLayout(_new_page);//新建布局
    horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));//为布局设置对象名
    TabTerminal *_tab_ptr = new TabTerminal(this, delta_username, "delta-sr");
    _new_page->setLayout(horizontalLayout);//在此Widget中添加该布局
    horizontalLayout->addWidget(_tab_ptr);

    QString _delta_name = "delta" + QString::number(delta_max_tab);
    ui->delta_tabWidget->addTab(_new_page, _delta_name);
    delta_max_tab++;
}

void MainWindow::on_deltaRemove_pushButton_clicked() {
    ui->delta_tabWidget->removeTab(ui->delta_tabWidget->currentIndex());
}
