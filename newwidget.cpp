#include "newwidget.h"
#include "ui_newwidget.h"
#include <QPushButton>
#include <QDateTime>
#include <iostream>
#include <fstream>
#include <QMessageBox>

using namespace std;

NewWidget::NewWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NewWidget)
{
    ui->setupUi(this);
    this->setFixedSize(1067,600);
    this->setWindowIcon(QIcon(":/Interface.png"));
    this->setWindowTitle("PLC_Interface  ——XUN");

    ui->index_btn->setIcon(QIcon(":/main.png"));
    ui->index_btn->setIconSize(QSize(50,50));

    ui->set_btn->setIcon(QIcon(":/set.png"));
    ui->set_btn->setIconSize(QSize(50,50));

    ui->close_btn->setIcon(QIcon(":/exit.png"));
    ui->close_btn->setIconSize(QSize(50,50));

    ui->return_btn->setIcon(QIcon(":/return.png"));
    ui->return_btn->setIconSize(QSize(50,50));

    ui->monitor_btn->setIcon(QIcon(":/monitor.png"));
    ui->monitor_btn->setIconSize(QSize(50,50));

    connect(ui->close_btn,&QPushButton::clicked,[=](){
        int ret;
        ret = QMessageBox::question(this,"退出","你是否确定退出系统？？？",QMessageBox::Yes,QMessageBox::No);
        if(ret == QMessageBox::Yes)
        {
            ofstream in_Record_File("Record.txt",ios::app);
            string record = "从主系统页面退出系统,";
            QDateTime sys_time = QDateTime::currentDateTime();
            string current_date = sys_time.toString("yyyy.MM.dd - hh:mm:ss - ddd\n").toStdString();
            in_Record_File<<record<<current_date;

            this->close();
        }
        else if(ret == QMessageBox::No)
        {
        }
    });

    connect(ui->index_btn,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(0);
    });

    connect(ui->monitor_btn,&QPushButton::clicked,[=](){
        ofstream in_Record_File("Record.txt",ios::app);
        string record = "进入柱状图生成页面,";
        QDateTime sys_time = QDateTime::currentDateTime();
        string current_date = sys_time.toString("yyyy.MM.dd - hh:mm:ss - ddd\n").toStdString();
        in_Record_File<<record<<current_date;
        in_Record_File.close();

        ui->stackedWidget->setCurrentIndex(1);
    });

    connect(ui->set_btn,&QPushButton::clicked,[=](){
        ofstream in_Record_File("Record.txt",ios::app);
        string record = "进入设置页面,";
        QDateTime sys_time = QDateTime::currentDateTime();
        string current_date = sys_time.toString("yyyy.MM.dd - hh:mm:ss - ddd\n").toStdString();
        in_Record_File<<record<<current_date;
        in_Record_File.close();

        ui->stackedWidget->setCurrentIndex(2);
    });

    connect(ui->return_btn,&QPushButton::clicked,[=](){
        ofstream in_Record_File("Record.txt",ios::app);
        string record = "从主系统页面返回登录页面,";
        QDateTime sys_time = QDateTime::currentDateTime();
        string current_date = sys_time.toString("yyyy.MM.dd - hh:mm:ss - ddd\n").toStdString();
        in_Record_File<<record<<current_date;
        in_Record_File.close();

        emit this->back();
    });
}

NewWidget::~NewWidget()
{
    delete ui;
}

