#include "mainwindow.h"
#include "registers.h"
#include "newwidget.h"
#include <iostream>
#include <fstream>
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDateTime>
#include <QPainter>
#include <QToolButton>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(1067,600);
    this->setWindowIcon(QIcon(":/Interface.png"));
    this->setWindowTitle("PLC_Interface  ——XUN");

    ui->user_text->setPlaceholderText("请输入账号");
    ui->psw_text->setPlaceholderText("请输入密码");

    ui->user->setStyleSheet("color:#FFFFFF");
    ui->password->setStyleSheet("color:#FFFFFF");

    ui->user_text->setStyleSheet("border-radius:5px;");
    ui->psw_text->setStyleSheet("border-radius:5px;");

    ui->clear_btn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    ui->clear_btn->setStyleSheet("border-radius:3px;border:1px solid #aaffff; border-style: outset;color:#FFFFFF;");

    ui->close_btn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    ui->close_btn->setStyleSheet("border-radius:3px;border:1px solid #aaffff; border-style: outset;color:#FFFFFF;");


    ui->login_btn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    ui->login_btn->setStyleSheet("border-radius:3px;border:1px solid #aaffff; border-style: outset;color:#FFFFFF;");

    ui->register_btn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    ui->register_btn->setStyleSheet("border-radius:3px;border:1px solid #aaffff; border-style: outset;color:#FFFFFF;");

    registers *Registers = new registers();
    NewWidget *newWidget = new NewWidget();

    connect(ui->register_btn,&QToolButton::clicked,[=](){
        ofstream in_Record_File("Record.txt",ios::app);
        string record = "从登录页面进入注册页面,";
        QDateTime sys_time = QDateTime::currentDateTime();
        string current_date = sys_time.toString("yyyy.MM.dd - hh:mm:ss - ddd\n").toStdString();
        in_Record_File<<record<<current_date;
        in_Record_File.close();

        this->hide();
        Registers->show();
    });

    connect(Registers,&registers::back,[=](){
        Registers->hide();
        this->show();
    });

    connect(newWidget,&NewWidget::back,[=](){
        newWidget->hide();
        this->show();
    });

    connect(ui->login_btn,&QToolButton::clicked,[=](){
        bool Bool = false;
        string user;
        ifstream readFile("Register.txt");
        if(((ui->user_text->text()=="")||(ui->psw_text->text()=="")))
        {
            QMessageBox::critical(this,"错误","请输入用户名及密码！");
        }
        else
        {
            string temp;
            while(getline(readFile, temp, '\n'))
            {
                QString str = QString::fromStdString(temp);
                QStringList list = str.split(",");
                QString str1 = list[0];
                QString str2 = list[1];
                if(str1==ui->user_text->text()&&str2==ui->psw_text->text())
                {
                    Bool = true;
                    user = ui->user_text->text().toStdString();
                }
            }

            if(Bool)
            {
                ofstream in_Record_File("Record.txt",ios::app);
                string record = "用户 "+user+" 成功登录系统,";
                QDateTime sys_time = QDateTime::currentDateTime();
                string current_date = sys_time.toString("yyyy.MM.dd - hh:mm:ss - ddd\n").toStdString();
                in_Record_File<<record<<current_date;
                in_Record_File.close();

                this->hide();
                newWidget->show();
            }
            else
            {
                QMessageBox::critical(this,"错误","登录失败，账号或者密码错误！");
            }
            readFile .close();
        }
    });

    connect(ui->clear_btn,&QToolButton::clicked,[=](){
        ofstream in_Record_File("Record.txt",ios::app);
        string record = "清除登录页面信息,";
        QDateTime sys_time = QDateTime::currentDateTime();
        string current_date = sys_time.toString("yyyy.MM.dd - hh:mm:ss - ddd\n").toStdString();
        in_Record_File<<record<<current_date;
        in_Record_File.close();

        ui->user_text->setText("");
        ui->psw_text->setText("");
    });

    connect(ui->close_btn, &QToolButton::clicked,[=](){
        int ret;
        ret = QMessageBox::question(this,"退出","你是否确定退出系统？？？",QMessageBox::Yes,QMessageBox::No);
        if(ret == QMessageBox::Yes)
        {
            ofstream in_Record_File("Record.txt",ios::app);
            string record = "从登录页面退出系统,";
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

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    static int x = 0;
    static int y = 0;

    QPainter *painter = new QPainter(this);
    QPixmap pix;
    pix.load(":/web.jpg");
    painter->drawPixmap(x,y,this->width(),this->height(),pix);
}
