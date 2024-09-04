#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPointer>
#include <QStandardItemModel>

class QProcess;

QT_BEGIN_NAMESPACE
namespace Ui { class SwarmDominantWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_lineEdit_returnPressed();
    void on_connectButton_clicked();

    void beta_readBashStandardOutput();
    void beta_readBashStandardError();
    void gamma_readBashStandardOutput();
    void gamma_readBashStandardError();
    void on_betaAdd_pushButton_clicked();

    void on_betaRemove_pushButton_clicked();

private:
    Ui::SwarmDominantWindow *ui;
    QPointer<QProcess> beta_process, gamma_process;
};
#endif // MAINWINDOW_H
