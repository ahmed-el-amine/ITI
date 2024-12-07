#ifndef PICTURE_H
#define PICTURE_H

#include <iostream>
#include "../Circle/Circle.h"
#include "../Rect/Rect.h"
#include "../Line/Line.h"

using namespace std;

class Picture
{
    int cNum;
    int rNum;
    int lNum;
    Circle *pCircles;
    Rect *pRects;
    Line *pLines;

public:
    Picture()
    {
        cNum = 0;
        rNum = 0;
        lNum = 0;
        pCircles = NULL;
        pRects = NULL;
        pLines = NULL;
    }

    Picture(int cn, int rn, int ln, Circle *pC, Rect *pR, Line *pL)
    {
        cNum = cn;
        rNum = rn;
        lNum = ln;
        pCircles = pC;
        pRects = pR;
        pLines = pL;
    }

    void setCircles(int, Circle *);
    void setRects(int, Rect *);
    void setLines(int, Line *);
    void paint();
};

#endif