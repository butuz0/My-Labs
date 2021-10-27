import math

x=float(input("x = "))
eps=float(input("eps = "))

Sh = 0
n = 0
t = (x**(2*n+1))/(math.factorial(2*n+1))

while (t > eps):
    t = (x**(2*n+1))/(math.factorial(2*n+1))
    Sh += t
    n += 1
    print (t)
else:
    print ("Sh= ",Sh)