#include <stdio.h>
#include <stdlib.h>

#define ROW 3
#define COL 4

void clearTheBuffer() {
	int c;
	while ((c = getchar()) != '\n' && c != EOF) { }
}

int main()
{
	int matrixArray[ROW][COL] = { 0 };

	for (int i = 0; i < ROW; i++)
	{
		for (int y = 0; y < COL; y++)
		{
			printf("Please Enter Value For [%d][%d]: ", i, y);

			while (scanf("%d", &matrixArray[i][y]) != 1) {
				printf("Invalid Input. Please Enter An Integer For [%d][%d]: ", i, y);
				clearTheBuffer();
			}
		}
	}

	for (int i = 0; i < ROW; i++)
	{
		int sumOfCol = 0;
		for (int y = 0; y < COL; y++)
		{
			sumOfCol += matrixArray[i][y];
		}

		printf("The SumOfCol in row %d = %d avg = %.01f \n", i + 1, sumOfCol, (float)sumOfCol / COL);
	}

	return 0;
}
