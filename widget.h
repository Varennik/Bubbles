#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPaintEvent>
#include <QTimerEvent>
#include <QMouseEvent>
#include <QTimer>

#include "circle.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    void mousePressEvent(QMouseEvent *event);
    void timerEvent(QTimerEvent *event);
    void paintEvent(QPaintEvent *);

    int timerForDraw;

    int num;
    Circle* mass;

    int releaseBubbles;
    bool gameOver;

    int timerForGameOver;
    int secondForGameOver;

private slots:
    void on_pushButton_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
