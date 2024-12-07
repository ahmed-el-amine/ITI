#ifndef PICTURE_C
#define PICTURE_C

#include "./Picture.h"

void Picture::setCircles(int cn, Circle *cptr)
{
    cNum = cn;
    pCircles = cptr;
}

void Picture::setRects(int rn, Rect *rptr)
{
    rNum = rn;
    pRects = rptr;
}

void Picture::setLines(int ln, Line *lptr)
{
    lNum = ln;
    pLines = lptr;
}

void Picture::paint()
{
    int i;

    for (i = 0; i < cNum; i++)
    {
        pCircles[i].draw();
    }

    for (i = 0; i < rNum; i++)
    {
        pRects[i].draw();
    }

    for (i = 0; i < lNum; i++)
    {
        pLines[i].draw();
    }
}

#endif