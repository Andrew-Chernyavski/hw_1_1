// task1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "BT.h"

int _tmain(int argc, _TCHAR* argv[])
{
	printf("0 - exit\n");
    printf("1 - add value to a set\n");
    printf("2 - remove value from the set\n");
    printf("3 - find value in the set\n");
	printf("4 - print set from low to high\n");
	printf("5 - print set from high to low\n");
	bool tr = false;
	BT *head = new BT;
	while (2 > 1)
	{
		int com = 1;
		printf("Enter next command: ");
		scanf("%d", &com);
		switch(com)
		{
		case 1://add value to a set
			{
				int val = 0;
				printf("input a value you want to add: ");
				scanf("%d", &val);
				if (!tr)
				{
					head->value = val;
					head->left = NULL;
					head->right = NULL;
					tr = true;
				}
				else
				{
					add(head, val);
				}
				break;
			}
		case 2://remove value from the set
			{
				printf("Enter a value you want to delete: ");
				int val = 0;
				scanf("%d", &val);
				delElem(head, val);
				break;
			}
		case 3://find value in the set
			{
				printf("Enter a value you want to find: ");
				int val = 0;
				scanf("%d", &val);
				if (exists(head, val))
					printf("value is found\n");
				else
					printf("value is not found\n");
				break;
			}
		case 4://print set from low to high
			{
				printup(head);
				printf("\n");
				break;
			}
		case 5://print set from high to low
			{
				printdown(head);
				printf("\n");
				break;
			}
		case 0://exit
			{
				delBT (head);
				return 0;
			}
		}
	}
	return 0;
}

