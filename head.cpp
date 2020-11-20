#include "head.h"
#include "ui_head.h"
#include <QTimer>
#include <QDateTime>

Head::Head(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Head)
{
    ui->setupUi(this);

    this->id1 = this->startTimer(1000);
    QTimer *timer = new QTimer(this);

    ui->information->setStyleSheet("background-color:red;");
}

Head::~Head()
{
    delete ui;
}

void Head::timerEvent(QTimerEvent *event)
{
    if(event->timerId()==this->id1)
    {
        QDateTime current_date_time = QDateTime::currentDateTime();
        QString current_date =current_date_time.toString("yyyy.MM.dd\nhh:mm:ss\nddd");
        ui->time->setText(current_date);
    }
}
