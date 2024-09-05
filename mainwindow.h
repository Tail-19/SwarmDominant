#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPointer>
#include <QStandardItemModel>
#include <QProcess>

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

    void alpha_readBashStandardOutput();
    void alpha_readBashStandardError();
    void on_alphaAdd_pushButton_clicked();
    void on_alphaRemove_pushButton_clicked();

    void beta_readBashStandardOutput();
    void beta_readBashStandardError();
    void on_betaAdd_pushButton_clicked();
    void on_betaRemove_pushButton_clicked();

    void gamma_readBashStandardOutput();
    void gamma_readBashStandardError();
    void on_gammaAdd_pushButton_clicked();
    void on_gammaRemove_pushButton_clicked();

    void delta_readBashStandardOutput();
    void delta_readBashStandardError();
    void on_deltaAdd_pushButton_clicked();
    void on_deltaRemove_pushButton_clicked();

    void epsilon_readBashStandardOutput();
    void epsilon_readBashStandardError();
    void on_epsilonAdd_pushButton_clicked();
    void on_epsilonRemove_pushButton_clicked();


private:
    Ui::SwarmDominantWindow *ui;

    QPointer<QProcess> alpha_process, beta_process, gamma_process, delta_process, epsilon_process;

    // The max index of the tab
    int alpha_max_tab = 0;
    int beta_max_tab= 0;
    int gamma_max_tab = 0;
    int delta_max_tab = 0;
    int epsilon_max_tab = 0;
};
#endif // MAINWINDOW_H
