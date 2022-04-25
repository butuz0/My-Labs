#include "Header.h"
#include "Structures.h"

//input:
//Popov 29 04 1990 31 05 2016
//Habibulaev 03 12 2000 08 01 2021
//Romaniuk 13 04 1997 19 08 2017
//Babuchenko 21 11 1987 25 01 2009
//Chulga 01 06 2001 19 04 2022
//Cherubenko 22 11 1980 09 03 2004
//Muzichuk 01 04 1994 06 10 2013

int main()
{
	string first_file_name = "first file.txt";
	string second_file_name = "second file.txt";

	int size;
	cout << "List size: ";
	cin >> size;
	input_file(first_file_name, size);

	cout << endl << "First file:" << endl;
	output_first_file(first_file_name);

	create_second_file(first_file_name, second_file_name, size);

	cout << endl << "Second file:" << endl;
	output_full_file(second_file_name);
	cout << endl;
}