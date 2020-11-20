#include "classifier.h"
#include "ui_classifier.h"
#include <QPushButton>
#include <iostream>
#include <fstream>
#include <QMessageBox>

using namespace std;

Classifier::Classifier(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Classifier)
{
    ui->setupUi(this);

    connect(ui->add_btn,&QPushButton::clicked,[=](){
        QString str1 = ui->lineEdit->text();
        if(str1!="")
        {
             bool Bool = true;
             ifstream Classifier_File("Classifier.txt",ios::in);
             string tmp;
             while(getline(Classifier_File, tmp, '\n'))
             {
                 QString str = QString::fromStdString(tmp);
                     if(str==str1){
                         QMessageBox::critical(this,"错误","抱歉分类器已存在！");
                         Bool = false;
                         break;
                     }
             }
             if(Bool){
                 ofstream Classifier_File("Classifier.txt",ios::app);
                 Classifier_File<<(str1+"\n").toStdString();
                 Classifier_File.close();

                 QMessageBox::information(this,"恭喜","分类器添加成功！");
             }
             Classifier_File.close();
        }
        else{
            QMessageBox::critical(this,"错误","抱歉您的分类器名为空！");
        }
    });

    connect(ui->delete_btn,&QPushButton::clicked,[=](){
        QString str1 = ui->lineEdit->text();
        if(str1!="")
        {
             bool Bool = false;
             int del_line = 1;
             ifstream Classifier_File("Classifier.txt",ios::in);
             string tmp;
             while(getline(Classifier_File, tmp, '\n'))
             {
                 QString str = QString::fromStdString(tmp);
                     if(str==str1){
                         Bool = true;
                         break;
                     }
                     del_line++;
             }
             Classifier_File.close();

             if(Bool){
                 ifstream in;
                 in.open("Classifier.txt");

                 string strFileData = "";
                 int line = 1;
                 char lineData[1024] = {0};
                 while(in.getline(lineData, sizeof(lineData)))
                 {
                     if (line==del_line)
                     {
                         strFileData += "\n";
                     }
                     else
                     {
                         strFileData += lineData;
                         strFileData += "\n";
                     }
                     line++;
                 }

                 ofstream out;
                 out.open("Classifier.txt");
                 out.flush();
                 out<<strFileData;
                 out.close();
                 QMessageBox::information(this,"信息","删除成功！当前分类器已删除");
             }
             else{
                 QMessageBox::critical(this,"错误","抱歉您的分类器不存在！");
             }
        }
        else{
            QMessageBox::critical(this,"错误","抱歉您的分类器名为空！");
        }
    });


    connect(ui->query_btn,&QPushButton::clicked,[=](){
        QString str1 = ui->lineEdit->text();
        if(str1!="")
        {
             bool Bool = false;
             ifstream Classifier_File("Classifier.txt",ios::in);
             string tmp;
             while(getline(Classifier_File, tmp, '\n'))
             {
                 QString str = QString::fromStdString(tmp);
                     if(str==str1){
                         Bool = true;
                         break;
                     }
             }
             Classifier_File.close();

             if(Bool){
                 QMessageBox::information(this,"信息","查询成功！存在当前分类器");
             }
             else{
                 QMessageBox::critical(this,"错误","抱歉您的分类器不存在！");
             }
        }
        else{
            QMessageBox::critical(this,"错误","抱歉您的分类器名为空！");
        }
    });


}

Classifier::~Classifier()
{
    delete ui;
}
