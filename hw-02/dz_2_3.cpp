// Задание 3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
void diff(int mas[], int numOfTerms, int num)
{
	while (numOfTerms != 1)
	{
		int i = numOfTerms - 1;
		int s = mas[numOfTerms];
		while ((i > 1) && (mas[i - 1] <= mas[i]))
		{
			s = s + mas[i];
			i--;
		}
		mas[i]++;
		numOfTerms = (i + s - 1);
		for(int j = i + 1; j <= numOfTerms; j++)
			mas[j] = 1;
		for(int i = 1; i <= numOfTerms; i++)
		if (i != numOfTerms)
			printf("%d+", mas[i]);
		else
			printf("%d", mas[i]);
		printf("\n");
	}
}

int main()
{
	printf("Input the number: ");
	int num = 0;
	scanf("%d", &num);
	int numOfTerms = num;
	int mas[50]; //число, гарантированно превыщающее входные данные
	for(int i = 1; i<= numOfTerms; i++) 
		mas[i] = 1;
	for(int i = 1; i <= numOfTerms; i++)
	{
		if (i != numOfTerms)
			printf("%d+", mas[i]);
		else
			printf("%d", mas[i]);
	}
	printf("\n"); 
	diff(mas, numOfTerms, num);
	scanf("%*s");
	return 0;
}

