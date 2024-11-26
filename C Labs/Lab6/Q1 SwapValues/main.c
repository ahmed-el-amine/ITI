#include <stdio.h>

int main()
{
    int a = 5, b = 10;

    printf("Init Values Ar a = %d, b = %d\n", a, b);    

    a = a + b;
    b = a - b;
    a = a - b;

    printf("Addition and Subtraction: a = %d, b = %d\n", a, b);    

    a = a * b;
    b = a / b;
    a = a / b;

    printf("Multiplication and Division: a = %d, b = %d\n", a, b);
    
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    
    printf("Bitwise XOR: a = %d, b = %d\n", a, b);

    swap(&a, &b);

    printf("Using a Function: a = %d, b = %d\n", a, b);


    return 0;
}


void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}