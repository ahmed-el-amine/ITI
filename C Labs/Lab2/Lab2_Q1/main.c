#include <stdio.h>

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

    printf("%d", 1);

    for (int i = 2; i <= size * size; i++) {
        if ((i-1) % size != 0)
        {
            row = decrement(size, row);
            col = decrement(size, col);
        }
        else row = increment(size, row);


        gotoxy(startX + col * 4, startY + row);

        if (i % 2 == 0) printf("%d", i);
        else printf("%d", i);
    }

    // Move cursor below the box
    gotoxy(1, startY + size + 2);

    return 0;
}
