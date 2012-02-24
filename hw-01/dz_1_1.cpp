vy// Задание 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	printf ("Input x\n");
	int x = 0;
	scanf("%d",&x);
	int kv = x * x;
	printf("x^4+x^3+x^2+x+1=%d\n",(kv + 1) * (kv + x) + 1) ;
	scanf("%*s");

	return 0;
}

