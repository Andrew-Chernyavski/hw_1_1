// task2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

int next(int **a, int n)
{
	int town = 0;
	int len = 100500;
	for (int j = 2; j <= n; j++)
	{
		if ((a[1][j] < len) && (a[1][j] > 0))
		{
			town = j;
			len = a[1][j];
		}
	}
	return town;
}

int _tmain(int argc, _TCHAR* argv[])
{
	FILE *file;
	file=fopen("text.txt","r");
	int n = 0;
	int m = 0;
	fscanf(file, "%d%d", &n, &m);
	int **a = new int*[n+1];
	for (int i = 0; i < n+1; i++)
		a[i] = new int[n+1];

	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			a[i][j] = 0;

	for (int k = 0; k < m; k++)
	{
		int i = 0;
		int j = 0;
		int len = 0;
		fscanf(file, "%d%d%d", &i, &j, &len);
		a[i][j] = len;
		a[j][i] = len;
	}
	fclose(file);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}

	int tow = 0;
	for (int i = 1; i < n; i++)
	{
		tow = next(a, n);
		printf("town %d, length: %d\n", tow, a[1][tow]);
		for (int j = 2; j <= n; j++)
			if ((a[tow][j] + a[1][tow] < a[1][j]) && (a[1][j] > 0))
				a[1][j] = a[tow][j] + a[1][tow];
		a[1][tow] = 0;
	}

	scanf("%*s");
	return 0;
}

