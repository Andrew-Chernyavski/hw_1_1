#include "stdafx.h"
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

int main()
{
	const int n = 5;//кол-во эл-тов  сортируемого массива
	int a[n];
	for (int i = 0; i < n; i++)
	{
		int c = rand() % 100 ; 
		a[i] = c;//массив заполняется случайными числами
	}
	printf("Ishodnyi massiv : ");
	for (int i = 0; i <= n - 1; i++)
		printf("%d ", a[i]);//выступление массива
	printf("\n");
	sort(a, 0, n - 1);//собственно сортировка
	printf("Posle sortirovki : ");//на бис в новом порядке
	for (int i = 0; i <= n - 1; i++)
		printf("%d ", a[i]);
	scanf("%");
	return 0;
}