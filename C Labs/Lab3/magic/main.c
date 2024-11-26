#ifdef _WIN32
    #include <windows.h>
    #define SLEEP_MS(x) Sleep(x)
    #define CLEAR_SCREEN system("cls")
#else
    #include <unistd.h>
    #define SLEEP_MS(x) usleep(x * 1000)
    #define CLEAR_SCREEN system("clear")
#endif

#include <stdio.h>

#define MS 500

void gotoxy(int x, int y) {
    printf("\033[%d;%dH", y, x);
}

int increment(int size, int current) {
    return (current + 1) % size;
}

int decrement(int size, int current) {
    return (current - 1 + size) % size;
}

int main() {
    int size = 0;

    while(size % 2 == 0 || size < 1)
    {
        printf("Enter the size of magic square (odd number): ");
        scanf("%d", &size);
    }


    int startX = 0;
    int startY = 3;


    int row = 0, col = size / 2;

    gotoxy(startX + col * 4, startY + row);

    SLEEP_MS(MS);

    printf("%d", 1);

    for (int i = 2; i <= size * size; i++)
    {
        if ((i-1) % size != 0)
        {
            row = decrement(size, row);
            col = decrement(size, col);
        }
        else row = increment(size, row);


        SLEEP_MS(MS);

        gotoxy(startX + col * 4, startY + row);

        SLEEP_MS(MS);

        if (i % 2 == 0) printf("%d", i);
        else printf("%d", i);
    }

    // Move cursor below the box
    gotoxy(1, startY + size + 2);

    return 0;
}


/*
#ifdef _WIN32
    #include <windows.h>
    #define SLEEP_MS(x) Sleep(x)
    #define CLEAR_SCREEN system("cls")
#else
    #include <unistd.h>
    #define SLEEP_MS(x) usleep(x * 1000)
    #define CLEAR_SCREEN system("clear")
#endif

#include <stdio.h>

#ifdef _WIN32
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x - 1;
    coord.Y = y - 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
#else
void gotoxy(int x, int y) {
    printf("\033[%d;%dH", y, x);
}
#endif

int increment(int size, int current) {
    return (current + 1) % size;
}

int decrement(int size, int current) {
    return (current - 1 + size) % size;
}

void drawBox(int x, int y, int size) {
    // Draw top border
    gotoxy(x-1, y-1);
    printf("+");
    for(int i = 0; i < size*4; i++) printf("-");
    printf("+");

    // Draw side borders
    for(int i = 0; i < size; i++) {
        gotoxy(x-1, y+i);
        printf("|");
        gotoxy(x+size*4, y+i);
        printf("|");
    }

    // Draw bottom border
    gotoxy(x-1, y+size);
    printf("+");
    for(int i = 0; i < size*4; i++) printf("-");
    printf("+");
    fflush(stdout);
}

void showStep(int x, int y, int num, int row, int col, int size) {
    gotoxy(1, y + size + 3);
    printf("Step %d: Placing %d at position (row=%d, col=%d)   ", num, num, row + 1, col + 1);

    gotoxy(1, y + size + 4);
    if (num > 1) {
        if ((num-1) % size != 0) {
            printf("Moving: UP and LEFT     ");
        } else {
            printf("Moving: DOWN one step   ");
        }
    }
    fflush(stdout);
}

int main() {
    int size;

    printf("Enter the size of magic square (odd number): ");
    scanf("%d", &size);

    if (size % 2 == 0 || size < 1) {
        printf("Please enter an odd number greater than 0\n");
        return 1;
    }

    CLEAR_SCREEN;

    // Starting position for the box
    int startX = 5;
    int startY = 3;

    // Draw the box first
    drawBox(startX, startY, size);

    // Add header
    gotoxy(startX, startY - 2);
    printf("Magic Square Animation (size: %d x %d)", size, size);

    int row = 0, col = size / 2;

    // Print first number with animation
    showStep(startX, startY, 1, row, col, size);
    gotoxy(startX + col*4, startY + row);
    printf("%3d", 1);
    fflush(stdout);
    SLEEP_MS(1000);

    for (int i = 2; i <= size * size; i++) {
        if ((i-1) % size != 0) {
            row = decrement(size, row);
            col = decrement(size, col);
        } else {
            row = increment(size, row);
        }

        showStep(startX, startY, i, row, col, size);

        gotoxy(startX + col*4, startY + row);
        printf("%3d", i);
        fflush(stdout);

        SLEEP_MS(1000);
    }

    // Final position
    gotoxy(1, startY + size + 5);
    printf("Magic Square completed!\n");

    return 0;
}
*/
