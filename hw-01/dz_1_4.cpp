// Задание 4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	int a[27];
	int i = 0;
	for (i = 0; i <= 27; i++)
		a[i] = 0;
	for (i = 0; i <= 999; i++) 
		a[ (i / 100) + (i % 100) / 10 + (i % 10)] += 1;
	int num=0;
	for (i = 0; i <= 27; i++) 
		num = num + a[i] * a[i];
	printf ("number of happy tickets=%d",num);
	scanf("%*s");
	return 0;
}

