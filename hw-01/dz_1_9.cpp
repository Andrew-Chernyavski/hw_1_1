// Задание 9.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	printf("vvedite chislo\n");
	int a = 0;
	scanf("%d",&a);
	printf("vvedite pokazatel stepeni\n");
	int n = 0;
	scanf("%d",&n);
	int i = 0;
	long int ans = 1;
	for (i = 0; i <= n; i++)
		ans *= a;
	printf("%d ^ %d = %d",a,n,ans);
	scanf("%s*");
	return 0;
}
	

