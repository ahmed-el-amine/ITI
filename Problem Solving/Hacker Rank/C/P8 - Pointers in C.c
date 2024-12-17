#include <stdio.h>

void update(int *a,int *b) {
    int tempa = *a + *b;
    int tempb = (*b > *a) ? *b - *a : *a - *b;

    *a = tempa;
    *b = tempb;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}