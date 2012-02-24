// Задание 7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "math.h"

int _tmain(int argc, _TCHAR* argv[])
{
	const int n=100;//вводится число, задающее предел простых чисел
	bool a[n];
	int i = 2;
	for (i = 2; i <= n; i++)
		a[i] = true;
	for (i = 2; i <= n/2; i++)
	{
		int j = 2;
		for (j = 2; j <= (sqrt(n)); j++)
			if (i * j <= n)
				a[j * i]=false;
	};
	for ( i = 2; i <= n; i++)
	{
		if (a[i] == true)
			printf("%d, ",i);
	}
	scanf("%*s");
	return 0;
}

