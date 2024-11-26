#include <stdio.h>
#include <stdlib.h>

int main()
{
    int userInput = 0;
    int sumNumbers = 0;

    while(sumNumbers <= 100)
    {
        printf("Enter Number \n");

        scanf("%d", &userInput);

        if (userInput < 1)
        {
            printf("Please Enter Number From 1 To +N \n");
        }
        else
        {
            sumNumbers += userInput;

            printf("sumNumbers: %d \n", sumNumbers);
        }

    }

    printf("The sum has exceeded 100. Curent Sum Is (%d)", sumNumbers);

    return 0;
}
