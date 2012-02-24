// Задание 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int countFibonRecurs (int number)
{
	if (number < 3)
		return 1;
	else
		return countFibonRecurs(number - 2) + countFibonRecurs(number - 1);
}

int countFibonIterative (int number)
{
	int pred1 = 1;
	int pred2 = 1;
	int sum = 0;
	for (int i = 3; i <= number; i++)
	{
		sum = pred1 + pred2;
		pred2 = pred1;
		pred1 = sum;
	}
	return sum;
}


int _tmain(int argc, _TCHAR* argv[])
{
	printf ("Input the number of member\n");
	int n = 0;
	scanf("%d", &n);
	int ans = 0;
	ans = countFibonRecurs(n);
	printf ("Recourse: %d\n", ans);
	ans = countFibonIterative(n);
	printf ("Iterative: %d\n", ans);
	scanf("%*s");
	return 0;
}

