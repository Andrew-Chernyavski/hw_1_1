// ������� 4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	printf("Vvedite znamenatel (n>1)\n");
	int n = 1;
	scanf("%d",&n);
	for (int i = 2; i <= n; i++)//i - �����������
	{
		for (int j = 1; j < i; j++)//j - ���������
		{
			bool coprime=true;
			int l = 2;
			for (l = 2; l <= i; l++)//�������� ��������� � �����������
				if (( i % l == 0) && (j % l == 0) && (j != 1))
					coprime = false;
			if (coprime)
				printf("%d/%d, ",j,i);
		}
	}
	scanf("%s*");
	return 0;
}

