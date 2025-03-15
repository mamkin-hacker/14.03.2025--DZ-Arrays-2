#include <iostream>
#include <locale>
#include <string>
#include <array>
#include <Windows.h>
#include <vector>
#include <algorithm>
using namespace::std;

int main()
{
	setlocale(LC_ALL, "RU");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	int startNum = 0;
	int endNum = 1;

	cin >> endNum;

	srand(time(0) + clock());

	for (int i = 0; i < startNum; i++)
	{
		int arr1[endNum - 1] = {};

		arr[i] = rand() % (endNum + 1);
		cout << endl << "Ёлемент массива N " << i + 1 << " равен " << arr[i] << endl;
		

	

}