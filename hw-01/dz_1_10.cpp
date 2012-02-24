// Задание 10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	const int nums=50;//предельное количество ввводимых символов
	char ch[nums];
	printf("Input the string\n");
	gets(ch);//чтение строки
	int fl=0;//флажок, отмечающий конец вводимой строки
	bool pal=true;
	for (fl=0; ch[fl]; fl++);
	for (int i=0; i<fl/2; i++)
	{
		if (ch[i]!=ch[fl-i-1])
		{	
			pal=false;
			break;
		};
	}
		if (pal)
		printf("palindrom\n");
	else
		printf("no palindrom\n");
	scanf("%*s");
	return 0;
}

