#include <iostream>
using namespace std;

double Lagrangere(int n, double* Xt, double* Yt, double x)
{
	double suma = 0;
	double iloczyn = 1;
	for (int i = 0; i < n; i++)
	{
		iloczyn = Yt[i];
		for (int j = 0; j < n; j++)
		{
			if (i != j)
			{
				iloczyn = iloczyn * (x - Xt[j]);
			}
		}
		for (int j = 0; j < n; j++)
		{
			if (i != j)
			{
				iloczyn = iloczyn / (Xt[i] - Xt[j]);
			}
		}
		suma += iloczyn;
	}
	cout << "suma: " << suma << endl;
	return suma;
}

int main()
{
	int n = 5;
	double Xt[] = { -2.0, -1.0 , 0.0, 1.0, 2.0 };
	double Yt[] = { 5.0, -2.0, 4.0, -7.0, 2.0 };
	double szuk_x = -2.0;
	cout << "Wynik: " << Lagrangere(n, Xt, Yt, szuk_x) << endl;
}