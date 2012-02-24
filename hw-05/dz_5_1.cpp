// task1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "stdio.h"

int _tmain(int argc, _TCHAR* argv[])
{
	int value;
	FILE *file;
	file=fopen("text.txt","r");
	char in[800];
	for (int i = 0; i <800; i++)
		in[i] = '\0';
	char out[400];
	for (int i = 0; i <400; i++)
		out[i] = '\0';
	fgets(in, 200, file);
	printf("%s\n", in);//тестовый вывод прочитанной строки
	
	char word[10];
	for (int i = 0; i < 10; i++)
		word[i] = '\0';
	int i = 0;
	int j = 0;
	do
	{
		if (in[i] != ' ')//если читается текст
		{				//то символ сравнивается с массивом символов word
			int ind = 0;//уже встречавшихся в слове как минимум однажды
			while ((word[ind] != in[i]) && (word[ind] != '\0'))
				ind++;//т.е. дойти либо до уже встретившегося символа, либо удостовериться что его нет
			if (word[ind] == '\0')//т.е. символ окажется первым
			{
				word[ind] = in[i];
				printf("%c", in[i]);
				out[j] = in[i];
				j++;
			}
		}
		else//если читается пробел, то word обнуляется
		{
			for (int ind = 0; ind < 10; ind++)
				word[ind] = NULL;
			printf("%c", in[i]);
			out[j] = in[i];
			j++;
		}
		i++;
	}
	while (in[i] != '\0');
	printf("\n%s", out);
	fclose(file);
	file=fopen("result.txt","w");
	fprintf(file, "%s", out);
	scanf("%*s");
	fclose(file);
	return 0;
}

