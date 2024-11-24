#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int main() {
    int array[MAX_SIZE] = {0};
    int size = 0, cols = 0;

    while (size < 1 || size > MAX_SIZE)
    {
        printf("Enter the size of the array (1-%d): ", MAX_SIZE);
        scanf("%d", &size);

        if (size < 1 || size > MAX_SIZE) printf("Invalid size! Please enter a number between 1 and 100.\n");
    }

    while (cols < 1 || cols > size || size % cols != 0)
    {
        printf("Enter the number of columns: ");
        scanf("%d", &cols);

        if (cols < 1 || cols > size) printf("columns! must be between 1 and %d.\n", size);
        else if (size % cols != 0) printf("invalid! %d must be divisible by the number of columns.\n", size);
    }

    int rows = size / cols;

    for(int i = 0; i < size; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    for(int row = 0; row < rows; row++)
    {
        for(int col = 0; col < cols; col++)
        {
            printf(" %d ", array[row * cols + col]);
        }
        printf("\n");
    }

    return 0;
}


