#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define MAXOPTIONS 3
#define UP 72
#define DOWN 80
#define RIGHT 77
#define LEFT 75
#define ENTER 13
#define ESC 27

#define clear() printf("\033[H\033[J")

// Define text colors using ANSI escape sequences
typedef enum TextColor {
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
    "\033[97m"
};

// Set terminal text color
void setTextColor(TextColor color) {
    fprintf(stdout, "%s", ansiColorSequences[color]);
}

void showMenu(char userCh, int selected, char pressEnter)
{
    clear();

    setTextColor(TC_YELLOW);

    printf("Please select an option: \n");
    printf("You Can Exit Using ESC Key \n\n");

    setTextColor(TC_WHITE);

    if (pressEnter != 0)
    {
        setTextColor(TC_GREEN);

        if (selected == 1)printf("New \n");
        if (selected == 2)printf("Display \n");
        if (selected == 3)printf("Exit \n");
    }
    else
    {
        for (int i = 1; i <= MAXOPTIONS; i++)
        {
            if (i == selected) {
                setTextColor(TC_GREEN);
                printf("-> ");
            }
            else setTextColor(TC_WHITE);

            if (i == 1) printf("New \n");
            if (i == 2) printf("Display \n");
            if (i == 3) printf("Exit \n");
        }
    }

}

int handleSelectRange(int selectRange) {
    if (selectRange < 1) return MAXOPTIONS;
    if (selectRange > MAXOPTIONS) return 1;
    return selectRange;
}

int main()
{
    int selected = 1;
    char userCh = 0;
    char pressEnter = 0;

    showMenu(userCh, selected, 0);

    while (1)
    {
        userCh = getch();
        char isValidClick = 1;
        switch (userCh)
        {
            case UP:
            case LEFT:
                if (pressEnter) break;
                selected -= 1;
                selected = handleSelectRange(selected);
                break;
            case DOWN:
            case RIGHT:
                if (pressEnter) break;
                selected += 1;
                selected = handleSelectRange(selected);
                break;
            case ENTER:
                pressEnter = 1;
                break;
            case ESC:
                if (pressEnter) pressEnter = 0;
                else return;
                break;
            default:
                isValidClick = 0;
                break;
        }

        if (isValidClick) showMenu(userCh, selected, pressEnter);
    }

    return 0;
}
