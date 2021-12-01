#include <iostream>
#include <math.h>
using namespace std;

double fctrl(double a)
{
	double k = 1;
	while (a > 1)
	{
		k *= a;
		a--;
	}
	return k;
}

double result(double n, double x, double eps)
{
	double k = 0, t, D = 0;

	do
	{
		t = (pow(-1, k) / (fctrl(k) * fctrl(n + k)) * pow((x / 2), (2 * k + n)));
		cout << t << endl;
		D += t;
		k++;
	}
	while (fabs(t) > eps);

	return D;
}

int main()
{
	double n, x, eps;

	cout << "integer n = ";
	cin >> n;
	cout << "x = ";
	cin >> x;
	cout << "accuracy eps = ";
	cin >> eps;

	cout<<"D = "<< result(n, x, eps) << endl;

	system("pause");
}