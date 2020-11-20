#ifndef MAINDEBUG_H
#define MAINDEBUG_H

#include <QMainWindow>

namespace Ui {
class MainDebug;
}

class MainDebug : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainDebug(QWidget *parent = 0);
    ~MainDebug();

private:
    Ui::MainDebug *ui;
};

#endif // MAINDEBUG_H
