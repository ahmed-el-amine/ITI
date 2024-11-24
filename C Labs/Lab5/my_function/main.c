#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "libs/strings/strings.c"
#include "libs/strings/strings.h"

#include "libs/validation/validation.h"
#include "libs/validation/validation.c"

int main() 
{
    
    // char ch = getchar();

    // printf("%c %d", ch, ch);
    // char input[100];
    // printf("%d", validationInputInt_Int(input));

char ss = 'A';
    printf("%c \n", stringCharToLowerCase(ss));
    printf("%c", stringCharToUpperCase(ss));

tolower(ss);
    
    // int sss = 0;

    // scanf("%d", &sss);

    // printf("%d", sss);

    return 0;
}