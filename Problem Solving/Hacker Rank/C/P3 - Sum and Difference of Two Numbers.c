#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	int n1 = 0;
    int n2 = 0;
    float n3 = 0;
    float n4 = 0;
    
    scanf("%d %d", &n1, &n2);
    printf("%d %d", n1 + n2, n1 - n2);
    printf("\n");
    scanf("%f %f", &n3, &n4);
    printf("%.1f %.1f", n3 + n4, n3 - n4);
    
    return 0;
}