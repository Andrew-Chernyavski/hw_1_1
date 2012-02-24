ри// Задание 6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	const int nums = 200; //предельное число символов строки
	const int nump = 10;//предельное число символов подстроки
	char chs[nums];
	char chp[nump];
	printf("Input the string\n");
	gets(chs);//чтение строки
	printf("Input the substring\n");
	gets(chp);//чтение подстроки
	int i = 0;//индекс символа строки
	int j = 0; //индекс символа подстроки
	int num = 0;//собственно кол-во вхождений
	while (chs[i])
	{
		if (chs[i] == chp[j])
		{
			if (!chp[j+1])
			{
				num++;
				i++;
				j = 0;
			}
			else
			{
				i++;
				j++;
			};
		}
		else
		{
			i++;
			j = 0;
		};
	};
	printf("the number of entry=%d\n",num);
	scanf("%*s");
	return 0;
}

