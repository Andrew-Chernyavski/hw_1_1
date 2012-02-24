// Задание 3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stack.h"

int priority(char ch)
{
	switch(ch)
	{
		case '*':
			return 3;
		case '/':
			return 3;
		case '-':
			return 2;
		case '+':
			return 2;
		case '(':
			return 1;
		case ')':
			return 1;
	}
}

stack *oper(stack *head, char c, char b[], int &j)
{
	stack *tmp = head;
	if((c == '+') || (c == '-') || (c == '/') || (c == '*'))
	{
		if(empty(tmp))
			tmp = push(tmp, c);
		else
			if(priority(tmp->value) < priority(c))             
				tmp = push(tmp, c);    
			else
			{
				while((!empty(tmp)) && (priority(tmp->value) >= priority(c)))
					b[j++] = pop(&tmp); 
				tmp = push(tmp, c);
			}
	}
	return tmp;
}

void operand(char c, char b[], int &j)
{
	if((c >= '0') && (c <= '9'))
		b[j++] = c;
}

stack *clbr(stack *head, char c, char b[], int &j)//после чтения закр. скобки
{
	stack *tmp = head;
	if(c == ')')          
	    {
			while((tmp->value) != '(')       
				b[j++] = pop(&tmp);	
				pop(&tmp);
		}
	return tmp;
}

stack *opbr(stack *head, char c)//откр. скобку в стек
{
	stack *tmp = head;
	if(c == '(')
		tmp = push(tmp, '(');
	return tmp;
}

stack *end(stack *head, char b[], int &j)//вытащить всё
{
	stack *tmp = head;
	while(!empty(tmp))
		b[j++] = pop(&tmp);
	b[j]='\0';
	return tmp;
}

bool numb(char ch)
{
	return ((ch >= '0') && (ch <= '9'));
}

int main()
{
	stack *st = NULL;
	char a[20];//вход, счётчик i
	char b[20];//вывод, счётчик j
	printf("infix: ");
	scanf("%s", a);
	int i = 0;
	int j = 0;
	while(a[i] != '\0')           
	{
		st = clbr(st, a[i], b, j);
		operand(a[i], b, j);
		st = opbr(st, a[i]);
		st = oper(st, a[i], b, j);
		i++;                                    
	}
	st = end(st, b, j);
	printf("postfix: %s\n", b);
	
	i = 0;
	while (b[i] != '\0')
	{
		if (numb(b[i]))//число - в стек
			st = push (st, b[i]);
		else//операция - вытащить два числа и прооперировать
		{
			int a1 = (int(pop(&st)) - int('0'));
			int b1 = (int(pop(&st)) - int('0'));
			int c = 0;
			switch (b[i])
			{
			case '+':
				c = a1 + b1;
				break;
			case '-':
				c = b1 - a1;
				break;
			case '*':
				c = b1 * a1;
				break;
			case '/':
				c = b1 / a1;
				break;
			}
			st = push (st, (c + int('0')));
		}
		i++;
	}
	int res = (int(pop(&st)) - int('0'));
	printf("result: %d\ninput something to close\n", res);

	scanf("%*s");
	return 0;
}