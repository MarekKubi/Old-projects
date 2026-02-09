
#include <math.h>
#include <iostream>
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

double trap(double a, double b, double (*f)(double))
{
	return ((b - a) / 2) * (f(a) + f(b));
}
double simp(double a, double b, double (*f)(double))
{
	return ((b - a) / 6) * (f(a) + 4 * f((a + b) / 2) + f(b));
}

double g5(double h0, double h, double (*f)(double))
{
	double suma = 0;

	double aaa = pow((10.0 / 7.0), (1.0 / 2.0));

	suma += f(h0 + (h / 2.0)) * (128.0 / 225.0);
	double dif1 = (1.0 / 3.0) * pow((5.0 - (2.0 * aaa)), (1 / 2));
	double dif2 = (1.0 / 3.0) * pow((5.0 + (2.0 * aaa)), (1 / 2));

	suma += f(h0 + (h / 2) - (h / 2) * dif1) * ((322 + (13 * pow(70.0, (1.0 / 2.0)))) / 900.0);
	suma += f(h0 + (h / 2) + (h / 2) * dif1) * ((322 + (13 * pow(70.0, (1.0 / 2.0)))) / 900.0);


	suma += f(h0 + (h / 2) - (h / 2) * dif2) * ((322 - (13 * pow(70.0, (1.0 / 2.0)))) / 900.0);
	suma += f(h0 + (h / 2) + (h / 2) * dif2) * ((322 - (13 * pow(70.0, (1.0 / 2.0)))) / 900.0);
	//cout << "suma = " << suma << endl;
	return suma;
}
double gh5(double h0, double h, double* tab1, double* tab2, int p)
{
	double suma = 0;

	double aaa = pow((10.0 / 7.0), (1.0 / 2.0));

	suma += WNaturalnyHOR(h0 + (h / 2.0), p, tab1) * WNaturalnyHOR(h0 + (h / 2.0), p, tab2) * (128.0 / 225.0);
	double dif1 = (1.0 / 3.0) * pow((5.0 - (2.0 * aaa)), (1 / 2));
	double dif2 = (1.0 / 3.0) * pow((5.0 + (2.0 * aaa)), (1 / 2));

	suma += WNaturalnyHOR(h0 + (h / 2) - (h / 2) * dif1, p, tab1) * WNaturalnyHOR(h0 + (h / 2) - (h / 2) * dif1, p, tab2) * ((322 + (13 * pow(70.0, (1.0 / 2.0)))) / 900.0);
	suma += WNaturalnyHOR(h0 + (h / 2) + (h / 2) * dif1, p, tab1) * WNaturalnyHOR(h0 + (h / 2) + (h / 2) * dif1, p, tab2) * ((322 + (13 * pow(70.0, (1.0 / 2.0)))) / 900.0);


	suma += WNaturalnyHOR(h0 + (h / 2) - (h / 2) * dif2, p, tab1) * WNaturalnyHOR(h0 + (h / 2) - (h / 2) * dif2, p, tab2) * ((322 - (13 * pow(70.0, (1.0 / 2.0)))) / 900.0);
	suma += WNaturalnyHOR(h0 + (h / 2) + (h / 2) * dif2, p, tab1) * WNaturalnyHOR(h0 + (h / 2) + (h / 2) * dif2, p, tab2) * ((322 - (13 * pow(70.0, (1.0 / 2.0)))) / 900.0);
	//cout << "suma = " << suma << endl;
	return suma;
}
double gaus(double (*f)(double), double a, double b, int N, double (*g)(double, double, double (*f)(double)))
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
	double h = (b - a) / N;
	for (int i = 0; i < N; i++)
	{
		suma += g(h0, h, f) * (h / 2);
		h0 = h0 + h;
	}
	if (pl)
	{
		return suma;
	}
	else
	{
		return suma * (-1);
	}
}

double gaush(double* tab1, double* tab2, int p, double a, double b, int N, double (*g)(double, double, double*, double*, int))
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
	double h = (b - a) / N;
	for (int i = 0; i < N; i++)
	{
		suma += g(h0, h, tab1, tab2, p) * (h / 2);
		h0 = h0 + h;
	}
	if (pl)
	{
		return suma;
	}
	else
	{
		return suma * (-1);
	}
}

void Gramm_shh(double f[5][5], double g[5][5], int punkty, int a, int b)
{
	for (int j = 0; j < punkty; j++)
	{
		g[0][j] = f[0][j];
	}
	double wsp;
	for (int i = 1; i < punkty; i++)
	{
		for (int j = 0; j < i; j++)
		{
			wsp = (gaush(f[i], g[j], punkty, a, b, 500, gh5) / gaush(g[j], g[j], punkty, a, b, 500, gh5));
			cout << "Wsp[" << i << "][" << j << "] = " << wsp << "\t";
			//cout << "G: " << gaush(f[i], g[j], punkty, a, b, 500, gh5) << " : " << gaush(g[j], g[j], punkty, a, b, 500, gh5);
			for (int k = 0; k < punkty; k++)
			{
				g[i][k] -= wsp * g[j][k];
			}
		}
		cout << endl;
		for (int j = 0; j < punkty; j++)
		{
			g[i][j] += f[i][j];
		}
	}
}

void czydz(double f[5])
{
	for (int j = 0; j < 5; j++)
	{
		cout << f[j] << "\t";
	}
}


int main()
{

	int punkty = 5;
	double tab1[] = { -2.0, 1.0 , 2.0, 1.0 };
	double tab2[] = { 10.0, -1.0 , 1.0, 2.0 };
	//cout << quad(f, 0, 4.5, pow(10,-3), 0) << endl



	double f[5][5]
	{
		1,0,0,0,0,
		0,1,0,0,0,
		0,0,1,0,0,
		0,0,0,1,0,
		0,0,0,0,1
	};
	double g[5][5]
	{
		0,0,0,0,0,
		0,0,0,0,0,
		0,0,0,0,0,
		0,0,0,0,0,
		0,0,0,0,0
	};


	//czydz(f[2]);

	Gramm_shh(f, g, punkty, 0, 1);
	for (int i = 0; i < punkty; i++)
	{
		for (int j = 0; j < punkty; j++)
		{
			cout << g[i][j] << "\t\t\t";
		}
		cout << endl;
	}
	return 0;
}