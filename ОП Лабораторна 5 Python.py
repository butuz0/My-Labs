i = 1

for number in range (10000, 100000):
    
    if i <= 10:
        
        reversed = 0                    #Знаходження оберненого числа
        number1 = number
        while number1 > 0:
            reversed *= 10
            reversed += number1 % 10
            number1 //= 10

            if number == reversed:      #Якщо число дорівнює оберненому числу

                divider=2               #Перевірка на простоту
                while number % divider != 0: 
                    divider += 1

                if number == divider:
                    print (number)
                    i += 1
