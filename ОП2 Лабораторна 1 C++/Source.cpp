#include "Header.h"

void input_file(string name)
{
	ofstream fileout;
	fileout.open(name);

	if (!fileout.is_open()) 
	{
		cout << "ERROR";
	}
	else 
	{
		string line;
		cout << "Enter text (Press ctrl+z and enter to finish):"<<endl;
		while (true)
		{
			getline(cin, line);
			fileout << line << endl;
			if (cin.eof())
			{
				break;
			}
		}
	}
	fileout.close();
}
void output_file(string name)
{
	ifstream filein;
	filein.open(name);

	if (!filein.is_open()) 
	{
		cout << "ERROR";
	}
	else 
	{
		string line;
		while (!filein.eof()) 
		{
			getline(filein, line);
			cout << line << endl;
		}
	}

	filein.close();
}
void create_second_file(string filein_name, string fileout_name)
{
	ifstream filein;
	ofstream fileout;
	filein.open(filein_name);
	fileout.open(fileout_name);

	if (!filein.is_open() || !fileout.is_open())
	{
		cout << "ERROR";
	}
	else
	{
		string line;
		while (!filein.eof())
		{
			getline(filein, line);
			if (!line.empty()) 
			{
				line = count_same(line);
				fileout << line << endl;
			}
		}
	}
	filein.close();
	fileout.close();
}
bool isnt_spec_symbol(char a)
{
	char arr[3]{ ',' , ';' , ' ' };
	for (int i = 0; i < 3; i++)
	{
		if (a == arr[i])
		{
			return false;
		}
	}
	return true;
}
string count_same(string arr)
{
	arr += " ";
	string s, arr1 = arr;
	int amount = 0;
	for (int i = 0; i < arr.length(); i++)
	{
		if (isnt_spec_symbol(arr[i]))
		{
			s += arr[i];
		}
		else
		{
			if (isalpha(s[0]))
			{
				int n = arr1.rfind(s);
				if (n == arr1.find(s))
				{
					s.clear();
					continue;
				}
				int m = s.length() + 1;
				arr1.replace(n, m, "");
				amount++;
			}
			s.clear();
		}
	}
	string str = to_string(amount);
	str += " ";
	str += arr;
	return str;
}