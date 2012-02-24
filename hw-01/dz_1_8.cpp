// Задание 8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int getFactorialRecursive(int n)
{
if (n != 1)
return (n * getFactorialRecursive(n - 1));
else
return 1;
}

int getFactorialIterative(int n)
{
int res = 1;
for (int i = 2; i <= n; i++)
res *= i;
return res;
}

int _tmain(int argc, _TCHAR* argv[])
{
printf("Input a: \n");
int a = 0;
scanf("%d", &a);
printf("Recursively : %d \n", getFactorialRecursive(a));
printf("Iteratively: %d", getFactorialIterative(a));

scanf("%d", &a);
return 0;
}