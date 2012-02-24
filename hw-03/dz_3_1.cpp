// Задание 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "time.h"
#include <cstdlib>
void sort(int a[], int l, int r)//массив, лев. инд, прав. инд.
{
	if(l < r)
	{ 
		int point = a[l];
		int i = l;
		int j = r;
		while(i < j)
		{
			while(a[i] <= point && i < r)
				i++;
			while(a[j] >= point && j > l)
				j--;
			if(i < j)
			{
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
		int temp = a[l];
		a[l] = a[j];
		a[j] = temp;
		sort(a, l, j - 1);
		sort(a, j + 1, r);
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(NULL));
	const int n = 20;
	int a[n];
	for (int i = 0; i < n; i++)
	{
		int ran = rand() % n;
		a[i] = ran;
		printf("%d ",a[i]);
	}
	printf("\n");
	sort(a, 0, n-1);
	int max = 0;
	for (int i = n-1; i > 0; i--)
		if (a[i] == a[i - 1])
		{
			max = a[i];
			break;
		}
	printf("\n");
	printf("%d", max);
	scanf("%*s");
	return 0;
}

