// task2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	const long long lim = 3*10e10;
	double num = 1;
	while (num != 0)
	{
		cout << "input the number or input ""0"" to exit\n";
		cin >> num;
		if (num != 0)
		{
			int k = sizeof (num)/sizeof (char);//8
			int exp = ((*((unsigned char *)(&num) + k-1) & 0177) * 16) + ((*((unsigned char *)(&num) + k-2) & ~017) >>4) - 1023;//степень двойки
			int i = k - 3;
			long long bin = (*((unsigned char *)(&num) + k-2) & 017) + 16;//бинарный вид
			while (i >= 0)
			{
				bin = (bin * 256) + *((unsigned char *)(&num) + i);
				i--;
			}
			bin *= 32;
			long long mask = 0x1000000000000000;//маска
			while (!(bin & mask) && bin)
				mask >>= 1;
			bin &= ~mask;
			mask >>= 1;
			long long mant = 10;//мантисса
			long long expon = 5;//для возведения в степень (*5/10)
			while (bin && expon < lim)
			{
				mant += (((bool)(bin & mask))* expon);
				expon *= 5;
				mant *= 10;
				bin <<= 1;
			}

				bool sign = *((unsigned char *)(&num) + k-1) >> 7;//знак входного числа
				char ch = ' ';//и его вывод
				if (sign)
					ch = '-';

				long long cmp = 1;//для вывода единственного знака до точки
				while (mant > cmp)  
					cmp *= 10;
				if (cmp != mant)
					cmp /= 10;

				if (exp > 0)
					while (mant < cmp * 5 && exp)
					{
						mant *= 2;
						exp--;
					}

				cout << ch << (mant / cmp) << ".";
				while (mant >= cmp)
				{
					mant -= cmp;
				}
				if (mant)
				{
					while (cmp/mant > 10)
					{
						cout << "0";
						cmp /= 10;
					}
					cout << mant;
				}
				else 
					cout << "00";
				if (exp)
					cout << "x2^(" << exp << ")" << endl;
				else
					cout << "00" << endl;
			}
			else
				return 0;
	}
	return 0;
}