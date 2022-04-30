from my_functions import *

# input
# size 7
# Popov 29 04 1990 31 05 2016
# Habibulaev 03 12 2000 08 01 2021
# Romaniuk 13 04 1997 19 08 2017
# Babuchenko 21 11 1987 25 01 2009
# Chulga 01 06 2001 19 04 2022
# Cherubenko 22 11 1980 09 03 2004
# Muzichuk 01 04 1994 06 10 2013


first_file = "first_file.txt"
second_file = "second_file.txt"

size = int(input("List size: "))

input_file(first_file, size)

print("First file:")
open_first_file(first_file, size)

new_size = create_second_file(first_file, second_file, size)

print("Second file:")
output_file(second_file, new_size)
