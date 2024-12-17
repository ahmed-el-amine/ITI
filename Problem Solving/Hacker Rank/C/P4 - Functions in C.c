#include <stdio.h>
/*
Add `int max_of_four(int a, int b, int c, int d)` here.
*/


int max_of_four(int a, int b, int c, int d) 
{
    int bValue = a;
    if (b > bValue) bValue = b;
    if (c > bValue) bValue = c;
    if (d > bValue) bValue = d;
    
    return  bValue;
}

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = max_of_four(a, b, c, d);
    printf("%d", ans);
    
    return 0;
}