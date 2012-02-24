// task2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

const int lim = 28;

struct AT
{
	char value;
	AT *oper1;
	AT *oper2;
};

AT *create(char a)
{
	AT *head = new AT;
	head->oper1 = NULL;
	head->oper2 = NULL;
	head->value = a;
	return head;
}

void mincalc(AT *&head)
{
	int res = 0;
	switch (head->value)
	{
	case '+':
		res = int(head->oper1->value) + int(head->oper2->value) - 2*int('0');
		break;
	case '-':
		res = int(head->oper1->value) - int(head->oper2->value);
		break;
	case '/':
		res = ((int(head->oper1->value) - int('0')) / (int(head->oper2->value) - int('0')));
		break;
	case '*':
		res = ((int(head->oper1->value) - int('0')) * (int(head->oper2->value) - int('0')));
		break;
	}
	delete head->oper1;
	head->oper1 = NULL;
	delete head->oper2;
	head->oper2 = NULL;
	head->value = res + int('0');


}

void add(AT *&tr, char a[], int &i)
{
	if ((a[i] == '(') || (a[i] == ')'))
	{
		add(tr, a, ++i);
	}
	else
	{
		if(a[i] != '\0')
		{
			if((a[i] == '+') || (a[i] == '-') || (a[i] == '*') || (a[i] == '/'))
			{
				tr = create(a[i++]);
				add(tr->oper1, a, i);
				add(tr->oper2, a, i);
			}
			else
			{
				tr = create(a[i++]);
			}
		}
		else
			return;
	}
}

void calc(AT *&head)
{
	if (oper(head->value))
	{
		if (!oper(head->oper1->value) && !oper(head->oper2->value))
			mincalc(head);
		else
		{
			if (oper(head->oper1->value))
				calc(head->oper1);
			if (oper(head->oper2->value))
				calc(head->oper2);
			calc(head);
		}
	}
}

bool number (char ch)
{
	return ((ch >= '0') && (ch <= '9'));
}

bool oper (char ch)
{
	return ((ch == '+') || (ch == '-') || (ch == '*') || (ch == '/'));
}

void iniz (char a[], int lim)
{
	for (int i = 0; i < lim; i++)
		a[i] = '\0';
}



void printup(AT *tmp)
{
	if (tmp->oper1)
		if ((tmp->oper1->oper1) || (tmp->oper1->oper2))//левый сын - дерево
			printup (tmp->oper1);
		else//левый сын - лист
			printf("%c ", tmp->oper1->value);
	printf("%c ", tmp->value);
	if (tmp->oper2)
		if ((tmp->oper2->oper2) || (tmp->oper2->oper1))
			printup(tmp->oper2);
		else
			printf("%c ", tmp->oper2->value);
}

int _tmain(int argc, _TCHAR* argv[])
{
	FILE *file=fopen("input.txt", "r");
	char str[15];
	fscanf(file, "%s", &str);
	printf("%s\n", str);
	AT *head = new AT;
	AT *tmp = head;
	int i = 0;
	add(*&head, str, i);
	printup(*&head);
	calc(*&head);
	printf("\n%c\n", (head->value));
	scanf("%*s");
	fclose(file);
	delete head;
	return 0;
}
