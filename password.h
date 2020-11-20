#ifndef PASSWORD_H
#define PASSWORD_H

#include <QWidget>

namespace Ui {
class Password;
}

class Password : public QWidget
{
    Q_OBJECT

public:
    explicit Password(QWidget *parent = 0);
    ~Password();

private:
    Ui::Password *ui;
};

#endif // PASSWORD_H
