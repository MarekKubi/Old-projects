
#include <iostream>
using namespace std;


void wiersz(int x, int y, int n, double A[][5], double* B)
{
	double wsp = A[y][x] / A[0][x];
	for (int i = n - 1; i >= x; i--)
	{
		A[y][i] = A[y][i] - (A[0][i] * wsp);
	}
	A[y][x] = 0;
	B[y] = B[y] - (B[0] * wsp);
}

void El(int x, double A[][5], int n, double* B)
{
	for (int i = n - 1; i > x; i--)
	{
		wiersz(x, i, n, A, B);
	}
}


double* mult(double A[][5], double* X, int n)
{

	double W[5];


	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			W[i] += A[i][j] * X[j];
		}
	}

	cout << "W: ";
	for (int i = 0; i < n - 1; i++)
	{
		cout << W[i] << " ";
	}
	cout << endl;
	return W;
}

double* ElimG(int n, double A[][5], double* B)
{
	for (int i = 0; i < n - 1; i++)

		El(i, A, n, B);
}
double X[5] = { 0,0,0,0,0 };



cout << "A: " << endl;
for (int i = 0; i < n; i++)
{
	for (int j = 0; j < n; j++)
	{
		cout << A[i][j] << "	";
	}
	cout << endl;
}
cout << endl;

for (int i = n - 1; i >= 0; i--)
{
	X[i] = B[i];
	for (int j = n - 1; j > i; j--)
	{
		X[i] -= A[i][j] * X[j];
	}
	X[i] = X[i] / A[i][i];
}
cout << "X: ";
for (int i = 0; i < n - 1; i++)
{
	cout << X[i] << " ";
}
cout << endl;



return mult(A, X, n);;
}


int main()
{
	double A[][5] =
	{
		{1,		-3,		4,		6.8,	9},
		{-3,	2,		4.6,	6.43,	-10 },
		{2,		-1,		2.8,	-8.4,	-5},
		{-6,	2,		7,		-0.5,	-0.9},
		{5,		-2,		-0.5,	12,		-4},

	};
	double B[5] = { 74.54,		-40.26,		-2.32,		12.6,	-8.9 };
	int n = 5;
	ElimG(n, A, B);
}