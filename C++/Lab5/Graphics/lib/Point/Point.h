#ifndef POINT_H
#define POINT_H

#include <iostream>

using namespace std;

class Point
{
    int x;
    int y;

public:
    Point();
    Point(int x1, int y1) : x(x1), y(y1)
    {
        cout << "At Point Const.";
    }

    void setX(int m);
    void setY(int n);

    int getX();
    int getY();
};

#endif