// ������� 4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "time.h"

struct List {
	int value;
	List *next;
};

List *create()
{
	List *head = new List;
	head->value = 0;
	head->next = NULL;
	return head;
};

void swap (int &a, int &b)
{
	int c = a;
	a = b;
	b = c;
};

void add(List *elem, int x)
{
	List *list = new List;
	list->value = x;
	list->next = elem->next;
	elem->next = list;
}

void addToEnd(List *elem, int x)
{
	List *tmp = elem;
	while (tmp->next)
		tmp = tmp->next;
	add(tmp,x);
};

void printlist(List *head)
{
	List *tmp = head;
	while (tmp->next)
	{
		tmp = tmp->next;
		printf("%d ", tmp->value);
	}
	printf("\n");
}

void mergeSortFrag(List *&tmp, int x)//����� ��� ������� ������ � x ����� tmp
{
	List *tmp1 = tmp->next;//������ ������� �������
	List *tmp2 = tmp1;
	for (int i = 1; i<=x; i++)
		tmp2 = tmp2->next;//������ ������� �������
	int i1 = x;
	int i2 = x;//������� ���������� ��-��� ������� �������
	List *head = create();//����� ��� "��������" ��������
	do//���������� ������ ���� ��������, ������� ����������� � �����
	{
		if ((tmp1->value) < (tmp2->value))
		{
			addToEnd(head, tmp1->value);
			i1--;
			tmp1 = tmp1->next;
		}
		else
		{
			addToEnd(head, tmp2->value);
			i2--;
			tmp2 = tmp2->next;
		}
	}
	while ((i1 != 0) && (i2 != 0));//����� ���� �� �������� �����������

	if (i1 != 0)			//�� ���������� "��������"
	{
		for (int i = 1; i < i1; i++)
		{
			addToEnd(head, tmp1->value);
			tmp1 = tmp1->next;
		};
		addToEnd(head, tmp1->value);
	}
	else if (i2 != 0)
		{
			for (int i = 1; i < i2; i++)
			{
				addToEnd(head, tmp2->value);
				tmp2 = tmp2->next;
			};
			addToEnd(head, tmp2->value);
		};

	tmp1 = head->next;//� �������� ����� "����" - ������ ��� ������������� ���������� 
	tmp2 = tmp->next;//������ ������� �� ����� ������� (head - �����, tmp - ��������)
	while (tmp1->next)
	{
		tmp2->value = tmp1->value;
		tmp1 = tmp1->next;
		tmp2 = tmp2->next;
	};
	tmp2->value = tmp1->value;
};

int _tmain(int argc, _TCHAR* argv[])
{
	const int num = 128;
	List *head = create();
	List *tmp = head;
	for (int i = 1; i<=num; i++)
	{
		addToEnd(tmp, (num+1-i));
		tmp = tmp->next;
	}
	printlist(head);
	
	int i1 = num/2;
	int stdif = 1;
	do
	{
		tmp = head;
		int steps = (i1 / (stdif));//���������� ����������� ������ ������ stdif
		for (int i = 0; i < steps; i++)
			{
				mergeSortFrag(tmp, stdif);
				for (int j = 0; j < (2*stdif); j++)
					tmp = tmp->next;
			}	
		printlist(head);
		stdif*=2;
	}
	while (stdif <= i1);
	scanf("%*s");
	return 0;
}

