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
};

class Artefakty
{
public:
	Pozycja tab1[1000];
	int tab2[1000];
	int tab3[1000];


	Artefakty();
	
	void wyswietl()
	{
		for (int i = 0; i < 1000; i++)
		{
			cout << i+1 << " " << (tab1[i]).X << " " << (tab1[i]).Y << endl;
		}
	}
	void wyswietl_j(int j)
	{
		cout << "K=" << j << endl;
		cout << "Odleglosci <= niz 1" << endl;
		for (int i = 0; i < j; i++)
		{
			cout << i + 1 << " " << (tab1[tab2[i]]).X << " " << (tab1[tab2[i]]).Y << endl;
		}
	}
	void JEDI(int n);
	void JEDI_brute(int n);
	void ubdut();
	int Squareitup(double X, double Y);
	int circle(double X, double Y, int* tab, int k);
};

Artefakty::Artefakty()
{
	fstream plik;
	plik.open("pozycje_poczatkowe.txt", ios::in);
	if (plik.good() == false)
	{
		cout << "ERROR" << endl;
		exit(0);
	}

	string x;
	string a, b;
	int j = 0, k = 0;
	for (int i = 0; i < 1000; i++)
	{
		a.clear();
		b.clear();
		getline(plik, x, ' ');
		getline(plik, a, ' ');
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
		tab2[i] = 0;
		tab3[i] = i;
	}

	plik.close();
}
void Artefakty::ubdut()
{
	for (int i = 1; i < 20; i++)
	{
		clock_t start;
		string m;
		fstream plik;
		if (i < 10)
		{
			m = "przemieszczenia_0.txt";
			//cout << m;
			m[16] = '0' + i;
			//cout << m;
		}
		if (i >= 10)
		{
			m = "przemieszczenia_00.txt";
			//cout << m[16];
			m[16] = '0' + ((i - (i % 10))/10);
			m[17] = '0' + (i % 10);
		}
		plik.open(m, ios::in);
		if (plik.good() == false)
		{
			cout << "ERROR" << endl;
			exit(0);
		}

		string x;
		string a, b;
		int j = 0, k = 0;
		for (int i = 0; i < 1000; i++)
		{
			a.clear();
			b.clear();
			getline(plik, x, ' ');
			getline(plik, a, ' ');
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
			(tab1[i]).X += atof(a.c_str());
			(tab1[i]).Y += atof(b.c_str());
			if (i == 2 || i == 5 || i == 11 || i == 16 || i == 20)
			{

				cout << "Bounding box czas: ";
				//auto begin = std::chrono::high_resolution_clock::now();
				start = clock();
				JEDI(i); 
				//auto end = std::chrono::high_resolution_clock::now();
				//auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
				//printf("Time measured: %.3f seconds.\n", elapsed.count() * 1e-9);
				cout << clock() - start << "ms" << endl;

				cout << "Brute force czas: ";
				//begin = std::chrono::high_resolution_clock::now();
				start = clock();
				JEDI_brute(i);
				//end = std::chrono::high_resolution_clock::now();
				//elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
				//printf("Time measured: %.3f seconds.\n", elapsed.count() * 1e-9);
				cout << clock() - start << "ms" << endl;
				cout << endl << "////////////////////" << endl;

    
			}
		}

		plik.close();
	}
}
void Artefakty::JEDI(int n)
{
	fstream plik;
	string a;
	if (n < 10)
	{
		a = "jedi_po_kroku_0.txt";
		//cout << a[14];
		a[14] = '0' + n;
	}
	if (n >= 10)
	{
		a = "jedi_po_kroku_00.txt";
		//cout << a;
		a[14] = '0' + ((n - (n % 10))/10);
		a[15] = '0' + (n % 10);

	}
	//cout << a[14];
	plik.open(a, ios::in);
	if (plik.good() == false)
	{
		cout << "ERROR" << endl;
		exit(0);
	}
	clock_t start;
	string x;
	string a_j, b_j;
	int j = 0, k = 0;
	double X, Y;
	for (int i = 0; i < 10; i++)
	{
		a_j.clear();
		b_j.clear();
		getline(plik, x, ' ');
		getline(plik, a_j, ' ');
		getline(plik, b_j, '\n');
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
		X = atof(a_j.c_str());
		Y = atof(b_j.c_str());

		//cout << "Pozycja Jedi: x = " << X << " y = " << Y << endl;
		//cout << "Pozycja Jedi: x = " << (tab1[1].X -X) << " y = " << (tab1[1].Y - Y) << endl;
		//cout << "Pozycja Jedi: x = " << (tab1[1].X) << " y = " << (tab1[1].Y) << endl;

		//cout << "Bounding box czas: ";
		//start = clock();
		k = Squareitup(X, Y);
		//cout << "k = " << k << endl;
		//k = circle(X, Y, tab2, k);
		//cout << clock() - start << "ms" << endl;
		//wyswietl_j(k);

		//cout << "Brute force czas: ";
		//start = clock();
		//Squareitup(X, Y);
		//k = circle(X, Y, tab1, 1000);
		//cout << clock() - start << "ms" << endl;
		//wyswietl_j(k);
	}

	plik.close();
}

void Artefakty::JEDI_brute(int n)
{
	fstream plik;
	string a;
	if (n < 10)
	{
		a = "jedi_po_kroku_0.txt";
		//cout << a[14];
		a[14] = '0' + n;
	}
	if (n >= 10)
	{
		a = "jedi_po_kroku_00.txt";
		//cout << a[14];
		a[14] = '0' + ((n - (n % 10)) / 10);
		a[15] = '0' + (n % 10);
	}
	//cout << a[14];
	plik.open(a, ios::in);
	if (plik.good() == false)
	{
		cout << "ERROR" << endl;
		exit(0);
	}
	clock_t start;
	string x;
	string a_j, b_j;
	int j = 0, k = 0;
	double X, Y;
	for (int i = 0; i < 10; i++)
	{
		a_j.clear();
		b_j.clear();
		getline(plik, x, ' ');
		getline(plik, a_j, ' ');
		getline(plik, b_j, '\n');
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
		X = atof(a_j.c_str());
		Y = atof(b_j.c_str());

		//cout << "Pozycja Jedi: x = " << X << " y = " << Y << endl;
		//cout << "Pozycja Jedi: x = " << (tab1[1].X -X) << " y = " << (tab1[1].Y - Y) << endl;
		//cout << "Pozycja Jedi: x = " << (tab1[1].X) << " y = " << (tab1[1].Y) << endl;
		
		//cout << "Bounding box czas: ";
		//start = clock();
		//k = Squareitup(X, Y);
		//k = circle(X, Y, tab2, k);
		//cout << clock() - start << "ms" << endl;
		//wyswietl_j(k);
		
		//cout << "Brute force czas: ";
		//start = clock();
		//Squareitup(X, Y);
		k = circle(X, Y, tab3, 1000);
		//cout << "k = " << k << endl;
		//cout << clock() - start << "ms" << endl;
		//wyswietl_j(k);
		
	}

	plik.close();
}
int Artefakty::Squareitup(double X, double Y)
{
	int i;
	int j = 0;
	bool t = 0;
	for (i = 0; i < 1000; i++)
	{
		for (int f = 0; f < 100; f++)
		{

			if ((((tab1[i]).X - X) < 1.0) && (((tab1[i]).Y - Y) < 1.0) && (((tab1[i]).X - X) > -1.0) && (((tab1[i]).Y - Y) > -1.0))
			{
				if (((((tab1[i]).X - X) * ((tab1[i]).X - X)) + (((tab1[i]).Y - Y) * ((tab1[i]).Y - Y))) < 1.0)
				{
					//cout << "i = " << i << "	" << abs((tab[i]).X - X) << "	" << abs((tab[i]).Y - Y) << endl;
					//cout << " Od =" << abs(((tab[i]).X * (tab[i]).X) + ((tab[i]).Y * (tab[i]).Y)) << endl;
					//cout << "Koords =" << (tab[i]).X << (tab[i]).Y << endl;
					tab2[j] = i;
					t = 1;
				}
			}
		}

		if (t)
		{
			j++;
			t = 0;
		}
	}
	return j;
}

int Artefakty::circle(double X, double Y, int* tab, int k)
{
	int i = 0;
	int j = 0;
	bool t = 0;
	for (i; i < k; i++)
	{
		//std::this_thread::sleep_for(std::chrono::milliseconds(10));
		for (int f = 0; f < 100; f++)
		{
			if (((((tab1[tab[i]]).X - X) * ((tab1[tab[i]]).X - X)) + (((tab1[tab[i]]).Y - Y) * ((tab1[tab[i]]).Y - Y))) < 1.0)
			{
				//cout << "i = " << i << "	" << abs((tab[i]).X - X) << "	" << abs((tab[i]).Y - Y) << endl;
				//cout << " Od =" << abs(((tab[i]).X * (tab[i]).X) + ((tab[i]).Y * (tab[i]).Y)) << endl;
				//cout << "Koords =" << (tab[i]).X << (tab[i]).Y << endl;
				tab2[j] = i;
				t =1;
			}
		}
		if (t)
		{
			j++;
			t = 0;
		}
	}
	//cout << "i = " << i << endl;;
	return j;
}

int main()
{
	Artefakty abc;
	abc.ubdut();
	//abc.wyswietl();

	//string b = "123.3453543";
	//double z = atof(b.c_str());
	//cout << z;

	return 0;
}