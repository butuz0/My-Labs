#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Date;
struct Employee;
void input_file(string name, int size);
void output_first_file(string);
void output_full_file(string);
void create_second_file(string, string, int);
void output_second_file(string, int);
bool current_month_birthday(Employee);
bool veteran(Employee);