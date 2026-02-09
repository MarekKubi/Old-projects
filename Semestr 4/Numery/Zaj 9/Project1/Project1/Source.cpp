
#include <math.h>
#include <iostream>
#include <iomanip>
using namespace std;


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
double fun5(double x)
{
	return sin(-x) + exp(-x) - pow(x, 3);
}

void eu(int kroki, double a, double b, double T, double alp, double bet)
{
	double h = (b - a) / kroki;
	for (int i = 0; i < kroki; i++)
	{
		//cout << T << endl;
		T += alp * h *(pow(T, 4) - bet);
	}
	cout << setprecision(15) << T << endl;
}

void Hanu(int kroki, double a, double b, double T, double alp, double bet)
{
	double h = (b - a) / kroki;
	for (int i = 0; i < kroki; i++)
	{
		//cout << T << endl;
		T +=  h * ((alp * (pow(T, 4) - bet)) + (alp*(T + alp * h * (pow(T, 4) - bet))));
	}
	cout << setprecision(15) << T << endl;
}

void eup(int kroki, double a, double b, double T, double alp, double bet)
{
	double h = (b - a) / kroki;
	for (int i = 0; i < kroki; i++)
	{
		//cout << setprecision(15) << T << endl;
		T += alp * h * (pow(T + ((1.0/2.0)* alp * h * (pow(T, 4) - bet)),4) -bet);
	}
	cout <<setprecision(15) <<T << endl;
}
// T0 = 1200
// 300s

int main()
{
	cout << "Euler: ";
	eu(3000, 0, 300, 1200, -1 * pow(10, -12), 0);
	cout <<endl<< "Hanu: ";
	Hanu(3000, 0, 300, 1200, -1 * pow(10, -12), 0);
	cout << endl << "Euler zmod: ";
	eup(3000, 0, 300, 1200, -1 * pow(10, -12), 0);
	return 0;
}