#include "set.h"
#include "ui_set.h"
#include <QDebug>
#include <QDateTime>
#include <iostream>
#include <fstream>

using namespace std;

Set::Set(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Set)
{
    ui->setupUi(this);
    connect(ui->class_btn,&QPushButton::clicked,[=](){
        ofstream in_Record_File("Record.txt",ios::app);
        string record = "进入分类器页面,";
        QDateTime sys_time = QDateTime::currentDateTime();
        string current_date = sys_time.toString("yyyy.MM.dd - hh:mm:ss - ddd\n").toStdString();
        in_Record_File<<record<<current_date;
        in_Record_File.close();

        ui->stacked_set->setCurrentIndex(0);
    });

    connect(ui->list_btn,&QPushButton::clicked,[=](){
        ofstream in_Record_File("Record.txt",ios::app);
        string record = "进入操作记录页面,";
        QDateTime sys_time = QDateTime::currentDateTime();
        string current_date = sys_time.toString("yyyy.MM.dd - hh:mm:ss - ddd\n").toStdString();
        in_Record_File<<record<<current_date;
        in_Record_File.close();

        ui->stacked_set->setCurrentIndex(1);

        emit this->add_list();
    });

    connect(ui->password_btn,&QPushButton::clicked,[=](){
        ofstream in_Record_File("Record.txt",ios::app);
        string record = "进入密码设置页面,";
        QDateTime sys_time = QDateTime::currentDateTime();
        string current_date = sys_time.toString("yyyy.MM.dd - hh:mm:ss - ddd\n").toStdString();
        in_Record_File<<record<<current_date;
        in_Record_File.close();

        ui->stacked_set->setCurrentIndex(2);
    });

    connect(ui->debug_btn,&QPushButton::clicked,[=](){
        ofstream in_Record_File("Record.txt",ios::app);
        string record = "进入串口调试页面,";
        QDateTime sys_time = QDateTime::currentDateTime();
        string current_date = sys_time.toString("yyyy.MM.dd - hh:mm:ss - ddd\n").toStdString();
        in_Record_File<<record<<current_date;
        in_Record_File.close();

        ui->stacked_set->setCurrentIndex(3);
    });
}

Set::~Set()
{
    delete ui;
}
