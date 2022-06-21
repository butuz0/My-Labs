from BankAccount import BankAccount
from Date import Date


class CurrentAccount(BankAccount):
    __last_operation_date = Date()
    __balance = 0.0

    def __init__(self, attributes):
        super(CurrentAccount, self).__init__(attributes)
        self.__balance = float(attributes[2])
        self.__last_operation_date = Date()

    def set_last_operation_date(self, date):
        self.__last_operation_date = date

    def get_last_operation_date(self):
        return self.__last_operation_date

    def get_balance(self):
        return self.__balance

    def add_balance(self, a):
        self.__balance += a

    def sub_balance(self, a):
        self.__balance -= a