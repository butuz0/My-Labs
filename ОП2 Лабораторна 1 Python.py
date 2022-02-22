
def input_file(filename):
    with open(filename, 'w') as infile:
        print("Enter text (Press ctrl+z and enter to finish):")
        try:
            while(True):
                infile.write(input() + "\n")
        except EOFError:
            pass

def output_file(filename):
    with open(filename, 'r') as file:
        lines = file.read().split("\n")
        for i in lines:
            print(i)

def create_second_file(first_file_name, second_file_name):
    with open(first_file_name, 'r') as infile:
        with open(second_file_name, 'w') as outfile:
            lines = infile.read().split("\n")
            for i in lines:
                if i != "":
                    temp = i.replace(";", " ")
                    temp = i.replace(",", " ")
                    words = temp.split()
                    outfile.write(str(count_same(words)) + " " + i + "\n")

def count_same(words):
    amount = 0
    List = []
    for i in range(len(words)):
        already = False
        for j in range (len(List)):
            if words[i] == List[j]:
                already = True
        if already == False and words.count(words[i]) > 1:
            amount += words.count(words[i])
            List.append(words[i])
    amount -= len(List)
    return amount

first_file_name = "first file.txt"
second_file_name = "second file.txt"
input_file(first_file_name)
print("First file:")
output_file(first_file_name)
create_second_file(first_file_name, second_file_name)
print("Second file:")
output_file(second_file_name)