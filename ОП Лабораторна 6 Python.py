from math import fabs

def fctrl(a):
	k = 1
	while a > 1:
		k =k*a
		a = a-1
	return k

def result(n, x, eps):
	D = 0
	k = 0	
	t = 1
	while fabs(t) > eps:
		t = (-1)**k/(fctrl(k)*fctrl(k+n))*((x/2)**(2*k+n))
		k += 1
		print (t)
		D += t
	return D

n = int(input("integer n = "))
x = float(input("x = "))
eps = float(input("accuracy eps = "))

print("D =",result(n,x,eps))