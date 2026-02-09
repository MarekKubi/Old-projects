
#include <iostream>
using namespace std;

double Lagrangere(int n, double* Xt, double* Yt, double x)
{
	double suma = 0;
	double iloczyn = 1;
	for (int i = 0; i < n; i++)
	{
		//suma += Yt[i]*((()())(()()))
		iloczyn = Yt[i];
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
				continue;
			}
			iloczyn = iloczyn * (x - Xt[j]);
		}
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
				continue;
			}
			iloczyn = iloczyn / (Xt[i] - Xt[j]);
		}
		suma += iloczyn;
	}
	return suma;
}

int main()
{
	int n = 5;
	double Xt[] = { -2, -1 , 0, 1, 2 };
	double Yt[] = { 5, -2, 4, -7, 2 };
	int szuk_x = 6;
	for (double j = -2; j <= 2; j += 0.01)
	{
		cout << Lagrangere(n, Xt, Yt, j) << endl;
	}
}