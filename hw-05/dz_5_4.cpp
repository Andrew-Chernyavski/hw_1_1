// task4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "string.h"

struct Numb
{
	char name[14];
	char number[14];
	Numb *next;
};

Numb *create()
{
	Numb *head = new Numb;
	for (int i = 0; i < 14; i++)
		head->name[i] = '\0';
	for (int i = 0; i < 14; i++)
		head->number[i] = '\0';
	head->next = NULL;
	return head;
}

void del(Numb *&elem)
{
	Numb *tmp = elem->next;
	if (tmp->next)
		elem->next = tmp->next;
	else
		elem->next = NULL;
	delete tmp;
}

void dellist(Numb *head)
{
	while (head->next)
		del(head);
	delete head;
}

int _tmain(int argc, _TCHAR* argv[])
{
	Numb *head = create();
	FILE *file=fopen("numbers.txt", "r");
	if (file)
	{
		while (!feof(file))//если есть непустой файлик, перенести его значения в список для дальнейшей работы
		{
			Numb *tmp = new Numb;
			fscanf(file, "%s", tmp->name);
			fscanf(file, "%s", tmp->number);
			tmp->next = head->next;
			head->next = tmp;
		};
	fclose(file);
	};
	
	printf("0 - exit\n1 - add note (name & number)\n2 - found number by name\n3 - found name by number\n4 - save to numbers.txt\n\n");
	char com = '\0';
	do
	{
		printf("input the next command\n");
		scanf("\n%c", &com);
		switch (com) {
		case '1'://добавить запись
		{
			Numb *tmp = new Numb;
			printf("input the name\n");
			scanf("%s", tmp->name);
			printf("input the number\n");
			scanf("%s", tmp->number);
			tmp->next = head->next;
			head->next = tmp;
			break;
		}
		case '2'://найти телефон по имени
			{
				char name[14];
				for (int i = 0; i < 14; i++)
					name[i] = '\0';
				printf("input the name you need to find\n");
				scanf("%s", name);
				Numb *tmp = head;
				while (tmp->next)
				{
					tmp = tmp->next;
					if (!strcmp(name, tmp->name))//если имя совпало, то остановить цикл, вывести номер на экран
					{
						printf("%s\n", tmp->number);
						break;
					}
					else
						printf("name not found\n");
				}
			}
			break;
		case '3'://найти имя по телефону
			{
				char number[14];
				for (int i = 0; i < 14; i++)
					number[i] = '\0';
				printf("input the number you need to find\n");
				scanf("%s", number);
				Numb *tmp = head;
				while (tmp->next)
				{
					tmp = tmp->next;
					if (!strcmp(number, tmp->number))//если номер совпал, то остановить цикл, вывести имя на экран
					{
						printf("%s\n", tmp->name);
						break;
					}
					else
						printf("name not found\n");
				}
			}
			break;
		case '4'://сохранить текущие данные в файл
			{
				FILE *file=fopen("numbers.txt", "w+");
				Numb *tmp = head;
				while (tmp->next)
				{
					fprintf(file, "%s\n", tmp->next->name);
					fprintf(file, "%s\n", tmp->next->number);
					tmp = tmp->next;
				};
				printf ("saved\n");
			}
			break;
		case '0':
			fclose(file);
			dellist(head);
			return 0;
		default:
			printf("what?\n");
		}
	}
	while (com != '0');
	return 0;
}

