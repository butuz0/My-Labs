#include "Header.h"
#include "Structures.h"

void input_file(string name, int size)
{
	ofstream fileout;
	fileout.open(name, ios::binary);

	if (!fileout.is_open())
	{
		cout << "ERROR" << endl;
	}
	else
	{
		Employee* person = new Employee[size];
		for (int i = 0; i < size; i++)
		{
			person[i].create_employee_struct();
			fileout.write((char*)&person[i], sizeof(Employee));
		}

	}
	fileout.close();
}
void output_first_file(string name)
{
	ifstream filein;
	filein.open(name, ios::binary);

	Employee person;
	if (!filein.is_open())
	{
		cout << "ERROR";
	}
	else
	{
		while (filein.read((char*)&person, sizeof(Employee)))
		{
			if (current_month_birthday(person))
			{
				cout << person.get_employee() << endl;
			}
		}
	}
	filein.close();
}
void output_file(string name)
{
	ifstream filein;
	filein.open(name, ios::binary);

	Employee person;
	if (!filein.is_open())
	{
		cout << "ERROR";
	}
	else
	{
		while (filein.read((char*)&person, sizeof(Employee)))
		{
			cout << person.get_employee() << endl;
		}
	}
	filein.close();
}
void create_second_file(string filein_name, string fileout_name, int size)
{
	ifstream filein;
	ofstream fileout;
	filein.open(filein_name, ios::binary);
	fileout.open(fileout_name, ios::binary);

	if (!filein.is_open() || !fileout.is_open())
	{
		cout << "ERROR";
	}
	else
	{
		Employee* person = new Employee[size];
		for (int i = 0; i < size; i++)
		{
			filein.read((char*)&person[i], sizeof(Employee));
			if (veteran(person[i]))
			{
				fileout.write((char*)&person[i], sizeof(Employee));
			}
		}
	}
	filein.close();
	fileout.close();
}
bool current_month_birthday(Employee person)
{
	if (person.date_of_birth.month == 4 && 2022 - person.date_of_employment.year >= 5)
		return true;
	else
		return false;
}
bool veteran(Employee person)
{
	if (person.date_of_employment.year - person.date_of_birth.year <= 25 &&
		2022 - person.date_of_employment.year >= 10)
		return true;
	else
		return false;
}