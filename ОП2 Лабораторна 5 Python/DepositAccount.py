from BankAccount import BankAccount
from Date import Date


class DepositAccount(BankAccount):
    __opening_date = Date()
    __period = 0
    __balance = 0.0
    __rate = 0.0

    def __init__(self, attributes):
        super(DepositAccount, self).__init__(attributes)
        self.__balance = float(attributes[2])
        self.__rate = float(attributes[3])
        att_for_date = attributes[4].split('.')
        self.__opening_date = Date(int(att_for_date[0]), int(att_for_date[1]), int(att_for_date[2]))
        self.__period = int(attributes[5])

    def get_opening_date(self):
        return self.__opening_date

    def get_period(self):
        return self.__period

    def get_balance(self):
        return self.__balance

    def get_rate(self):
        return self.__rate

    def add_balance(self, a):
        self.__balance += a

    def sub_balance(self, a):
        self.__balance -= a