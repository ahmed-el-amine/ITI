#ifndef LINE_H
#define LINE_H

#include <iostream>
#include "graphics.h"
#include "../Point/Point.h"

using namespace std;

class Line
{
    Point start;
    Point end;

public:
    Line() : start(), end()
    {
        cout << "At line Const.";
    }

    Line(int x1, int y1, int x2, int y2) : start(x1, y1), end(x2, y2)
    {
        cout << "At line Const.";
    }

    void draw()
    {
        line(start.getX(), start.getY(), end.getX(), end.getY());
    }
};

#endif