#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include<cmath>
#include <chrono>  
#include <windows.h>  
#include <thread>

using namespace std;

class Pozycja
{
public:
	double X;
	double Y;
	Pozycja(double x, double y)
	{
		X = x;
		Y = y;
	}

	Pozycja()
	{
		X = 10.0;
		Y = 10.0;
	}
};

class Artefakty
{
public:
	Pozycja max;
	Pozycja tab1[10];


	Artefakty();

	void wyswietl()
	{
		for (int i = 0; i < 10; i++)
		{
			cout << "Numer	" <<i << "\nPozycja:	X = " << (tab1[i]).X << "	Y = " << (tab1[i]).Y << endl;
		}
	}
	void wyswietl_j()
	{
		cout << "MAX Pozycja:	X = " << max.X << "	Y = " << max.Y << endl;
	}
	void divide_and_cry(int n);
};

Artefakty::Artefakty()
{
	fstream plik;
	plik.open("points.csv", ios::in);
	if (plik.good() == false)
	{
		cout << "ERROR" << endl;
		exit(0);
	}
	string x;
	string a, b;
	int j = 0, k = 0;
	getline(plik, x, '\n');
	for (int i = 0; i < 10; i++)
	{
		a.clear();
		b.clear();
		getline(plik, x, ',');
		getline(plik, a, ',');
		getline(plik, b, '\n');
		/*
		while (x[j] != ' ')
		{
			j++;
			cout << "a" << endl;
		}
		j++;
		while (x[j] != ' ')
		{
			cout << "c" << endl;
			a[k] = x[j];
			k++;
			j++;
			cout << "e" << endl;
		}
		j++;
		while (x[j] != '\n')
		{
			b[k] = x[j];
			k++;
			j++;
			cout << "d" << endl;
		}
		cout << "b" << endl;
		*/
		(tab1[i]).X = atof(a.c_str());
		(tab1[i]).Y = atof(b.c_str());
	}
	max = tab1[0];
	plik.close();
}

void Artefakty::divide_and_cry(int NNN)
{
	double n = NNN;
	int i;
	double mini = 10.0;
	double Last_mini = 0;
	const double div = 1.0 / n;
	double X = div / 2;
	double Y = div / 2;
	cout << "Div = " << div << endl;
	for (int f = 0; f < 1; f++)
	{
		n = NNN;
		mini = 10.0;
		Last_mini = 0;
		X = div / 2;
		Y = div / 2;
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				mini = 10.0;
				for (i = 0; i < 10; i++)
				{
					if ((((tab1[i]).X - X) < mini) && (((tab1[i]).Y - Y) < mini) && (((tab1[i]).X - X) > -mini) && (((tab1[i]).Y - Y) > -mini))
					{
						if (sqrt((((tab1[i]).X - X) * ((tab1[i]).X - X)) + (((tab1[i]).Y - Y) * ((tab1[i]).Y - Y))) < mini)
						{
							//cout << "i = " << i << "	" << abs((tab[i]).X - X) << "	" << abs((tab[i]).Y - Y) << endl;
							//cout << " Od =" << abs(((tab[i]).X * (tab[i]).X) + ((tab[i]).Y * (tab[i]).Y)) << endl;
							//cout << "Koords =" << (tab[i]).X << (tab[i]).Y << endl;
							
							mini = sqrt((((tab1[i]).X - X) * ((tab1[i]).X - X)) + (((tab1[i]).Y - Y) * ((tab1[i]).Y - Y)));
						}
					}
				}
				if (mini > Last_mini)
				{
					Last_mini = mini;
					max.X = X;
					max.Y = Y;
				}
				X += div;
			}
			X = div / 2;
			Y += div;
		}

		mini = 10.0;
		X = 0;
		Y = 0;
		for (int y = 0; y < 2; y++)
		{
			for (int k = 0; k < n; k++)
			{
				mini = 10.0;
				for (i = 0; i < 10; i++)
				{
					if ((((tab1[i]).X - X) < mini) && (((tab1[i]).Y - Y) < mini) && (((tab1[i]).X - X) > -mini) && (((tab1[i]).Y - Y) > -mini))
					{
						if (sqrt((((tab1[i]).X - X) * ((tab1[i]).X - X)) + (((tab1[i]).Y - Y) * ((tab1[i]).Y - Y))) < mini)
						{
							//cout << "i = " << i << "	" << abs((tab[i]).X - X) << "	" << abs((tab[i]).Y - Y) << endl;
							//cout << " Od =" << abs(((tab[i]).X * (tab[i]).X) + ((tab[i]).Y * (tab[i]).Y)) << endl;
							//cout << "Koords =" << (tab[i]).X << (tab[i]).Y << endl;

							mini = sqrt((((tab1[i]).X - X) * ((tab1[i]).X - X)) + (((tab1[i]).Y - Y) * ((tab1[i]).Y - Y)));
						}
					}
				}
				if (mini > Last_mini)
				{
					//cout << "Mini: " << mini << endl;
					Last_mini = mini;
					max.X = X;
					max.Y = Y;
				}
				X += div;
			}
			Y = 1;
			X = div / 2;
		}
		

		mini = 10.0;
		X = 0;
		Y = 0;
		for (int y = 0; y < 2; y++)
		{
			for (int k = 0; k < n; k++)
			{
				mini = 10.0;
				for (i = 0; i < 10; i++)
				{
					if ((((tab1[i]).X - X) < mini) && (((tab1[i]).Y - Y) < mini) && (((tab1[i]).X - X) > -mini) && (((tab1[i]).Y - Y) > -mini))
					{
						if (sqrt((((tab1[i]).X - X) * ((tab1[i]).X - X)) + (((tab1[i]).Y - Y) * ((tab1[i]).Y - Y))) < mini)
						{
							//cout << "i = " << i << "	" << abs((tab[i]).X - X) << "	" << abs((tab[i]).Y - Y) << endl;
							//cout << " Od =" << abs(((tab[i]).X * (tab[i]).X) + ((tab[i]).Y * (tab[i]).Y)) << endl;
							//cout << "Koords =" << (tab[i]).X << (tab[i]).Y << endl;

							mini = sqrt((((tab1[i]).X - X) * ((tab1[i]).X - X)) + (((tab1[i]).Y - Y) * ((tab1[i]).Y - Y)));
						}
					}
				}
				if (mini > Last_mini)
				{
					//cout << "Mini: " << mini << endl;
					Last_mini = mini;
					max.X = X;
					max.Y = Y;
				}
				Y += div;
			}
			X = 1;
			Y = div / 2;
		}
	}

	mini = 10.0;
	X = 1;
	Y = 1;

	mini = 10.0;
	for (i = 0; i < 10; i++)
	{
		if ((((tab1[i]).X - X) < mini) && (((tab1[i]).Y - Y) < mini) && (((tab1[i]).X - X) > -mini) && (((tab1[i]).Y - Y) > -mini))
		{
			if (sqrt((((tab1[i]).X - X) * ((tab1[i]).X - X)) + (((tab1[i]).Y - Y) * ((tab1[i]).Y - Y))) < mini)
			{
				//cout << "i = " << i << "	" << abs((tab[i]).X - X) << "	" << abs((tab[i]).Y - Y) << endl;
				//cout << " Od =" << abs(((tab[i]).X * (tab[i]).X) + ((tab[i]).Y * (tab[i]).Y)) << endl;
				//cout << "Koords =" << (tab[i]).X << (tab[i]).Y << endl;

				mini = sqrt((((tab1[i]).X - X) * ((tab1[i]).X - X)) + (((tab1[i]).Y - Y) * ((tab1[i]).Y - Y)));
			}
		}
	}
	if (mini > Last_mini)
	{
		cout << "Mini: " << mini << endl;
		Last_mini = mini;
		max.X = X;
		max.Y = Y;
	}
}


int main()
{
	clock_t start;
	Artefakty abc;

	cout << "discrete-ing czas: ";
	start = clock();
	abc.divide_and_cry(10000);
	cout << clock() - start << "ms" << endl;

	abc.wyswietl();
	abc.wyswietl_j();
	cout << endl << "////////////////////" << endl << endl;


	return 0;
}