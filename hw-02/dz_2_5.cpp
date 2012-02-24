// Задача 5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>

void build(int x[], int j, int n) 
{
	int list = 0;
	int tmp = x[j];
	while (j <= n / 2) 
	{
		list = j * 2; 
		if ((list < n) && (x[list] < x[list + 1]))
			list++;
		if(tmp >= x[list])
			break; 
		x[j] = x[list]; 
		j = list;
	}
	x[j] = tmp;
}

void Sort(int x[], int n) 
{
	printf("\n");
	int tmp;
	for (int i = n / 2; i >= 0; i--) 
		build(x, i, n - 1); 
	for (int i = n - 1; i > 0; i--) 
	{
		tmp = x[0];
		x[0] = x[i]; 
		x[i] = tmp; 
		build(x, 0, i - 1);
	}
}

int main()
{
	const int n = 10;
	int a[n];
	for (int i = 0; i <= n - 1; i++)
		a[i] = rand() % 100;
	printf("First array: ");
	for (int i = 0; i <= n - 1; i++)
		printf("%d ", a[i]);
	printf("\n");
	Sort(a, n);
	printf("Result: ");
	for (int i = 0; i <= n - 1; i++)
		printf("%d ", a[i]);
	scanf("%*s");
	return 0;
}
