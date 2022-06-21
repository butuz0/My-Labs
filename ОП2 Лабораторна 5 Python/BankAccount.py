from abc import ABC, abstractmethod
from datetime import datetime


class BankAccount(ABC):
    __bank_name = ""
    __id = 0
    __is_available = True

    def __init__(self, attributes):
        self.__bank_name = attributes[0]
        self.__id = int(attributes[1])
        self.__is_available = True

    def set_is_available(self, status):
        self.__is_available = status

    def get_bank_name(self):
        return self.__bank_name

    def get_id(self):
        return self.__id

    def get_is_available(self):
        return self.__is_available

    @abstractmethod
    def add_balance(self, a):
        pass

    @abstractmethod
    def sub_balance(self, a):
        pass
