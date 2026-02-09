
#include <iostream>
using namespace std;



double* mult(double A[][5], double* X, int n)
{

	double W[5] = { 0,0,0,0,0 };


	for (int i = 0; i <= n - 1; i++)
	{
		for (int j = 0; j <= n - 1; j++)
		{
			W[i] += A[i][j] * X[j];
		}
	}
	
	cout << "W: ";
	for (int i = 0; i < n; i++)
	{
		cout << W[i] << " ";
	}
	cout << endl;/**/
	return W;
}

double* Dolitle(int n, double A[][3])
{
	bool t = 0;
	for (int i = 0; i < n; i++)
	{
		if (!A[i][i])
		{
			t = 1;
			double swap[3];
			for (int j = 0; j < n; j++)
			{
				swap[j] = A[i][j];
			}
			for (int k = n-1; k >= 0; k--)
			{
				if (A[k][i])
				{
					for (int l = 0; l < n; l++)
					{
							A[i][l] = A[k][l];
							A[k][l] = swap[l];
					}
					t = 0;
					break;
				}
			}
			
		}
	}
	if (t) 
	{
		cout << "NIWLASCIWE A!!!";
		exit(0);
	}
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

	double U[][3] =
	{
		{0,	0,	0},
		{0,	0,	0},
		{0,	0,	0}
	};
	double L[][3] =
	{
		{1,	0,	0},
		{0,	1,	0},
		{0,	0,	1}
	};
	double suma = 0;
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i <= j; i++)
		{
			U[i][j] = A[i][j];
			for (int k = 0; k < i; k++)
			{
				//cout << "J " << j << "I " << i << endl;
				U[i][j] -= (L[i][k] * U[k][j]);
			}
		}
		
		for (int i = j+1; i < n; i++)
		{
			
			for (int k = 0; k < j; k++)
			{
				suma -= (L[i][k] * U[k][j]);
			}
			L[i][j] = ((suma + A[i][j]) / U[j][j]);
			suma = 0;
		}
	}


	cout << "L: " << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << L[i][j] << "	";
		}
		cout << endl;
	}
	cout << endl;


	cout << "U: " << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << U[i][j] << "	";
		}
		cout << endl;
	}
	cout << endl;
	return 0;//mult(A, X, n);;
}


int main()
{
	double A[][3] =
	/*{
		{60,	30,	20},
		{30,	20,	15},
		{20,	15,	12}
	};/**/
	/**/{
		{3,	0,	1},
		{0,	-1,	3},
		{1,	3,	0}
	};/**/

	int n = 3;
	Dolitle(n, A);
}