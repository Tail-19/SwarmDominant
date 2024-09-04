#ifndef TABTERMINAL_H
#define TABTERMINAL_H

#include <QWidget>

namespace Ui {
class TabTerminal;
}

class TabTerminal : public QWidget
{
    Q_OBJECT

public:
    explicit TabTerminal(QWidget *parent = nullptr);
    ~TabTerminal();

private:
    Ui::TabTerminal *ui;
};

#endif // TABTERMINAL_H
