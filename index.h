#ifndef INDEX_H
#define INDEX_H

#include <QWidget>

namespace Ui {
class Index;
}

class Index : public QWidget
{
    Q_OBJECT

public:
    explicit Index(QWidget *parent = 0);
    ~Index();
    virtual void paintEvent(QPaintEvent *event);
private:
    Ui::Index *ui;
};

#endif // INDEX_H
