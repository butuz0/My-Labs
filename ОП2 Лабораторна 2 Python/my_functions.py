#from datetime import datetime
from employee import Employee
import pickle


# def set_date(frase):
#     day, month, year = input(frase).split(" ")
#     day = int(day)
#     month = int(month)
#     year = int(year)
#     date = datetime
#     date = date(year, month, day)
#     return date
#
#
# def get_date(date):
#     line = f"{str(date.day)}.{str(date.month)}.{str(date.year)}"
#     return line


def veteran(person):
    if person.date_of_employment.year - person.date_of_birth.year <= 25 and 2022 - person.date_of_employment.year >= 10:
        return True
    return False


def current_month_birthday(person):
    if person.date_of_birth.month == 4 and 2022 - person.date_of_employment.year >= 5:
        return True
    return False


def input_file(first_file, size):
    employees = []
    for i in range(size):
        employees.append(Employee())
        employees[i].set_employee()
    print("writing in file 1")
    with open(first_file, "wb") as f:
        for person in employees:
            pickle.dump(person, f)


def output_file(file, size):
    employees = []
    with open(file, "rb") as f:
        for i in range(size):
            employees.append(Employee())
            employees[i] = pickle.load(f)
            print(employees[i].get_employee())


def open_first_file(first_file, size):
    employees = []
    with open(first_file, "rb") as f:
        for i in range(size):
            employees.append(Employee())
            employees[i] = pickle.load(f)
            if current_month_birthday(employees[i]):
                print(employees[i].get_employee())


def create_second_file(first_file, second_file, size):
    employees = []
    with open(first_file, "rb") as f:
        for i in range(size):
            employees.append(Employee())
            employees[i] = pickle.load(f)
            print(employees[i].get_employee())
    new_size = 0
    with open(second_file, "wb") as f:
        for i in range(size):
            if veteran(employees[i]):
                pickle.dump(employees[i], f)
                new_size += 1
    return new_size
