#include <iostream>
#include <locale>
#include <string>
#include <array>
#include <Windows.h>
#include <vector>
#include <algorithm>
#include <typeinfo>
using namespace::std;

int main()
{
	setlocale(LC_ALL, "RU");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	int Num = 0;

	cout << "Введи число от 0 до 99 включительно: ";
	cin >> Num;

	while (cin.fail())
	{
		cin.clear();
		Num = 0;
		cout << "Твое введеное значение не число!" << endl;
		cout << endl << "Введи число от 0 до 99 включительно: ";
		cin.ignore(3);
		cin >> Num;

	}

	while (Num > 99)
	{

		cin.clear();
		Num = 0;
		cout << "Твое число превышает диапазон!" << endl;
		cout << endl << "Введи число от 0 до 99 включительно: ";
		cin >> Num;

	}

	srand(time(0) + clock());

	int arr1[99];
	int arr2[99];

	int count1 = 0;
	int count2 = 0;

	cout << endl << "Первый массив - [ ";
	for (int i = 0; i < Num; i++)
	{
		arr1[i] = rand() % (Num + 1);
		count1 = count1 + arr1[i];
		cout << arr1[i] << " ";

	}
	cout << " ]. Cумма элементов равна ";
	cout << count1;

	cout << endl << "Второй массив - [ ";
	for (int j = 0; j < Num; j++)
	{
		arr2[j] = rand() % (Num + 1);
		count2 = count2 + arr2[j];
		cout << arr2[j] << " ";

	}
	cout << " ]. Cумма элементов равна ";
	cout << count2;

	if (count1 > count2)
	{
		int arrSummary[198];
		for (int k = 0; k < Num; k++)
		{
			arrSummary[k] = arr1[k];
			arrSummary[k + Num] = arr2[k];
		}

		cout << endl << "Третий массив - [ ";
		for (int e = 0; e < 2 * Num; e++)
		{
			cout << arrSummary[e] << " ";
		}
		cout << " ]" << endl;
	}
	else if (count1 < count2)
	{
		int arrSummary[198];
		for (int k = 0; k < Num; k++)
		{
			arrSummary[k] = arr2[k];
			arrSummary[k + Num] = arr1[k];
		}

		cout << endl << "Третий массив - [ ";
		for (int e = 0; e < 2 * Num; e++)
		{
			cout << arrSummary[e] << " ";
		}
		cout << " ]" << endl;
	}
	else
	{
		cout << endl << "Третий массив - [ 0 0 ] ";
	}


}
