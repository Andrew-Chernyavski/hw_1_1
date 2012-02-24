// «адание 5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{	const int num=100;//число, гарантированно превышающее число знаков во входных данных
	char ch[num];
	gets(ch);
	int bal = 0;
	int i = 0;
	for (i = 0; i <= num; i++)
	{
		if (ch[i] == '(' )
			bal+=1;
		if (ch[i] == ')' )
			bal-=1;
		if (bal < 0)
		{
			break; printf("no balance\n");
	};
	if (bal == 0)
		printf("balance\n");
	else
		printf("no balance\n");
	scanf("%*s");
	return 0;
}

