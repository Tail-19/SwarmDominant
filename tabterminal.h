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
    explicit TabTerminal(QWidget *parent = nullptr, QString username = "linux", QString hostname = "ubuntu22.04");
    ~TabTerminal();

private slots:
    void readBashStandardOutput();
    void readBashStandardError();

    void on_tabLineEdit_returnPressed();

private:
    Ui::TabTerminal *ui;
    QProcess *tab_process;

public:
    QString user;
    QString host;
    QString start_line;
};

#endif // TABTERMINAL_H
