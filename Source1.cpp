#include <iostream>
#include <locale>
#include <array>
#include <Windows.h> // не работает setConsole
using namespace::std;

int main()
{
	setlocale(LC_ALL, "RU");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	int Num = 0;

	cout << "Приветсвуем в программе по генерации двух случайных массивов чисел, объединяемых в третий общий массив (первых местах идут элементы большего массива)!" << endl;

	cout << endl << "Введи число от 0 до 99 включительно: "; // в принципе, это формальное ограничение - можно и увеличить
	cin >> Num;

	while (cin.fail())
	{
		cin.clear();
		Num = 0;
		cout << "Твое введеное значение не число!" << endl;
		cout << endl << "Введи число от 0 до 99 включительно: ";
		//cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');// 
		cin.ignore((numeric_limits<streamsize>::max)(), '\n'); //игнорируем ввод "Нечисла" + хак со скобкой - для ограничения области видимости (не даёт расширять макросы с параметрами).
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

	int* arr1 = new int [Num];
	int* arr2 = new int [Num];

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
		int* arrSum = new int[Num*2];
		for (int k = 0; k < Num; k++)
		{
			arrSum[k] = arr1[k];
			arrSum[k + Num] = arr2[k];
		}

		cout << endl << "Третий массив - [ ";
		for (int e = 0; e < 2 * Num; e++)
		{
			cout << arrSum[e] << " ";
		}
		cout << " ]" << endl;
		delete[] arrSum;
	}
	else if (count1 < count2)
	{
		int* arrSum = new int[Num * 2];
		for (int k = 0; k < Num; k++)
		{
			arrSum[k] = arr2[k];
			arrSum[k + Num] = arr1[k];
		}

		cout << endl << "Третий массив - [ ";
		for (int e = 0; e < 2 * Num; e++)
		{
			cout << arrSum[e] << " ";
		}
		cout << " ]" << endl;
		delete[] arrSum;
	}
	else
	{
		cout << endl << "Третий массив - [ 0 0 ] ";
	}
	delete[] arr1;
	delete[] arr2;

	return 0;
}
