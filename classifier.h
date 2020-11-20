#ifndef CLASSIFIER_H
#define CLASSIFIER_H

#include <QWidget>

namespace Ui {
class Classifier;
}

class Classifier : public QWidget
{
    Q_OBJECT

public:
    explicit Classifier(QWidget *parent = 0);
    ~Classifier();

private:
    Ui::Classifier *ui;
};

#endif // CLASSIFIER_H
