#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tabterminal.h"
#include <QProcess>


void MainWindow::epsilon_readBashStandardOutput() {
    QByteArray _epsilon_out = epsilon_process->readAllStandardOutput();
    if(!_epsilon_out.isEmpty()){
        _epsilon_out.removeLast();
        ui->epsilonTerminal->append(QString::fromUtf8(_epsilon_out));
    }
}

void MainWindow::epsilon_readBashStandardError() {
    QByteArray _epsilon_out = epsilon_process->readAllStandardError();
    if(!_epsilon_out.isEmpty())   ui->epsilonTerminal->append(QString::fromUtf8(_epsilon_out));
}

void MainWindow::on_epsilonAdd_pushButton_clicked() {

    QWidget *_new_page = new QWidget();

    QHBoxLayout *horizontalLayout = new QHBoxLayout(_new_page);//新建布局
    horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));//为布局设置对象名
    TabTerminal *_tab_ptr = new TabTerminal(this, "epsilon", "epsilon-sr");
    _new_page->setLayout(horizontalLayout);//在此Widget中添加该布局
    horizontalLayout->addWidget(_tab_ptr);

    QString _epsilon_name = "epsilon" + QString::number(epsilon_max_tab);
    ui->epsilon_tabWidget->addTab(_new_page, _epsilon_name);
    epsilon_max_tab++;
}

void MainWindow::on_epsilonRemove_pushButton_clicked() {
    ui->epsilon_tabWidget->removeTab(ui->epsilon_tabWidget->currentIndex());
}
