// task3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	FILE *file;
	file=fopen("input.txt", "r");
	char str[1000];
	bool sl = false;
	while (!feof(file))
	{
		fgets (str, 1000, file);
		int i = 1;
		while((str[i-1] != '/') && (str[i] != '/') && (str[i] != '\0') || (sl))
		{
			if (str[i-1] == '"')
				sl = !sl;
			i++;
		}
		while (str[i] != '\0')
		{
			printf("%c", str[i]);
			i++;
		}
	}
	fclose(file);
	scanf("%*s");
	return 0;
}

