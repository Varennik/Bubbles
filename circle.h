#ifndef CIRCLE_H
#define CIRCLE_H

class Circle
{
    int x;
    int y;
    int xd;
    int yd;
    bool alive = true;
    int colorR;
    int colorG;
    int colorB;
    int radius;

public:
    Circle();
    Circle(int x, int y, int xd, int yd);
    void setCoordinates(int x, int y);
    void setVector(int xd,int yd);
    void setAlive(bool alive);
    void setColor(int r, int g, int b);
    void setRadius(int radius);
    int getX();
    int getY();
    int getXd();
    int getYd();
    bool getAlive();
    int getColorR();
    int getColorG();
    int getColorB();
    int getRadius();
};

#endif // CIRCLE_H
