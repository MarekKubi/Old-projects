#include "header.h"

void t10X10::czytaj_dane()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (i == j)
			{
				//cout << "1\t";
				tab[i][j] = 1;
			}
			else
			{
				//cout << "0\t";
				tab[i][j] = 0;
			}
		}
		//cout << endl;
	}
}

void t10X10::zapisz_dane_do_pliku()
{
	ofstream plik;
	plik.open("dane.txt");
	char tekst;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			tekst = (tab[i][j] + '0');
			plik << tekst;
			plik << "\t";
		}
		plik << "\n";
	}
	plik.close();
}

void t10X10::czytaj_dane_z_pliku()
{
	ifstream plik;
	plik.open("dane.txt");
	string wiersz;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			getline(plik, wiersz);
			while (wiersz != "") {
				cout << wiersz << endl;
				getline(plik, wiersz);
			}
		}
	}
	plik.close();
}
