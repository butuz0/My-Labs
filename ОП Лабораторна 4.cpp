#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int k, k_max;
	float Greg, Greg_sum = 0, Wal, Wal_sum = 1, pi = 3.14159;

	cout << "k_max = ";
	cin >> k_max;

	for (k = 1; k <= k_max; k++)
	{
		Greg = (pow(-1, k + 1)) / (2 * k - 1);
		Greg_sum += Greg;
	}
	cout << "Число pi за рядом Грегорі = " << Greg_sum * 4 << endl;
	cout << "Ряд Грегорі відрізняється від значення числа pi на  " << abs(pi - Greg_sum*4) << endl;

	for (k = 1; k <= k_max; k++)
	{
		Wal = (4 * pow(k, 2)) / (4 * pow(k, 2) - 1);
		Wal_sum *= Wal;
	}
	cout << "Число pi за добутком Валліса = " << Wal_sum * 2 << endl;
	cout << "Добуток Валліса відрізняється від значення числа pi на " << abs(pi - Wal_sum*2) << endl;

	system("pause");
}
