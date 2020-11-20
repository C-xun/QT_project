#include "maindebug.h"
#include "ui_maindebug.h"
#include <QToolBar>
#include <QToolButton>
#include <QPushButton>

MainDebug::MainDebug(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainDebug)
{
    ui->setupUi(this);
    this->setFixedSize(800,600);

    QToolBar *toolBar = new QToolBar(this);
    this->addToolBar(toolBar);

    toolBar->setFloatable(false);
    toolBar->setAllowedAreas(Qt::TopToolBarArea);

    QToolButton *toolBtn1 = new QToolButton(this);
    toolBtn1->setIcon(QIcon(":/open.png"));
    toolBtn1->setFixedSize(25,25);
    toolBar->addWidget(toolBtn1);

    QToolButton *toolBtn2 = new QToolButton(this);
    toolBtn2->setIcon(QIcon(":/close.png"));
    toolBtn2->setFixedSize(25,25);
    toolBar->addWidget(toolBtn2);

    toolBar->addSeparator();

    QToolButton *toolBtn3 = new QToolButton(this);
    toolBtn3->setIcon(QIcon(":/add.png"));
    toolBtn3->setFixedSize(25,25);
    toolBar->addWidget(toolBtn3);

    QToolButton *toolBtn4 = new QToolButton(this);
    toolBtn4->setIcon(QIcon(":/clear.png"));
    toolBtn4->setFixedSize(25,25);
    toolBar->addWidget(toolBtn4);

    QToolButton *toolBtn5 = new QToolButton(this);
    toolBtn5->setIcon(QIcon(":/write.png"));
    toolBtn5->setFixedSize(25,25);
    toolBar->addWidget(toolBtn5);

    QToolButton *toolBtn6 = new QToolButton(this);
    toolBtn6->setIcon(QIcon(":/read.png"));
    toolBtn6->setFixedSize(25,25);
    toolBar->addWidget(toolBtn6);

    QToolButton *toolBtn7 = new QToolButton(this);
    toolBtn7->setIcon(QIcon(":/keep.png"));
    toolBtn7->setFixedSize(25,25);
    toolBar->addWidget(toolBtn7);

    toolBar->addSeparator();

    QToolButton *toolBtn8 = new QToolButton(this);
    toolBtn8->setIcon(QIcon(":/num.png"));
    toolBtn8->setFixedSize(25,25);
    toolBar->addWidget(toolBtn8);

    QToolButton *toolBtn9 = new QToolButton(this);
    toolBtn9->setIcon(QIcon(":/time.png"));
    toolBtn9->setFixedSize(25,25);
    toolBar->addWidget(toolBtn9);

    toolBar->addSeparator();

    QToolButton *toolBtn10 = new QToolButton(this);
    toolBtn10->setIcon(QIcon(":/exit.png"));
    toolBtn10->setFixedSize(25,25);
    toolBar->addWidget(toolBtn10);

    connect(ui->clear_btn,&QToolButton::clicked,[=](){
        ui->textEdit->clear();
    });

    connect(ui->pushButton_2,&QToolButton::clicked,[=](){
        QString str = ui->lineEdit->text();
        ui->textEdit->setText(str);
        ui->lineEdit->clear();
    });
}

MainDebug::~MainDebug()
{
    delete ui;
}
