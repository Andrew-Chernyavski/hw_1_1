// task3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"

int numOfDigs (int x)
{
	int num = 1;
	if ((x < 10) && (x > -10))
		return num;
	else
	{
		while ((x >= 10) || (x <= -10))
		{
			x = x / 10;
			num++;
		}
		return num;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	printf ("Input degree of polynom\n");
	int deg = 0;
	scanf("%d", &deg);
	const int max = 20;//limit of degree
	int a[max];
	for (int i = deg; i >= 0; i--)
	{
		printf("Input the coefficient of %d degree\n", i);
		scanf("%d", &a[i]);
	}

	//line of degrees
	if (deg > 1)
	{
		if (a[deg] == 1)
			printf(" %d", deg);
		else
			if (a[deg] == -1)
				printf("  %d", deg);
			else
			{	
				if (a[deg] < 0)
				printf(" ");
				int c = numOfDigs(a[deg]);
				for (int i = 0; i < c; i++)
					printf(" ");
				printf(" %d", deg);
			}
	}
	for (int i = (deg - 1); i > 1; i--)
	{
		if (a[i] != 0)
		{
			if (a[i] == 1)
				printf("  %d", i);
			else
				if (a[i] == -1)
					printf("  %d", i);
				else
				{
					int c = numOfDigs(a[i]);
					for (int j = 0; j < c; j++)
						printf(" ");
					printf("  %d", i);
				}
		}
	}
	printf("\n");
	
	//line  of "x" and coefficients
	if (a[deg] == 1)
		printf("x");
	else
		if (a[deg] == -1)
			printf("-x");
		else
			printf("%dx", a[deg]);
	for (int i = (deg - 1); i >= 1; i--)
	{
		if (a[i] > 0)
		{
			int c = numOfDigs(i+1);
			for (int j = 0; j < c; j++)
				printf(" ");
			if (a[i] != 1)
				printf("+%dx", a[i]);
			else 
				printf("+x");
		}
		else
			if (a[i] <0)
			{
				int c = numOfDigs(i+1);
				for (int j = 0; j < c; j++)
					printf(" ");
				if (a[i] != -1)
					printf("%dx", a[i]);
				else
					printf("-x");
			}
	}
	if (a[0] > 0)
		printf(" +%d", a[0]);
	else
		if (a[0] < 0)
			printf(" %d", a[0]);
	scanf("%*s");
	return 0;
}

