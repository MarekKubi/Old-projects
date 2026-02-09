
#include <iostream>
using namespace std;

double WNaturalnyHOR(double x, int punkty, double* tab)
{

	//int x = -4;
	//int punkty = 4;
	//double tab[] = { -2.0,(-1.0) * (13.0 / 6.0),4.0 / 3.0,1.0 / 2.0 };
	double result = 0;
	for (int i = punkty-1; i >= 0; i--)
	{
		result = result * x;
		result += tab[i];

	}

	cout << "Wynik dla x=" << x << " to: " << result << endl;

	//delete tabY;
	return result;
}


double WNewtonaHOR(double x, int punkty, double* tabX, double* tabY)
{

	//int x = 2;
	//int punkty = 4;
	double tmp;
	//double tabX[] = {4,1,0};
	//double tabY[] = { -4,(5.0 / 3.0),(-1.0) * (7.0 / 6.0),1.0 / 2.0 };
	double result = tabY[punkty-1];
	for (int i = punkty - 1; i > 0; i--)
	{
		tmp = x + tabX[i - 1];
		result = result * tmp;
		//cout << "Wynik dla i=" << i << " to: " << result << endl;
		result += tabY[i - 1];

	}

	cout << "Wynik dla x=" << x << " to: " << result << endl;

	//delete tabY;
	return result;
}

/*
double* WNewtonTOnormal(double* result)
{

	int punkty = 4;
	double cary;
	double tabX[] = { 4,1,0 };
	double tabY[] = { -4,(5.0 / 3.0),(-1.0) * (7.0 / 6.0),1.0 / 2.0 };

	for (int i = punkty - 1; i >= 0; i--)
	{
		result[i] = tabX[i]
	}

	cout << "Wynik dla x=" << x << " to: " << result << endl;

	//delete tabY;
	return result;
}*/
int main()
{
	///*
	//double* result = new double[4];
	double x = -1;
	int punkty = 4;
	double tab[] = { -2.0,(-1.0) * (13.0 / 6.0),4.0 / 3.0,1.0 / 2.0 };
	WNaturalnyHOR(x,punkty,tab);

	//*/
	/*
	double x = 0;
	int punkty = 4;
	double tabX[] = { 4,1,0 };
	double tabY[] = { -4,(5.0 / 3.0),(-1.0) * (7.0 / 6.0),1.0 / 2.0 };
	WNewtonaHOR(x, punkty, tabX, tabY);
	*/
	//delete result
}