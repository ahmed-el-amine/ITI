#ifndef SHAPE_C
#define SHAPE_C

typedef enum ShapeColors
{
    BLACK_NEW = 0,
    EGA_BLACK_NEW = 0,
    BLUE_NEW = 1,
    EGA_BLUE_NEW = 1,
    GREEN_NEW = 2,
    CGA_GREEN_NEW = 2,
    EGA_GREEN_NEW = 2,
    CYAN_NEW = 3,
    CGA_CYAN_NEW = 3,
    EGA_CYAN_NEW = 3,
    RED_NEW = 4,
    CGA_RED_NEW = 4,
    EGA_RED_NEW = 4,
    MAGENTA_NEW = 5,
    CGA_MAGENTA_NEW = 5,
    EGA_MAGENTA_NEW = 5,
    BROWN_NEW = 6,
    CGA_BROWN_NEW = 6,
    EGA_BROWN_NEW = 6,
    LIGHTGRAY_NEW = 7,
    CGA_LIGHTGRAY_NEW = 7,
    EGA_LIGHTGRAY_NEW = 7,
    DARKGRAY_NEW = 8,
    EGA_DARKGRAY_NEW = 8,
    LIGHTBLUE_NEW = 9,
    EGA_LIGHTBLUE_NEW = 9,
    LIGHTGREEN_NEW = 10,
    CGA_LIGHTGREEN_NEW = 10,
    EGA_LIGHTGREEN_NEW = 10,
    LIGHTCYAN_NEW = 11,
    CGA_LIGHTCYAN_NEW = 11,
    EGA_LIGHTCYAN_NEW = 11,
    LIGHTRED_NEW = 12,
    CGA_LIGHTRED_NEW = 12,
    EGA_LIGHTRED_NEW = 12,
    LIGHTMAGENTA_NEW = 13,
    CGA_LIGHTMAGENTA_NEW = 13,
    EGA_LIGHTMAGENTA_NEW = 13,
    YELLOW_NEW = 14,
    CGA_YELLOW_NEW = 14,
    EGA_YELLOW_NEW = 14,
    WHITE_NEW = 15,
    CGA_WHITE_NEW = 15,
    EGA_WHITE_NEW = 15,
    MAXCOLORS_NEW = 15

} ShapeColors;

class Shape
{
    ShapeColors Color;

public:
    ShapeColors getColor()
    {
        return this->Color;
    }

    void setColor(ShapeColors color)
    {
        this->Color = color;
    }

    Shape()
    {
        Color = ShapeColors::WHITE_NEW;
    }
};

#endif