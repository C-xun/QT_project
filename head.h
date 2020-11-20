#ifndef HEAD_H
#define HEAD_H

#include <QWidget>

namespace Ui {
class Head;
}

class Head : public QWidget
{
    Q_OBJECT

public:
    explicit Head(QWidget *parent = 0);
    ~Head();
    int id1 = 0;
    int id2 = 0;
    virtual void timerEvent(QTimerEvent *event);

private:
    Ui::Head *ui;
};

#endif // HEAD_H
