#pragma once
#include "Header.h"

struct Date
{
	int day, month, year;
	void set_date()
	{
		cin >> day;
		cin >> month;
		cin >> year;
	}
	string get_date()
	{
		string line;
		line += to_string(day) + ".";
		line += to_string(month) + ".";
		line += to_string(year);

		return line;
	}
};
struct Employee
{
	string surname;
	Date date_of_birth{}, date_of_employment{};
	void create_employee_struct()
	{
		cin >> surname;
		date_of_birth.set_date();
		date_of_employment.set_date();
	}
	string get_employee()
	{
		string line;
		line += "Surname: " + surname + "; ";
		line += "Date of birth: " + date_of_birth.get_date() + "; ";
		line += "Date of employment: " + date_of_employment.get_date();

		return line;
	}
};