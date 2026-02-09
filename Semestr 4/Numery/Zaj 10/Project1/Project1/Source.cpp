
#include <math.h>
#include <iostream>
#include <iomanip>
using namespace std;
#define tol pow(10,-10) 

double WNaturalnyHOR(double x, int punkty, double* tab)
{
	double result = 0;
	for (int i = punkty - 1; i >= 0; i--)
	{
		result = result * x;
		result += tab[i];

	}
	return result;
}


double fun1(double x)
{
	return pow(x, 3) + pow(x, 2) + (3*x) - 3;
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
double fun5(double x)
{
	return sin(-x) + exp(-x) - pow(x, 3);
}


bool eup(double (*f)(double),double x1, double x2, int k)
{
	double x3;
	if ((f(x1) < 0) && (f(x2)<0))
	{
		return 0;
	}
	if ((f(x1) > 0) && (f(x2) > 0))
	{
		return 0;
	}
	if ((f(x1) > 0) && (f(x2) < 0))
	{
		x3 = x1;
		x1 = x2;
		x2 = x3;
	}
	x3 = (x1 + x2) / 2.0;
	int i = 0;
	while (!(f(x3) > -tol && f(x3) < tol) && k > i)
	{
		//cout << "i: " << i << endl;
		if (f(x3) < 0)
		{
			x1 = x3;
		}
		else
		{
			x2 = x3;
		}
		x3 = (x1 + x2) / 2.0;
		if ((x1 < 0 && x2 < 0) || (x1 > 0 && x2 > 0))
		{
			//cout << "Niewlasciwe x1 x2" << endl;
			return 0;
		}
		i++;
	}
	cout << setprecision(15) << "Miejsce zerowe: " << x3 <<endl << "Wartosc: " << f(x3) << endl;
	return 1;
}
// T0 = 1200
// 300s

int main()
{
	srand(time(NULL));
	int k = 10;
	double a  = -(k/2);
	double s = 100;
	double h = 1.0 / s;
	for (int i = 0; i < (k * s * 2); i++)
	{
		//cout << "a: " << a << endl;
		if (eup(fun1, a, a+h, 1000))
		{
			break;
		}
		a += h / 2.0;
	}
	return 0;
}