s = input("Введіть ряд чисел: ")
arr = s.split()
arr = [int(el) for  el in arr]
print("Масив введених чисел: ", arr)
arr.sort()
print("Відсортований масив: ", arr)