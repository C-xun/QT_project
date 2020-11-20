#include "record.h"
#include "ui_record.h"
#include <QDateTime>
#include <iostream>
#include <fstream>
#include <QTimer>

using namespace std;

Record::Record(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Record)
{
    ui->setupUi(this);

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    QHeaderView* headerView = ui->tableWidget->verticalHeader();
    headerView->setHidden(true);
    ui->tableWidget->setRowCount(100);

    this->id = this->startTimer(5000);

}

Record::~Record()
{
    delete ui;
}

void Record::timerEvent(QTimerEvent *event)
{
    if(event->timerId()==this->id)
    {
        ui->tableWidget->clearContents();
        int row = 0;
        string tmp;
        ifstream in_Record_File("Record.txt",ios::in);
        while(getline(in_Record_File, tmp, '\n'))
        {
            QString str = QString::fromStdString(tmp);
            QStringList list = str.split(",");
            QString str1 = list[0];
            QString str2 = list[1];
            ui->tableWidget->setItem(row,0,new QTableWidgetItem(str1));
            ui->tableWidget->setItem(row,1,new QTableWidgetItem(str2));
            row++;
            if(row>=100)
            {
                ofstream clear_File("Record.txt");
            }
        }
        row = 0;
    }
}
