// Задание 2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <time.h>
#include "list.h"


int program(int num, int k)//прогнать программу для num эл-тов, удаляя каждый k-й эл-т
{
	List *head = CreateCircle(num);
	int numleft = num;
	List *tmp = head;
	for (int i = 1; i<num; i++)
		tmp = tmp->next;
	do
	{
		for (int i = 1; i<k; i++)
			tmp = tmp->next;
		del(tmp);
		numleft--;
	}
	while (numleft > 1);
	int mem = tmp->value;
	return mem;//вернуть последний оставшийся эл-т
	dellist(head);
}

int _tmain(int argc, _TCHAR* argv[])
{
	const int num = 10;//кол-во эл-тов списка
	printf("Enter the item number you want to delete\n");
	int k = 0;
	scanf("%d",&k);
	int result = 0;
	result = program (num,k);
	printf("%d\n", result);

	printf("Enter the item number you want to save\n");
	int sav = 0;
	bool found = false;
	scanf("%d", &sav);
	for (int i = 2; i<=num; i++)
	{
		result = program (num,i);
		if (result == sav)
		{
			found = true;
			printf("%d ", i);
		}
	}
	if (!found)
		printf("Impossible");
	scanf("%*s");
	return 0;
}


