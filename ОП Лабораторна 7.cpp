#include <iostream>
#include <stdlib.h>
using namespace std;

void fillArray(int arr[], const int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = rand()%10+1;
	}
}
void printArray(int arr[], const int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		cout << arr[i] << " ";
	}
}
void unique(int arr1[], int arr2[], const int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (arr2[i] == arr1[j])
				arr1[j] = 0;
		}
	}
}

int main()
{
	srand(time(NULL));

	const int SIZE = 10;
	int arr1[SIZE], arr2[SIZE];

	fillArray(arr1, SIZE); 
	printArray(arr1, SIZE);  //створення й виведення масиву А
	cout << endl;

	fillArray(arr2, SIZE);
	printArray(arr2, SIZE);  //створення й виведення масиву В
	cout << endl;

	unique(arr1, arr2, SIZE);  //виведення масиву А з елементами, яких немає в масиві В
	printArray(arr1, SIZE);

	system("pause");
}