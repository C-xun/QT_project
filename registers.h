#ifndef REGISTERS_H
#define REGISTERS_H

#include <QWidget>

namespace Ui {
class registers;
}

class registers : public QWidget
{
    Q_OBJECT

public:
    explicit registers(QWidget *parent = 0);
    ~registers();
    virtual void paintEvent(QPaintEvent *event);

private:
    Ui::registers *ui;
signals:
    void back(void);
};

#endif // REGISTERS_H
