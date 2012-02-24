// task10.2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
const int length = 50;
const int start = 0;
const int firstSign = 1;
const int intPart = 2;
const int afterDot = 3;
const int fractPart = 4;
const int signOfExp = 5;
const int afterExp = 6;
const int degOfExp = 7;
const int success = 8;
const int fail = 9;

bool sign (char ch)
{
	return ((ch == '+') || (ch == '-'));
}

bool numb (char ch)
{
	return ((ch >= '0') && (ch <= '9'));
}

bool exp (char ch)
{
	return (ch == 'e');
}

bool dot (char ch)
{
	return (ch == '.');
}

bool end (char ch)
{
	return (ch == '\0');
}

int _tmain(int argc, _TCHAR* argv[])
{
	char a[length];
	int pos = 0;
	int i = 0;
	printf("input the string you want to analyse\n");
	scanf("%s", a);
	do
	{
		switch (pos)
		{
		case start:
			if (sign(a[i]))
				pos = firstSign;
			else if (numb(a[i]))
					 pos = intPart;
				 else
					 pos = fail;
			break;
		case firstSign:
			if (numb(a[i]))
				pos = intPart;
			else
				if (end(a[i]))
					pos = fail;
			break;
		case intPart:
			if (!numb(a[i]))
				if (dot(a[i]))
					 pos = afterDot;
				 else
					 if (end(a[i]))
						 pos = success;
					 else
						pos = fail;
			break;
		case afterDot:
			if (numb(a[i]))
				pos = fractPart;
			else
				pos = fail;
			break;
		case fractPart:
			if (!numb(a[i]))
				if (exp(a[i]))
					pos = signOfExp;
					 else if (end(a[i]))
						 pos = success;
						  else
							  pos = fail;
					 
			break;
		case signOfExp:
			if (sign(a[i]))
				pos = afterExp;
			else
				pos = fail;
			break;
		case afterExp:
			if (numb(a[i]))
				pos = degOfExp;
			else pos = fail;
			break;
		case degOfExp:
			if (!numb(a[i]))
				if (end(a[i]))
					pos = success;
				else
					pos = fail;
			break;
		}
		i++;
	}
	while ((pos != success) && (pos != fail));
	if (pos == 8)
		printf("ok, thanks, input something to exit\n");
	else
		printf("there is something wrong, input something to exit\n");
	scanf("%*s");
	return 0;
}

