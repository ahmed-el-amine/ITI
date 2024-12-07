#ifndef RECT_H
#define RECT_H

#include <iostream>
#include "graphics.h"
#include "../Point/Point.h"
#include "../Shape/Shape.h"

using namespace std;

class Rect : public Shape
{
private:
    Point ul;
    Point lr;

public:
    Rect() : ul(), lr()
    {
        cout << "At Rect Count.";
    }

    Rect(int x1, int y1, int x2, int y2) : ul(x1, y1), lr(x2, y2)
    {
        cout << "At Rect Const.";
    }

    void draw()
    {
        setcolor(this->getColor());
        rectangle(ul.getX(), ul.getY(), lr.getX(), lr.getY());
    }
};

#endif