// Задание 3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "list.h"


int _tmain(int argc, _TCHAR* argv[])
{
	printf("Commands:\n0 - exit\n1 - add value to sorted list\n2 - remove value from list\n3 - print list\n\n");
	List *head = create();
	char ch = ' ';
	do
	{
		printf("Enter the next command\n");
		scanf("\n%c",&ch);
		switch(ch)
		{
		case'1':
		{
			printf("Enter the number you want to add\n");
			int n = 0;
			scanf("%d",&n);
			addToSort(head, n);
			break;
		}
		case '2':
		{
			printf ("Enter the number you want to delete\n");
			int n = 0;
			scanf("%d",&n);
			delnum(head,n);
			break;
		}
		case '3':
			printlist(head);
			break;
		}
	}
	while (ch != '0');
	dellist(head);
	return 0;
}

