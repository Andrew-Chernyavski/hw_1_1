// task 9.1.cpp: определяет точку входа для консольного приложения.
//

//в качестве примера: в первом файла числа, не превышающие 100 и кратные 2; во втором - кратные 3
//таким образом, в выходной файл записываются числа, кратные 6

#include "stdafx.h"
#include "string.h"
#include "math.h"

const int lim = 42;
const int size = 140;

struct list
{
	char word[lim];
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

void iniz(char a[])
{
	for (int i = 0; i < lim; i++)
		a[i] = '\0';
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

void lookFor(FILE *file, char str[])
{
	int key = hash(str);
	list *tmp = hashtab[key];
	while(tmp != NULL)
		if(equal(tmp->word, str))
			if(tmp->num != 0)
			{
				fprintf(file, "%s\n", str);
				tmp->num--;
				return;
			}
			else
				return;
		else
			tmp = tmp->next;
}

int _tmain(int argc, _TCHAR* argv[])
{
	FILE *file1 = fopen ("input1.txt", "r");
	FILE *file2 = fopen ("input2.txt", "r");
	FILE *output = fopen ("output.txt", "w");
	while (!feof(file1))
	{		
		char a1[lim];
		iniz(a1);
		fscanf(file1, "%s", a1);
		add(hashtab[hash(a1)], a1);
	};
	/*printf("hash narisovan\n");
	scanf("%*s");*/
	while (!feof(file2))
	{
		char a2[lim];
		iniz(a2);
		fscanf(file2, "%s", a2);
		lookFor (output, a2);
		/*printf("scanirovana\n");*/
	}
	/*printf("proverit' zapis'\n");
	scanf("%*s");*/
	del();

	printf("completed, input something to end\n");
	scanf("%*s");
	fclose(file1);
	return 0;
}



