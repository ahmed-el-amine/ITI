#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("A- ITI \n");
    printf("B- NTI \n");
    printf("C- FTI \n");
    printf("Please Select One Option From A,B,C \n");

    char userSelectOption = 0;

    scanf("%c", &userSelectOption);

    switch(userSelectOption)
    {
        case 'a':
        case 'A':
            printf("You Selected ITI");
            break;
        case 'b':
        case 'B':
            printf("You Selected NTI");
            break;
        case 'c':
        case 'C':
            printf("You Selected FTI");
            break;
        default:
         printf("Select Option From A,B,C Only");
            break;
    }

    return 0;
}
