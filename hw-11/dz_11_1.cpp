// task 11.1.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <string>

const int start = 0;
const int OK = 8;
bool run(const char *& word);
bool plmin(const char *&word);
bool mulDiv(const char *&word);
bool brackNum(const char *&word);
enum position { term, sign, digit, point, ex, fail };
const char mas[5][8] =
{
   { 0, 0, 8, 0, 8, 0, 0, 8 },
   { 1, 0, 1, 0, 1, 6, 0, 1 },
   { 2, 2, 2, 4, 4, 7, 7, 7 },
   { 0, 0, 3, 0, 0, 0, 0, 0 },
   { 0, 0, 5, 0, 5, 0, 0, 0 }
};
bool parsing (const char *ch)
{
	return plmin(ch);
}
bool plmin(const char *&ch)
{
    if (!mulDiv(ch))
        return false;
	while ((*ch == '+') || (*ch == '-'))
    {
        ch++;
		if ((*ch == '+') || (*ch == '-'))
			return false;
        if (!mulDiv(ch))
            return false;
    }
	return true;
}
bool mulDiv(const char *&ch)
{
    if (!brackNum(ch))
        return false;
    while ((*ch == '*') || (*ch == '/'))
    {
        ch++;
		if ((*ch == '*') || (*ch == '/') || (*ch == '+') || (*ch == '-'))
			return false;
        if (!brackNum(ch))
            return false;
    }
	return true;
}
bool brackNum(const char *&ch)
{
    if (*ch == '(')
    {
        ch++;
        if (!plmin(ch))
            return false;
        if (*ch != ')')
            return false;
        ch++;
        return true;
    } 
	else 
		return run(ch);
}
position next(const char *&ch)
{
	char now = *ch;
    ch++;

    switch (now)
    {
		case '\0':
			return term;
		case '+':
		case '*':
		case'/':
		case ')':
			ch--;
			return term;
		case '-':
		    return sign;
		case '.':
		    return point;
		case 'e': 
		    return ex;
		default:
		    if ((now >= '0') && (now <= '9'))
		        return digit;
		    return fail;
    }
}
bool run(const char *&ch)
{
	for (int pos = start; ; )
    {
        position sym = next(ch);
        if (sym == fail)
            return false;
		if (pos > mas[sym][pos])
		{
			ch--;
			return true;
		}
        pos = mas[sym][pos];
        if (pos == start)
            return false;
        if (pos == OK)
            return true;
    }
}

int _tmain(int argc, _TCHAR* argv[])
{
	printf("Enter your exprexxion\n");
	std::string h;
	std::getline(std::cin, h);
	if (parsing(h.c_str()))
		printf("all right, input something to exit\n");
	else
		printf("fail, input something to exit\n");
	scanf("%*s");
	return 0;
}

