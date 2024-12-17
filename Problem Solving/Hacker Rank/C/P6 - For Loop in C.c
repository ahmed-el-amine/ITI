#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>



int main() 
{
    char arr[9][6] = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
    int a, b;
    scanf("%d\n%d", &a, &b);
  	// Complete the code.
    
    for (int i = a; i <= b; i++)
    {
        if (i > 0 && i < 10)
        {
            printf("%s\n", arr[i - 1]);
        }
        else printf("%s\n", (i % 2) <= 0 ? "even" : "odd");
    }

    return 0;
}

