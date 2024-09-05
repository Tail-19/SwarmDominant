#ifndef TABTERMINAL_H
#define TABTERMINAL_H

#include <QWidget>
#include <QPointer>
#include <QProcess>

namespace Ui {
class TabTerminal;
}

class TabTerminal : public QWidget
{
    Q_OBJECT

public:
    explicit TabTerminal(QWidget *parent = nullptr
                        , QString username = "Ubuntu22.04", QString hostname = "Linux");
    ~TabTerminal();

    void setUser(QString username="Linux");
    void setHost(QString hostname="Ubuntu22.04");
    QString getUser();
    QString getHost();

private slots:
    void readBashStandardOutput();
    void readBashStandardError();

    void on_tabLineEdit_returnPressed();

private:
    QString user;
    QString host;
    QString start_line;

    Ui::TabTerminal *ui;
    QPointer<QProcess> tab_process;
};

#endif // TABTERMINAL_H
