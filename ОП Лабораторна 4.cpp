#include <iostream>
#include <Windows.h>
#include <math.h>

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int k, k_max;
	float Greg, Greg_result = 0, Wal, Wal_result = 1, pi = 3.14159;

	cout << "k_max = ";
	cin >> k_max;

	for (k = 1; k <= k_max; k++)		// пошук pi за рядом Грегорі
	{
		Greg = (pow(-1, k - 1)) / (2 * k - 1);    // в варіанті лабораторної помилка в формулі, тут правильно
		Greg_result += Greg;
	}
	cout << "Число pi за рядом Грегорі = " << Greg_result * 4 << endl;
	cout << "Ряд Грегорі відрізняється від значення числа pi на  " << abs(pi - Greg_result * 4) << endl;

	for (k = 1; k <= k_max; k++)		// пошук pi за добутком Валліса
	{
		Wal = (4 * pow(k, 2)) / (4 * pow(k, 2) - 1);
		Wal_result *= Wal;
	}
	cout << "Число pi за добутком Валліса = " << Wal_result * 2 << endl;
	cout << "Добуток Валліса відрізняється від значення числа pi на " << abs(pi - Wal_result * 2) << endl;

	system("pause");
}
