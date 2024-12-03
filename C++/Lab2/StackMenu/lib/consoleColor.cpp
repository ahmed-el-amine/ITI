#ifndef CONSOLECOLOR_H
#define CONSOLECOLOR_H

#include <stdio.h>

// Define text colors using ANSI escape sequences
typedef enum TextColor
{
    TC_BLACK = 0,
    TC_BLUE,
    TC_GREEN,
    TC_CYAN,
    TC_RED,
    TC_MAGENTA,
    TC_BROWN,
    TC_LIGHTGRAY,
    TC_DARKGRAY,
    TC_LIGHTBLUE,
    TC_LIGHTGREEN,
    TC_LIGHTCYAN,
    TC_LIGHTRED,
    TC_LIGHTMAGENTA,
    TC_YELLOW,
    TC_WHITE
} TextColor;

// ANSI escape sequences for colors
static const char *ansiColorSequences[] = {
    "\033[30m", "\033[34m", "\033[32m", "\033[36m", "\033[31m",
    "\033[35m", "\033[33m", "\033[37m", "\033[90m", "\033[94m",
    "\033[92m", "\033[96m", "\033[91m", "\033[95m", "\033[93m",
    "\033[97m"};

// Set terminal text color
void setTextColor(TextColor color)
{
    fprintf(stdout, "%s", ansiColorSequences[color]);
}
#endif