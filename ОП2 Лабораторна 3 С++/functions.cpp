#include "Header.h"
#include "book.h"

Book* create_list_of_books(int size)
{
	Book* books = new Book[size];

	for (int i = 0; i < size; i++)
	{
		string title;
		string name, second_name, surname;
		int year, pages;

		cout << "Input book title: ";
		getline(cin >> ws, title);
		books[i].set_book_title(title);

		cout << "Input book information (Author, year, pages): ";
		cin >> surname;
		cin >> name;
		cin >> second_name;
		cin >> year;
		cin >> pages;
		books[i].set_author(surname, name, second_name);
		books[i].set_year(year);
		books[i].set_pages(pages);
	}
	return books;
}
Book find_biggest_book(Book *books, int size)
{
	int first_year, second_year;
	cout << "Enter year diapason: ";
	cin >> first_year;
	cin >> second_year;

	Book biggest_book;
	int max_pages = 0;
	for (int i = 0; i < size; i++)
	{
		if (books[i].get_year() >= first_year && books[i].get_year() <= second_year && books[i].get_pages() > max_pages)
		{
			max_pages = books[i].get_pages();
			biggest_book = books[i];
		}
	}
	return biggest_book;
}