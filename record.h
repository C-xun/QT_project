#ifndef RECORD_H
#define RECORD_H

#include <QWidget>

namespace Ui {
class Record;
}

class Record : public QWidget
{
    Q_OBJECT

public:
    explicit Record(QWidget *parent = 0);
    ~Record(); 
    int id = 0;
    virtual void timerEvent(QTimerEvent *event);

private:
    Ui::Record *ui;
};

#endif // RECORD_H
