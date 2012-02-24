// task 10.1.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"

struct list
{
	int deg;
	int coef;
	list* next;
};

list* Create()
{
	list* head = new list;
	head->next = NULL;
	return head;
}

void add(list *head, int i, int co)
{
	list* tmp = new list;
	head->next = tmp;
	tmp->deg = i;
	tmp->coef = co;
	tmp->next = NULL;
}

void input(list *head)
{
	list *tmp = head;
	int de = 0;
	scanf("%d", &de);
	for (int i = de; i >= 0; i--)
	{
		int co = 0;
		printf ("Input the coefficient of %d degree\n", i);
		scanf("%d", &co);
		add(tmp, i, co);
		tmp = tmp->next;
	}
}

bool equal(list *headP, list *headQ)
{
	bool eq = true;
	list *tmpP = headP;
	list *tmpQ = headQ;
	while ((tmpP->next) && (tmpQ->next))
	{
		tmpP = tmpP->next;
		tmpQ = tmpQ->next;
		if ((tmpP->coef != tmpQ->coef) || (tmpP->deg != tmpQ->deg))
			return false;
	}
	if ((tmpP->next) || (tmpQ->next))
		return false;
	return true;
}

int pow(int a, int b)
{
	int res = 1;
	for (int i = 0; i < b; i++)
		res*=a;
	return res;
}

int result(list *head, int x)
{
	int res = 0;
	list *tmp = head;
	while (tmp->next)
	{
		tmp = tmp->next;
		res+=((tmp->coef) * (pow(x,(tmp->deg))));
	}
	return res;
}

void printpol(list *head)
{
	list *tmp = head->next;
	printf("%d*x^%d", tmp->coef, tmp->deg);
	while(tmp->next->deg > 1)
	{
		tmp = tmp->next;
		if (tmp->coef >= 0)
			printf("+");
		printf("%d*x^%d", tmp->coef, tmp->deg);
	}
	tmp = tmp->next;
	if (tmp->coef >= 0)
		printf("+");
	printf("%d*x", tmp->coef);
	tmp = tmp->next;
	if (tmp->coef >= 0)
		printf("+");
	printf("%d\n", tmp->coef);
}

void del(list *&elem)
{
	list *tmp = elem->next;
	if (tmp->next)
		elem->next = tmp->next;
	else
		elem->next = NULL;
	delete tmp;
}

void dellist(list *head)
{
	while (head->next)
		del(head);
	delete head;
}

void printmem(int a, int b)//вывести член многочлена вида 
{
	if (a > 0)
		printf("+");
	else if (a == -1)
		printf("-");
	if ((a != 1) && (a != -1))
		printf("%d", a);
	if (b >= 2)
		printf("*x^%d", b);
	else
		if (b != 0)
			printf("*x");
}

int _tmain(int argc, _TCHAR* argv[])
{
list* headP = new list;
printf ("Input the degree of polymom P\n");
input(headP);
list *headQ = new list;
printf ("Input the degree of polymom Q\n");
input(headQ);
printf("P(x)=");
printpol(headP);
printf("Q(x)=");
printpol(headQ);
printf("0 - exit\n1 - P = Q?\n2 - P(x), Q(y)\n3 - P + Q\n\n");
char com = '\0';
	do
	{
		printf("input the next command\n");
		scanf("\n%c", &com);
		switch (com) 
		{
		case '1'://проверить равенство
		{
			if (equal(headP, headQ))
				printf("polynomials are equal\n");
			else
				printf("polynomials are not equal\n");			
			break;
		}
		case '2'://найти P(x) и Q(y)
			{
				printf("input x\n");
				int x = 0;
				scanf("%d", &x);
				printf("P(x) = %d\n", result(headP, x));
				printf("input y\n");
				scanf("%d", &x);
				printf("Q(y) = %d\n", result(headQ, x));
			}
			break;
		case '3'://суммировать
			{
				printf("P(x)+Q(x)=");
				list *tmpP = headP;
				list *tmpQ = headQ;
				if (headP->next->deg != headQ->next->deg)//полиномы разных степеней
				{
					if (headP->next->deg > headQ->next->deg)//полином – имеет бќльшую степень
					{
						tmpP = tmpP->next;
						printf("%d*x^%d", tmpP->coef, tmpP->deg);
						while (tmpP->next->deg > tmpQ->next->deg)
						{
							tmpP = tmpP->next;
							printmem(tmpP->coef, tmpP->deg);
						}
						while(tmpP->next)
						{
							tmpP = tmpP->next;
							tmpQ = tmpQ->next;
							printmem((tmpP->coef + tmpQ->coef), tmpP->deg);
						}
					}
					else//Q имеет бќльшую степень
					{
						tmpQ = tmpQ->next;
						printf("%d*x^%d", tmpQ->coef, tmpQ->deg);
						while (tmpP->next->deg < tmpQ->next->deg)
						{
							tmpQ = tmpQ->next;
							printf("+%d*x^%d", tmpQ->coef, tmpQ->deg);
							printmem(tmpQ->coef, tmpQ->deg);
						}
						while(tmpP->next)
						{
							tmpP = tmpP->next;
							tmpQ = tmpQ->next;
							printmem((tmpP->coef + tmpQ->coef), tmpP->deg);
						}
					}
				}
				else//полиномы одинаковых степеней
				{
					tmpP = tmpP->next;
					tmpQ = tmpQ->next;
					printf("%d*x^%d", (tmpP->coef + tmpQ->coef), tmpP->deg);
					while(tmpP->next)
					{
						tmpP = tmpP->next;
						tmpQ = tmpQ->next;
						printmem((tmpP->coef + tmpQ->coef), tmpP->deg);
					}
				}
			}
			printf("\n");
			break;
		case '0':
			dellist(headP);
			dellist(headQ);
			return 0;
		default:
			printf("what?\n");
		}
	}
	while (com != '0');
	return 0;
}

