// task1.cpp: ���������� ����� ����� ��� ����������� ����������.
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
	printf("%s\n", in);//�������� ����� ����������� ������
	
	char word[10];
	for (int i = 0; i < 10; i++)
		word[i] = '\0';
	int i = 0;
	int j = 0;
	do
	{
		if (in[i] != ' ')//���� �������� �����
		{				//�� ������ ������������ � �������� �������� word
			int ind = 0;//��� ������������� � ����� ��� ������� �������
			while ((word[ind] != in[i]) && (word[ind] != '\0'))
				ind++;//�.�. ����� ���� �� ��� �������������� �������, ���� �������������� ��� ��� ���
			if (word[ind] == '\0')//�.�. ������ �������� ������
			{
				word[ind] = in[i];
				printf("%c", in[i]);
				out[j] = in[i];
				j++;
			}
		}
		else//���� �������� ������, �� word ����������
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

