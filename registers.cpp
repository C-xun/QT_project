#include "registers.h"
#include "mainwindow.h"
#include "ui_registers.h"
#include <iostream>
#include <fstream>
#include <QMessageBox>
#include <QDebug>
#include <QDateTime>
#include <QPainter>
#include <QToolButton>

using namespace std;

registers::registers(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::registers)
{
    ui->setupUi(this);
    this->setFixedSize(1067,600);
    this->setWindowIcon(QIcon(":/Interface.png"));
    this->setWindowTitle("PLC_Interface  ——XUN");

    ui->user_text->setPlaceholderText("由字母、数字或 _ 组成账号");
    ui->psw_text->setPlaceholderText("请输入您的密码");
    ui->psw_text2->setPlaceholderText("请再次输入您的密码");

    ui->user->setStyleSheet("color:#FFFFFF");
    ui->psw->setStyleSheet("color:#FFFFFF");
    ui->psw_2->setStyleSheet("color:#FFFFFF");

    ui->user_text->setStyleSheet("border-radius:5px;");
    ui->psw_text->setStyleSheet("border-radius:5px;");
    ui->psw_text2->setStyleSheet("border-radius:5px;");

    ui->close_btn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    ui->close_btn->setStyleSheet("border-radius:3px;border:1px solid #aaffff; border-style: outset;color:#FFFFFF;");

    ui->reg_btn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    ui->reg_btn->setStyleSheet("border-radius:3px;border:1px solid #aaffff; border-style: outset;color:#FFFFFF;");


    ui->login_btn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    ui->login_btn->setStyleSheet("border-radius:3px;border:1px solid #aaffff; border-style: outset;color:#FFFFFF;");

    connect(ui->reg_btn,&QToolButton::clicked,[=](){
        bool Bool = true;
        QString str1,str2,str3;
        str1=ui->user_text->text();
        str2=ui->psw_text->text();
        str3=ui->psw_text2->text();
        if(str1==""){
            QMessageBox::critical(this,"错误","抱歉您注册失败！用户名不能为空！");
        }
        else if(str2==""||str3==""){
            QMessageBox::critical(this,"错误","抱歉您注册失败！请设置您的密码！");
        }
        else if(str1!=""&&str2!=""&&str3!="")
        {
            if(str2==str3)
            {
                ofstream OutFile("Register.txt",ios::app);
                ifstream ReadFile("Register.txt",ios::in);
                string tmp;

                while(getline(ReadFile, tmp, '\n'))
                {
                    QString str = QString::fromStdString(tmp);
                    QStringList list = str.split(",");
                    QString str1_1 = list[0];
                        if(str1==str1_1){
                            qDebug()<<"用户名已存在！"<<endl;
                            QMessageBox::critical(this,"错误","抱歉您注册失败！用户名已存在！");
                            Bool = false;
                            break;
                        }
                }

                if(Bool){
                    ofstream in_Record_File("Record.txt",ios::app);
                    string record = "用户 "+str1.toStdString()+" 成功注册,";
                    QDateTime sys_time = QDateTime::currentDateTime();
                    string current_date = sys_time.toString("yyyy.MM.dd - hh:mm:ss - ddd\n").toStdString();
                    in_Record_File<<record<<current_date;
                    in_Record_File.close();

                    OutFile << (str1+","+str2+"\n").toStdString();
                    OutFile.close();
                    QMessageBox::information(this,"恭喜","恭喜您注册成功！");
                }
            }
            else if(str2!=str3){
                QMessageBox::critical(this,"错误","抱歉您注册失败！请两次密码一致！");
            }
        }

    });

    connect(ui->login_btn,&QToolButton::clicked,[=](){
        ofstream in_Record_File("Record.txt",ios::app);
        string record = "从注册页面返回登录页面,";
        QDateTime sys_time = QDateTime::currentDateTime();
        string current_date = sys_time.toString("yyyy.MM.dd - hh:mm:ss - ddd\n").toStdString();
        in_Record_File<<record<<current_date;
        in_Record_File.close();

        emit this->back();
    });

    connect(ui->close_btn, &QToolButton::clicked,[=](){  
        int ret;
        ret = QMessageBox::question(this,"退出","你是否确定退出系统？？？",QMessageBox::Yes,QMessageBox::No);
        if(ret == QMessageBox::Yes)
        {
            ofstream in_Record_File("Record.txt",ios::app);
            string record = "从注册页面退出系统,";
            QDateTime sys_time = QDateTime::currentDateTime();
            string current_date = sys_time.toString("yyyy.MM.dd - hh:mm:ss - ddd\n").toStdString();
            in_Record_File<<record<<current_date;
            in_Record_File.close();

            this->close();
        }
        else if(ret == QMessageBox::No)
        {
        }
    });
}

registers::~registers()
{
    delete ui;
}

void registers::paintEvent(QPaintEvent *event)
{
    static int x = 0;
    static int y = 0;

    QPainter *painter = new QPainter(this);
    QPixmap pix;
    pix.load(":/web.jpg");
    painter->drawPixmap(x,y,this->width(),this->height(),pix);
}
