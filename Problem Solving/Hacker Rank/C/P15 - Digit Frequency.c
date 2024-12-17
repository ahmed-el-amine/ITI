#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    char chars[1000];
    int numbs[10] = {0};
    
    scanf("%s", chars);
    
    for (int i = 0; i < strlen(chars); i++) 
    {
        if (chars[i] >= 48 && chars[i] <= 57) numbs[chars[i] - 48]++;
    }
    
    for (int i = 0; i < 10; i++) 
    {
        printf("%d ", numbs[i]);
    }
    
    return 0;
}
