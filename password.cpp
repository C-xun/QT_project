#include "password.h"
#include "ui_password.h"
#include <iostream>
#include <vector>
#include <time.h>
#include <QMessageBox>
#include <QPushButton>

using namespace std;

Password::Password(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Password)
{
    ui->setupUi(this);

    srand(time(NULL));
    vector<string> Static_psw;
    Static_psw.push_back("000");
    Static_psw.push_back("111");
    Static_psw.push_back("222");
    Static_psw.push_back("333");
    Static_psw.push_back("444");
    Static_psw.push_back("555");
    Static_psw.push_back("666");
    Static_psw.push_back("777");
    Static_psw.push_back("888");
    Static_psw.push_back("999");
    random_shuffle(Static_psw.begin(), Static_psw.end());
    int psw = rand()%10;

    ui->lineEdit->setText(QString::fromStdString(Static_psw[psw]));

    connect(ui->pushButton,&QPushButton::clicked,[=](){
        int psw = rand()%10;
        ui->lineEdit->setText(QString::fromStdString(Static_psw[psw]));
    });

    connect(ui->pushButton_2,&QPushButton::clicked,[=](){
        if(ui->lineEdit_2->text()==""||ui->lineEdit_3->text()==""||ui->lineEdit_4->text()==""||ui->lineEdit_5->text()=="")
        {
            QMessageBox::critical(this,"错误","请填写完所有信息！");
        }
        else{
            if(ui->lineEdit->text()!=ui->lineEdit_3->text())
            {
                QMessageBox::critical(this,"错误","请保存两次静态码一致！");
            }
            else if(ui->lineEdit_2->text()!=ui->lineEdit_4->text())
            {
                QMessageBox::critical(this,"错误","请保存两次安全码一致！");
            }
            else if(ui->lineEdit_5->text()!=(ui->lineEdit_3->text()+ui->lineEdit_4->text()))
            {
                QMessageBox::critical(this,"错误","请确保密码由静态码和安全码合成！");
            }
            else if(ui->lineEdit_5->text()==(ui->lineEdit_3->text()+ui->lineEdit_4->text()))
            {
                QMessageBox::information(this,"恭喜","密码修改成功！");
            }
        }
    });
}

Password::~Password()
{
    delete ui;
}
