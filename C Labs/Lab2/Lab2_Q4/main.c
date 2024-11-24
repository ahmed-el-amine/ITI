#include <stdio.h>
#include <stdlib.h>

int main()
{
    for (int x = 1; x <= 10; x++)
    {
        printf("Table %d \n", x);
        for (int y = 1; y <= 10; y++)
        {
            printf("%d x %d = %d \n",x,y, x*y);
        }

        printf("***************** \n");
    }

    return 0;
}
