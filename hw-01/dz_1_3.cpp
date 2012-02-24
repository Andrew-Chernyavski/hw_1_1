// Задание 3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
const int m=6;
const int n=4;
int a[m+n];
int i;
for (i=0; i<(m+n); i++)
	{
	a[i]=i;
	printf ("%d ",a[i]);
	}
printf("\n");
for ( i = 0; i<m;i++)
	{
	int j=0;
	for (j = m+n-1;j>0;j--)
		{
		int h=0;
		h = a[j];
		a[j] = a[0];
		a[0] = h;
		}
for (i=0; i<(m+n); i++)
	printf ("%d ",a[i]);
printf("\n");
scanf("%*s");
	return 0;
}

