#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH_OF_ARRAY 100

int main()
{
    int setOfNumbers[MAX_LENGTH_OF_ARRAY] = {0};

    int userSize = 0;

    printf("Please Select Size From 1 To %d : ", MAX_LENGTH_OF_ARRAY);
    while(userSize <= 0)
    {
        scanf("%d", &userSize);
    }

    for (int i = 0; i < userSize; i++){
        printf("Enter Value For Element [%d] : ", i +1);
        scanf("%d", &setOfNumbers[i]);
    }

    int min = 0;
    int max = 0;

    for (int i = 0; i < userSize; i++)
    {
        int value = setOfNumbers[i];
        if (i != 0)
        {
            if (value < min) min = value;
            if (value > max) max = value;
        }
        else {
            min = value;
            max = value;
        }
    }

    printf("Min Number Is: %d \n", min);
    printf("Max Number Is: %d", max);


    return 0;
}
