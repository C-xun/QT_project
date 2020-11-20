#include "index.h"
#include "ui_index.h"
#include <QPainter>

Index::Index(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Index)
{
    ui->setupUi(this);
}

Index::~Index()
{
    delete ui;
}

void Index::paintEvent(QPaintEvent *event)
{
    static int x = 0;
    static int y = 0;

    QPainter *painter = new QPainter(this);
    QPixmap pix;
    pix.load(":/background.png");
    painter->drawPixmap(x,y,this->width(),this->height(),pix);
}
