#ifndef PICTURE_H
#define PICTURE_H

#include "graphics.h"

class Point
{
private:
    int x, y;

public:
    Point() : x(0), y(0) {}
    Point(int x1, int y1) : x(x1), y(y1) {}

    int getX() { return x; }
    int getY() { return y; }
};

class Line
{
private:
    Point start;
    Point end;

public:
    Line() : start(), end() {}
    Line(int x1, int y1, int x2, int y2) : start(x1, y1), end(x2, y2) {}

    void draw()
    {
        line(start.getX(), start.getY(), end.getX(), end.getY());
    }
};

class Rect
{
private:
    Point ul; // Upper-left point
    Point lr; // Lower-right point
public:
    Rect() : ul(), lr() {}
    Rect(int x1, int y1, int x2, int y2) : ul(x1, y1), lr(x2, y2) {}

    void draw()
    {
        rectangle(ul.getX(), ul.getY(), lr.getX(), lr.getY());
    }
};

class Circle
{
private:
    Point center;
    int radius;

public:
    Circle() : center(), radius(0) {}
    Circle(int m, int n, int r) : center(m, n), radius(r) {}

    void draw()
    {
        circle(center.getX(), center.getY(), radius);
    }
};

class Picture
{
private:
    int cNum, rNum, lNum;
    Circle *pCircles;
    Rect *pRects;
    Line *pLines;

public:
    Picture() : cNum(0), rNum(0), lNum(0), pCircles(nullptr), pRects(nullptr), pLines(nullptr) {}

    void setCircles(int cn, Circle *pC)
    {
        cNum = cn;
        pCircles = pC;
    }

    void setRects(int rn, Rect *pR)
    {
        rNum = rn;
        pRects = pR;
    }

    void setLines(int ln, Line *pL)
    {
        lNum = ln;
        pLines = pL;
    }

    void paint()
    {
        for (int i = 0; i < cNum; i++)
        {
            pCircles[i].draw();
        }
        for (int i = 0; i < rNum; i++)
        {
            pRects[i].draw();
        }
        for (int i = 0; i < lNum; i++)
        {
            pLines[i].draw();
        }
    }
};

#endif // PICTURE_H