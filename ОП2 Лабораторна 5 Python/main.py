from DepositAccount import DepositAccount
from CurrentAccount import CurrentAccount
from Date import Date
from datetime import datetime


def init_arrays(size, currents, deposits):
    print("Enter info about accounts in format\n"
          "For current account: [bank name, id, balance]\n"
          "For deposit account: [bank name, id, balance, rate, dd.mm.yyyy, period]\n"
          "and again...")
    for i in range(size):
        attributes = input().split(',')
        currents.append(CurrentAccount(attributes))
        attributes = input().split(',')
        deposits.append(DepositAccount(attributes))
        print()

    return currents, deposits


def check_deposits(size, currents, deposits):
    now = get_system_date()
    for i in range(size):
        open_date = deposits[i].get_opening_date()
        completed_month = now.get_month_between_dates(open_date)
        if completed_month >= deposits[i].get_period():
            percents = deposits[i].get_period() * (deposits[i].get_balance() * deposits[i].get_rate())
            currents[i].add_balance(deposits[i].get_balance())
            deposits[i].sub_balance(deposits[i].get_balance())
            deposits[i].set_is_available(False)
            open_date.set_month(open_date.get_month() + deposits[i].get_period())
        else:
            percents = completed_month * (deposits[i].get_balance() * deposits[i].get_rate())
            open_date.set_month(open_date.get_month() + completed_month)
        while open_date.get_month() > 12:
            open_date.set_year(open_date.get_year() + 1)
            open_date.set_month(open_date.get_month() - 12)
        currents[i].add_balance(percents)
        currents[i].set_last_operation_date(open_date)


def print_accounts(size, currents, deposits):
    print()
    for i in range(size):
        c = currents[i]
        d = deposits[i]
        last_op = c.get_last_operation_date()
        status = "Available" if d.get_is_available() else "Unavailable"
        print("Pair {}:\n"
              "id: {}"
              "\tbank name: {}"
              "\tdate of last operation: {}"
              "\tbalance: {}"
              "\nid: {}"
              "\tbank name: {}"
              "\tstatus: {}"
              "\tbalance: {}\n"
              .format(str(i + 1), c.get_id(), c.get_bank_name(), last_op.__str__(), c.get_balance(),
                      d.get_id(), d.get_bank_name(), status, d.get_balance()))


def get_system_date():
    current_datetime = datetime.now()
    sys_date = Date(current_datetime.day, current_datetime.month, current_datetime.year)
    return sys_date


n = int(input("Enter the number of bank accounts: "))
current = []
deposit = []
init_arrays(n, current, deposit)
check_deposits(n, current, deposit)
print_accounts(n, current, deposit)
