#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tabterminal.h"
#include <QProcess>


void MainWindow::alpha_readBashStandardOutput() {
    QByteArray _alpha_out = alpha_process->readAllStandardOutput();
    if(!_alpha_out.isEmpty()){
        _alpha_out.removeLast();
        ui->alphaTerminal->append(QString::fromUtf8(_alpha_out));
    }
}

void MainWindow::alpha_readBashStandardError() {
    QByteArray _alpha_out = alpha_process->readAllStandardError();
    if(!_alpha_out.isEmpty())   ui->alphaTerminal->append(QString::fromUtf8(_alpha_out));
}

void MainWindow::on_alphaAdd_pushButton_clicked() {

    QWidget *_new_page = new QWidget();

    QHBoxLayout *horizontalLayout = new QHBoxLayout(_new_page);//新建布局
    horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));//为布局设置对象名
    TabTerminal *_tab_ptr = new TabTerminal(this, "alpha", "alpha-sr");
    _new_page->setLayout(horizontalLayout);//在此Widget中添加该布局
    horizontalLayout->addWidget(_tab_ptr);

    QString _alpha_name = "alpha" + QString::number(alpha_max_tab);
    ui->alpha_tabWidget->addTab(_new_page, _alpha_name);
    alpha_max_tab++;
}

void MainWindow::on_alphaRemove_pushButton_clicked() {
    ui->alpha_tabWidget->removeTab(ui->alpha_tabWidget->currentIndex());
}
