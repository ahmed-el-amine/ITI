#ifndef HANDLEINPUTS_H
#define HANDLEINPUTS_H

#include <stdio.h>
#include "./conio.h"
#include "defines.h"

/// @brief This function escape un nedded char for menu controls
/// @return char
char getKey_Char()
{
    char c = getch();

    if (c == KEY_EXTEND)
    {
        if (kbhit())
        {
            getch();
            c = getch();
            return c;
        }
        else
            return c;
    }
    return c;
}

#endif