// Задание 4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "math.h"

int exp(int k)
{
	float exp = 0;
	exp = log10f(k);
	exp = ceil(exp);
	return exp;
}


int _tmain(int argc, _TCHAR* argv[])
{
	int a[9];
	for (int i = 0; i<=9; i++)
		a[i] = 0;
	int num = 0;
	printf("Enter the number\n");
	scanf("%d",&num);
	int s = exp(num);
	do
	{
		int del = 1; 
		for (int i = 1; i < s; i++)
			del*=10;
		int z = num / del;
		a[z]++;
		num = num % del;
		s--;
	}
	while (s >= 2);
	a[num]++;

	for (int i = 0; i<=9; i++)
		printf("a[%d]=%d ", i, a[i]);
	printf("\n");

	int i = 1;
	while (a[i] == 0)
		i++;
	printf("%d",i);
	a[i]--;
	for (i = 0; i<=9; i++)
		if (a[i] != 0)
			for (int j = 0; j<a[i]; j++)
				printf("%d",i);

	scanf("%*s");
	return 0;
}

