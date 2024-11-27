#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    
    int length = 0;

    scanf("%d", &length);
    
    int * arr = (int *)malloc(length * sizeof(int));
    
    int sum = 0;
    for (int i = 0; i < length; i++) 
    {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    
    printf("%d", sum);
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}