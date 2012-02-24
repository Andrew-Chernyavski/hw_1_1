// Задание 2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "time.h"
#include <cstdlib>

int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(NULL));
	const int n=5;
	int a[n][n];
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<n; j++)
		{
			int ran = rand() % 40;
			a[i][j] = ran + 10;//для удобства расположения, чтобы все числа были двузначными
			printf ("%d ",a[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	int i = n / 2;
	int j = n / 2;//начало ставится в центр
	printf("%d ", a[i][j]);
	int indspir = 1;//"индекс" спирали - кол-во "звеньев" вправо при старте следующего "круга"
	for (int lap = 1; lap <= n/2; lap++)
	{
		i--;
		printf("%d ", a[i][j]);
		
		for (int ind = 0; ind < indspir; ind++)
		{
			j++;
			printf("%d ", a[i][j]);
		}

		for (int ind = 0; ind <= indspir; ind++)
		{
			i++;
			printf("%d ", a[i][j]);
		}

		for (int ind = 0; ind <= indspir; ind++)
		{
			j--;
			printf("%d ", a[i][j]);
		}

		for (int ind = 0; ind <= indspir; ind++)
		{
			i--;
			printf("%d ", a[i][j]);
		}
	}

	scanf("%*s");
	return 0;
}

