class Date:
    __year = 1900
    __month = 1
    __day = 1

    def __init__(self, day=1, month=1, year=1900):
        self.__day = day
        self.__month = month
        self.__year = year

    def set_year(self, year):
        self.__year = year

    def set_month(self, month):
        self.__month = month

    def set_day(self, day):
        self.__day = day

    def get_year(self):
        return self.__year

    def get_month(self):
        return self.__month

    def get_day(self):
        return self.__day

    def __str__(self):
        d_str = str(self.__day)
        if self.__day < 10:
            d_str = '0' + str(self.__day)
        m_str = str(self.__month)
        if self.__month < 10:
            m_str = '0' + str(self.__month)
        return "{}.{}.{}".format(d_str, m_str, self.__year)

    def get_month_between_dates(self, other):
        return ((self.__year - other.get_year()) * 12) + self.__month - other.get_month()