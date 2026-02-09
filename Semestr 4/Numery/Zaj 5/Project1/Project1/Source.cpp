
#include <math.h>
#include <iostream>
using namespace std;

double fun1( double x)
{
	return pow(x, 2) * pow(sin(x), 3);
}
double fun2(double x)
{
	if (!x)
	{
		return 1;
	}
	return (sin(x) / x);
}
double fun3(double x)
{
	return (x - 1) * exp(pow(x, 2));
}
double fun4(double x)
{
	return sin(1 / x);
}

double trap(double a, double b, double (*f)(double))
{
	return ((b - a) / 2) * (f(a) + f(b));
}
double simp(double a, double b, double (*f)(double))
{
	return ((b - a) / 6) * (f(a) + 4*f((a+b)/2) + f(b));
}

double quad(double (*f)(double), double a, double b, double h, bool t)
{
	bool pl = 1;
	if (b < a)
	{
		pl = 0;
		double tmp = b;
		b = a;
		a = tmp;
	}
	double suma = 0;
	double h0 = a;
	while((h0+h)<b)
	{
		if (t)
		{
			suma += trap(h0, h0 + h, f);
		}
		else 
		{
			suma += simp(h0, h0 + h, f);
		}
		h0 = h0 + h;
		//cout << h0 << endl;
	}
	if (t)
	{
		suma += trap(h0, b, f);
	}
	else
	{
		suma += simp(h0, b, f);
	}
	if (pl)
	{
		return suma;
	}
	else 
	{
		return suma*(-1);
	}
}


int main()
{
	double (*f)(double);
	
	//cout << quad(f, 0, 4.5, pow(10,-3), 0) << endl;
	f = fun1;
	cout << "h	t		s" << endl;
	for (int i = -2; i >= -6; i--)
	{
		cout << pow(10, i)<<"	" << quad(f, 0, 4.5, pow(10, i), true) << "	" << quad(f, 0, 4.5, pow(10, i), false) << endl;
	}
	f = fun2;
	cout << "h	t		s" << endl;
	for (int i = -2; i >= -6; i--)
	{
		cout << pow(10, i) << "	" << quad(f, 0, 1, pow(10, i), true) << "	" << quad(f, 0, 1, pow(10, i), false) << endl;;
	}
	f = fun3;
	cout << "h	t		s" << endl;
	for (int i = -2; i >= -6; i--)
	{
		cout << pow(10, i) << "	" << quad(f, -2, 2, pow(10, i), true) << "	" << quad(f, -2, 2, pow(10, i), false) << endl;
	}
	f = fun4;
	cout << "h	t		s" << endl;
	for (int i = -2; i >= -6; i--)
	{
		cout << pow(10, i) << "	" << quad(f, pow(10,-4), 1, pow(10, i), true) << "	" << quad(f, pow(10, -4), 1, pow(10, i), false) << endl;
	}
}