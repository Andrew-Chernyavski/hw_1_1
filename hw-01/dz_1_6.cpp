��// ������� 6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	const int nums = 200; //���������� ����� �������� ������
	const int nump = 10;//���������� ����� �������� ���������
	char chs[nums];
	char chp[nump];
	printf("Input the string\n");
	gets(chs);//������ ������
	printf("Input the substring\n");
	gets(chp);//������ ���������
	int i = 0;//������ ������� ������
	int j = 0; //������ ������� ���������
	int num = 0;//���������� ���-�� ���������
	while (chs[i])
	{
		if (chs[i] == chp[j])
		{
			if (!chp[j+1])
			{
				num++;
				i++;
				j = 0;
			}
			else
			{
				i++;
				j++;
			};
		}
		else
		{
			i++;
			j = 0;
		};
	};
	printf("the number of entry=%d\n",num);
	scanf("%*s");
	return 0;
}

