#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

int arraySize(string s)
{
    int count = 0, size = 0;
    while (count < s.length())
    {
        if (s[count] != ' ')
        {
            size++;
            while (s[count] != ' ' && count < s.size())
            {
                count++;
            }
        }
        else {
            while (s[count] == ' ' && count < s.size())
            {
                count++;
            }
        }
    }
    return size;
}
void generateArray(string s, int* arr, int size)
{
    string rez;
    int pos;
    for (int i = 0; i < size; i++)
    {
        pos = s.rfind(' ');
        if (pos == -1)
        {
            arr[i] = atoi(s.c_str());
            return;
        }
        rez = s.substr(pos + 1);
        arr[i] = atoi(rez.c_str());
        for (int j = pos; j < s.size(); ++j)
        {
            s.erase(j);
        }
        pos--;
        while (s[pos] == ' ')
        {
            s.erase(pos);
            pos--;
        }
    }
}
void printArray(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void bubbleSort(int* arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string s;
    cout << "Введіть ряд чисел: ";
    getline(cin, s);
    int size = arraySize(s);
    int* arr = new int[size];
    generateArray(s, arr, size);
    cout << "Масив введених чисел: ";
    printArray(arr, size);
    bubbleSort(arr, size);
    cout << "Відсортований масив: ";
    printArray(arr, size);
    delete[] arr;
}