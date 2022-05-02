#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

class Book;
Book* create_list_of_books(int);
Book find_biggest_book(Book*, int);