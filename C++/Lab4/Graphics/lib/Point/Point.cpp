#ifndef POINT_C
#define POINT_C

#include "./Point.h"

void Point::setX(int m)
{
    this->x = m;
}

void Point::setY(int n)
{
    this->y = n;
}

int Point::getX()
{
    return this->x;
}

int Point::getY()
{
    return this->y;
}

#endif