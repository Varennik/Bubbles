#include "circle.h"

Circle::Circle()
{
}

Circle::Circle(int x, int y, int xd, int yd)
{
    this->x = x;
    this->y = y;
    this->xd = xd;
    this->yd = yd;
}

void Circle::setCoordinates(int x, int y)
{
    this->x = x;
    this->y = y;
}

void Circle::setVector(int xd, int yd)
{
    this->xd = xd;
    this->yd = yd;
}

void Circle::setAlive(bool alive)
{
    this->alive = alive;
}

void Circle::setColor(int r, int g, int b)
{
    this->colorR = r;
    this->colorG = g;
    this->colorB = b;
}

void Circle::setRadius(int radius)
{
    this->radius = radius;
}

int Circle::getX()
{
    return this->x;
}

int Circle::getY()
{
    return this->y;
}

int Circle::getXd()
{
    return this->xd;
}

int Circle::getYd()
{
    return this->yd;
}

bool Circle::getAlive()
{
    return this->alive;
}

int Circle::getColorR()
{
    return this->colorR;
}

int Circle::getColorG()
{
    return this->colorG;
}

int Circle::getColorB()
{
    return this->colorB;
}

int Circle::getRadius()
{
    return this->radius;
}
