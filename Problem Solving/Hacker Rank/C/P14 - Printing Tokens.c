#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    char * s = malloc(1024 * sizeof(char));
    scanf("%[^\n]", s);
    s = realloc(s, strlen(s) + 1);
    
    for (int i = 0; i < strlen(s); i++) {
        char value = s[i];
        if (value != ' ') printf("%c", value);
        else printf("\n");
    }
    
    //Write your logic to print the tokens of the sentence here.
    return 0;
}