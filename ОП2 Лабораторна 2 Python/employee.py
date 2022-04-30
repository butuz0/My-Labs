#from my_functions import *
from datetime import datetime

"""for some reason class function set_employee doesn't see 
functions set_date and get_date if they're are imported from 
my_functions file, so they are defined here"""


def set_date(frase):
    day, month, year = input(frase).split(" ")
    day = int(day)
    month = int(month)
    year = int(year)
    date = datetime
    date = date(year, month, day)
    return date


def get_date(date):
    line = f"{str(date.day)}.{str(date.month)}.{str(date.year)}"
    return line


class Employee:
    surname = str
    date_of_birth = datetime
    date_of_employment = datetime

    def set_employee(self):
        self.surname = input("Surname: ")
        self.date_of_birth = set_date("Date of birth: ")
        self.date_of_employment = set_date("Date of employment: ")

    def get_employee(self):
        birth = get_date(self.date_of_birth)
        employment = get_date(self.date_of_employment)
        info = f"Surname: {self.surname}; Date of birth: {birth}; Date of employment: {employment}"
        return info
