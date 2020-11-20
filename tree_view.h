#ifndef TREE_VIEW_H
#define TREE_VIEW_H

#include <QWidget>

QT_BEGIN_NAMESPACE

namespace Ui {
class Tree_view;
}

class Tree_view : public QWidget
{
    Q_OBJECT

public:
    explicit Tree_view(QWidget *parent = 0);
    ~Tree_view();

private:
    Ui::Tree_view *ui;
};

#endif // TREE_VIEW_H
