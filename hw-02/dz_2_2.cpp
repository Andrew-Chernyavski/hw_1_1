// Задание 2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	printf ("Input the number\n");//a^n
	int a = 0;
	scanf("%d", &a);
	printf ("Input the exponent\n");
	int n = 0;
	scanf("%d", &n);
	int num=a;
	int ext=n;
	int rest = 0;
	int res = 1;
	while (ext >= 1)
	{
		if (ext == 1)
		{
			res*=num;
			ext--;
		}
		else
		{
			rest = ext % 2;
			ext = ext / 2;
			if (rest == 1)
				res*=num;
			num*=num;
		}
	}
	printf("%d ^ %d = %d",a,n,res);
	scanf("%*s");
	return 0;
}

