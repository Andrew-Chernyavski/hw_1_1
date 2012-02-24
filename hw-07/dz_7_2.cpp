// task 7.2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "math.h"

const int limword = 14;
const int size = 140;

struct list
{
	char word[limword];
	int num;
	list *next;
}; 

list *hashtab[size];


list *create(char word[])
{
	list *tmp = new list;
	int i = 0;
	while(word[i - 1] != '\0')
		tmp->word[i] = word[i++];
	tmp->num = 1;
	tmp->next = NULL;
	return tmp;
}

bool equal(char str[], char str2[])
{
	int i = 0;
	bool f = true;
	while((str[i] != '\0') || (str2[i] != '\0'))
	{
		if(str[i] != str2[i])
			return false;
		i++;
	}
	return true;
}

void add(list *&tab, char word[])
{
	if(tab == NULL)
		tab = create(word);
	else
	{
		if(equal(word, tab->word))
			tab->num++;
		else
			add(tab->next, word);
	}
}

void del()
{
	for (int i = 0; i < size; i++)
		if(hashtab[i] != NULL)
			while (hashtab[i] != NULL)
			{
				list *tmp =	hashtab[i];
				hashtab[i] = tmp->next;
				delete(tmp);
			}
}

void print()
{
	for(int i = 0; i < size; i++)
	{
		if(hashtab[i] != NULL)
			while (hashtab[i] != NULL)
			{
				printf("\"%s\" -  %d time(s)\n", hashtab[i]->word, hashtab[i]->num);
				hashtab[i] = hashtab[i]->next;
			}
	}
}

void iniz(char a[], int lim)
{
	for (int i = 0; i < lim; i++)
		a[i] = '\0';
}

int hash (char word[])
{
	int i = 0;
	int res = 0;
	while (word[i] != '\0')
	{
		res+=word[i];
		i++;
	}
	res = (abs(res) % 140);
	return res;
}

int main()
{
	FILE *file;
	file = fopen("input.txt", "r");
	char str[limword];
	while(!feof(file))
	{
		iniz(str, limword);
		fscanf(file, "%s", str);
		printf("%s ", str);
		add(hashtab[hash(str)], str);
	}
	printf("\n\n");
	print();
	del();
	scanf("%*s");
	return 0;
}

