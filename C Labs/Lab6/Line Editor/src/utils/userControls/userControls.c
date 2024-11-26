#ifndef USER_CONTROLS_C
#define USER_CONTROL_C

#include <stdio.h>
#include "../../lib/defines.h"
#include "../../lib/conio.h"

char userControlsGetInputChar()
{
    char userInputChar = getch();

    if (userInputChar == KEY_EXTEND)
    {
        if (kbhit())
        {
            getch();
            userInputChar = getch();
            return userInputChar;
        }
        // for return if ESC key
        else return userInputChar;
        
        return userInputChar;
    }
    
    return userInputChar;
}

#endif