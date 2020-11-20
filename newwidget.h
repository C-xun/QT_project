#ifndef NEWWIDGET_H
#define NEWWIDGET_H

#include <QWidget>

namespace Ui {
class NewWidget;
}

class NewWidget : public QWidget
{
    Q_OBJECT

public:
    explicit NewWidget(QWidget *parent = 0);
    ~NewWidget();

private:
    Ui::NewWidget *ui;

signals:
    void back(void);
};

#endif // NEWWIDGET_H
