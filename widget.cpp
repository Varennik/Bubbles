#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QTimer>
#include <time.h>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    num = 200;
    mass = new Circle[num];
    releaseBubbles = 0;

    srand(time(0));
    gameOver = false;

    ui->pushButton->setHidden(true);

    for(int k = 0;k < num; k++)
    {
        int x = rand()%(width()-30);
        int y = rand()%(height()-30);
        int xd, yd;
        do {
            xd = rand()%11-5;
            yd = rand()%11-5;
        } while(xd == 0 && yd == 0);

        int r = rand()%256;
        int g = rand()%256;
        int b = rand()%256;

        int radius = rand()%51+50;

        mass[k].setCoordinates(x, y);
        mass[k].setVector(xd, yd);
        mass[k].setColor(r, g, b);
        mass[k].setRadius(radius);
    }
    timerForDraw = startTimer(15);

    timerForGameOver = startTimer(1000);
    secondForGameOver = 10;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    int x = event->x();
    int y = event->y();

    for(int k = 0; k < num; k++)
    {
        if(mass[k].getX() < x && x < mass[k].getX() + mass[k].getRadius())
            if(mass[k].getY() < y && y < mass[k].getY() + mass[k].getRadius())
                if(mass[k].getAlive())
                {
                    mass[k].setAlive(false);
                    releaseBubbles++;
                }
    }
}

void Widget::timerEvent(QTimerEvent *event)
{
    int timerId = event->timerId();
    if(timerId == timerForDraw)
    {
        if(releaseBubbles >= num)
        {
            gameOver = true;
            ui->pushButton->setHidden(false);
        }

        for (int k = 0; k < num; k++)
        {
            int NewX = mass[k].getX() + mass[k].getXd();
            int NewY = mass[k].getY() + mass[k].getYd();

            mass[k].setCoordinates(NewX, NewY);

             if (mass[k].getX() > (width()-30))
                 mass[k].setVector(0-mass[k].getXd(), mass[k].getYd());

             if (mass[k].getY() > (height()-30))
                 mass[k].setVector(mass[k].getXd(), 0-mass[k].getYd());

             if (mass[k].getX() < 0)
                 mass[k].setVector(0-mass[k].getXd(), mass[k].getYd());

             if (mass[k].getY() < 0)
                 mass[k].setVector(mass[k].getXd(), 0-mass[k].getYd());
        }
    }
    else if(timerId == timerForGameOver)
    {
        secondForGameOver--;
        if(secondForGameOver == 0)
        {
            gameOver = true;
            ui->pushButton->setHidden(false);
        }
    }

    update();
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter p(this);

    if(gameOver)
    {
        p.drawText(400,300,"Game Over");
        p.drawText(400,310,QString("You Kill %1 Bubbles").arg(releaseBubbles));
    }
    else
    {
        for (int k = 0;k < num; k++)
        {
            if(mass[k].getAlive())
            {
                int r = mass[k].getColorR();
                int g = mass[k].getColorG();
                int b = mass[k].getColorB();
                p.setBrush(QColor(r, g, b));
                p.drawEllipse(mass[k].getX(), mass[k].getY(), mass[k].getRadius(), mass[k].getRadius());
            }
        }
        p.drawText(20,20,QString("%1").arg(releaseBubbles));
        p.drawText(20,30,QString("Time: %1").arg(secondForGameOver));
    }
}


void Widget::on_pushButton_clicked()
{
    ui->pushButton->setHidden(true);
    gameOver = false;

    releaseBubbles = 0;
    secondForGameOver = 10;
    for(int k = 0; k < num; k++)
    {
        mass[k].setAlive(true);
    }
}
