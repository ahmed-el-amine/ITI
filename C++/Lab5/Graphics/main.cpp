#include <iostream>
#include "graphics.h"

#include "./lib/Circle/Circle.h"

#include "./lib/Line/Line.h"

#include "./lib/Picture/Picture.h"
#include "./lib/Picture/Picture.cpp"

#include "./lib/Point/Point.h"
#include "./lib/Point/Point.cpp"

#include "./lib/Rect/Rect.h"

using namespace std;

int main()
{
    // run with command { g++ main.cpp -lSDL_bgi -lSDL2 && ./a.out }
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    Picture myPic;

    Circle c1(50, 50, 50);
    Circle c2(200, 100, 100);
    Circle c3(420, 50, 30);
    c1.setColor(YELLOW_NEW);
    c2.setColor(YELLOW_NEW);
    c3.setColor(YELLOW_NEW);
    Circle cArr[3] = {c1, c2, c3};

    Rect r1(30, 40, 170, 100);
    Rect r2(420, 50, 500, 300);
    r1.setColor(CYAN_NEW);
    r2.setColor(CYAN_NEW);
    Rect rArr[2] = {r1, r2};

    Line l1(420, 50, 300, 300);
    Line l2(40, 500, 500, 400);

    l1.setColor(GREEN_NEW);
    l2.setColor(GREEN_NEW);

    Line lArr[2] = {l1, l2};

    myPic.setCircles(3, cArr);
    myPic.setRects(2, rArr);
    myPic.setLines(2, lArr);

    myPic.paint();

    getch();
    closegraph();

    return 0;
}