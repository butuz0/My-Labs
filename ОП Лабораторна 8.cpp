#include <iostream>
#include <iomanip>
using namespace std;

void dynamicArray(int **arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = new int[size];
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			arr[i][j] = rand() % 10;
		}
	}
}
void printArray(int **arr, int size)
{
	for (int i = 0; i < size; i++) // заполнение массива
	{
		for (int j = 0; j < size; j++)
		{
			cout << setw(2) << arr[i][j];
		}
		cout << endl;
	}
	cout << endl;
}
void bubbleSort(int **arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - 1; j++)
		{
			for (int k = 0; k < size - j - 1; k++)
			{
				if (arr[i][k] < arr[i][k + 1])
				{
					int temp = arr[i][k];
					arr[i][k] = arr[i][k + 1];
					arr[i][k + 1] = temp;
				}
			}
		}
	}
}
void diagonalSort(int **arr, int size)
{
	int j = 0, i = 0;
	for (i; i < size - 1; i++)
	{
		if (arr[i][j] < arr[i + 1][j + 1])
		{
			for (int k = 0; k < size; k++)
			{
				int tmp;
				tmp = arr[i][k];
				arr[i][k] = arr[i + 1][k];
				arr[i + 1][k] = tmp;
			}
		j++;
	}
}

void memoryCleaning(int **arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}


int main()
{
	srand(time(NULL));

	int size;
	cout << "enter size: ";
	cin >> size;

	int** arr = new int* [size];

	dynamicArray(arr, size);  //створення динамічної матриці
	printArray(arr, size);   
	bubbleSort(arr, size);   //сортування рядків матриці за спаданням
	printArray(arr, size);
	diagonalSort(arr, size);  //сортування головної діагоналі матриці за спаданням перестановкою рядків
	printArray(arr, size);
	memoryCleaning(arr, size);
}

