// ������� 1.cpp : Defines the entry point for the console application.
//
//name: Andrew Chernyavski
//e-mail: andrew.chernyavski@yandex.ru
//Homework 4, task 1

// ���� ��� ������. 
// ����������, ����� ��, ����������� ������� � ������ ������, �������� ������ ������.

// time start: 16.10, 22,56
//time estimation: 3 hours

//time done: 23.21
//time real: 25 minutes

#include "stdafx.h"
#include "time.h"
#include <cstdlib>

int _tmain(int argc, _TCHAR* argv[])
{
	const int num = 10;//���-�� �������� � �������
	char s1[num];
	char s2[num];
	printf("Input the first string\n");//�� ������������ �������,
	gets(s1);							//�.�. ������� ���������� "��������" ������
	printf("Input the second string\n");//��� ������� ��� ����� ��������
	gets(s2);
	
	bool check = true;
	for (int i = 0; i < num; i++)
	{
		int j = 0;
		while (s2[j] != s1[i])
		{
			j++;
			if (j >=num)
			{
				check = false;
				break;
			}
		}
		s2[j] = ' ';//��-� � �������� ��������� "�����������"
		if (!check)
			break;
	}
	if (check)
		printf ("OK");
	else
		printf ("Error");

	scanf("%*s");
	return 0;
}

