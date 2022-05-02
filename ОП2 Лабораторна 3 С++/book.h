#pragma once
#include "Header.h"

class Book
{
private:
	string author_surname;
	string author_name;
	string author_second_name;
	string book_title;
	int year_of_publication;
	int amount_of_pages;

public:
	void set_book_title(string title)
	{
		book_title = title;
	}
	void set_author(string surname, string name, string second_name)
	{
		author_surname = surname;
		author_name = name;
		author_second_name = second_name;
	}
	void set_year(int year)
	{
		year_of_publication = year;
	}
	void set_pages(int pages)
	{
		amount_of_pages = pages;
	}
	int get_year()
	{
		return year_of_publication;
	}
	int get_pages()
	{
		return amount_of_pages;
	}
	string get_title()
	{
		return book_title;
	}
	string get_author()
	{
		string line;
		line += author_surname + " " + author_name + " " + author_second_name;
		return line;
	}
	string get_book_info()
	{
		string line;
		line += "Title: " + book_title + "; ";
		line += "Author: " + author_surname  + " " + author_name + " " + author_second_name + "; ";
		line += "Year: " + to_string(year_of_publication) + "; ";
		line += "Pages: " + to_string(amount_of_pages);
		return line;
	}
};