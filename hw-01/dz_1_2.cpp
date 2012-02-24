r=// Задание 2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	printf("vvedite delimoe\n");
	int delim = 0;
	scanf("%d",&delim);
	printf("vvedite delitel'\n");
	int delit = 0;
	scanf("%d",&delit);
	if (delit==0)
		{
		printf("Vvedena nedopustimaya operaciya\n");
		}
	else
		{
		int nepch = 0;
			while (delim >= delit)//true;
			{
			delim = delim - delit;
			nepch = nepch + 1;
			}
		
		printf("Nepolnoe chastnoe=%d\n",nepch);
		}	
	scanf("%*s");
	return 0;
}

