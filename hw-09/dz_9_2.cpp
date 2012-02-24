// task 9.2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
const int limmax = 56;
const int limmin = 14;

void iniz(char a[], int lim)
{
	for (int i = 0; i < lim; i++)
		a[i] = '\0';
}

int size(char a[])
{
	int i = 0;
	while (a[i] != '\0')
		i++;
	return i;
}

int hash (char a)
{
	int r = int(a);
	return r;
}

bool equal (char substr[], int sizeSub, char str[], int ind)
{
	for (int i = 0; i < sizeSub; i++)
	{
		if (substr[i] != str[(i+ind)])
			return false;
		return true;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	char str[limmax];
	iniz(str, limmax);
	char substr[limmin];
	iniz(substr, limmin);
	printf("input the string: ");
	scanf("%s", str);
	printf("input the substring you want to find\n");
	scanf("%s", substr);
	int sizeSub = size(substr);

	int hashSubstr = 0;
	int i = 0;
	while (substr[i] != '\0')
	{
		hashSubstr+=hash(substr[i]);
		i++;
	}

	int hashPartStr = 0;
	i = 0;
	for (int i = 0; i < sizeSub; i++)
		hashPartStr+=hash(str[i]);

	if ((hashSubstr == hashPartStr) && (equal(substr, sizeSub, str, 0)))
	{
		printf("substring is contained in the beginning of the line\n");
	}
	else
	{
		i = 0;
		int dif = size(str) - size(substr);
		bool found = false;
		while (!found && (i <= dif))
		{
			hashPartStr-=hash(str[i]);
			hashPartStr+=hash(str[i + sizeSub]);
			if ((hashSubstr == hashPartStr) && (equal(substr, sizeSub, str, i+1)))
			{
				printf("agreement from the %d-th symbol\n", i+2);
				found = true;
			}
			i++;
		}
		if (!found)
			printf ("substring was not founded\n");
	}
	scanf("%*s");
	return 0;
}

