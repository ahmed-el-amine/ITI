#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
#include "graphics.h"
#include "../Point/Point.h"
#include "../Shape/Shape.h"

using namespace std;

class Circle : public Shape
{
private:
    Point center;
    int radius;

public:
    Circle() : center()
    {
        radius = 0;
        cout << "At Circle Const.";
    }

    Circle(int m, int n, int r) : center(m, n)
    {
        radius = r;
        cout << "At Circle Const.";
    }

    void draw()
    {
        setcolor(this->getColor());
        circle(center.getX(), center.getY(), radius);
    }
};

#endif