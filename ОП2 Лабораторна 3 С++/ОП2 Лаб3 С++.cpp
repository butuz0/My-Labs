#include "Header.h"
#include "book.h"

//input
//size 6
//Рекреації Андрюхов Юрій Ігоровий 1992 240
//Тореадори з Васюківки Нестайко Всеволод Зіновійович 1973 544
//Мина Мазайло Куліш Микола Гурович 1929 141
//Вершники Янковський Юрій Іванович 1935 107
//Гайдамаки Шевченко Тарас Григорович 1841 288
//Тигролови Багряний Іван Павлович 1946 304

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int size;
	cout << "Size of list of books: ";
	cin >> size;
	Book *books = create_list_of_books(size);
	Book biggest_book = find_biggest_book(books, size);
	cout << "Biggest book: "<< biggest_book.get_title() << endl;
}