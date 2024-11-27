#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    char ch;
    scanf("%c", &ch);
    printf("%c\n", ch);

    scanf("\n");

    char s[100] = {0};
    scanf("%[^\n]%*c", s);
    printf("%s\n", s);

    char s[100] = {0};
    scanf("%[^\n]%*c", s);
    printf("%s", s);

    return 0;
}