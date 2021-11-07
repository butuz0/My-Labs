#include <iostream>

using namespace std;

int main()
{
    int number, i = 1;

    for (number = 10000; number < 100000; number++) 
    {
        if (i <= 10)
        {
            int reversed = 0, number1;           //Знаходження оберненого числа
            number1 = number;

            while (number1 > 0)
            {
                reversed *= 10;
                reversed += number1 % 10;
                number1 /= 10;
            }
            if (number == reversed)          //Якщо число дорівнює оберненому числу
            {
                 int divider = 2;            //Перевірка на простоту
                 while (number % divider != 0)
                     divider++;
                 if (divider == number)
                 {
                     cout << number << endl;
                     i++;
                 }
            }
        }
    }
    system("pause");
}