#include "Header.h"

TSilnik::TSilnik()
{
	moc = 0;
	max_moment_obr = 0;
}

TSilnik::TSilnik(int moc_n, int moment_n)
{
	moc=moc_n;
	max_moment_obr= moment_n;
}

TSamochod::TSamochod(string MODEL, int MOC, int MOMENT)
{	
	TSilnik t1(MOC, MOMENT);
	silnik = t1;
	model =	MODEL;
}


void TSamochod::wypisz()
{
	cout << "Model: " << model << endl << "Moc: " << silnik.moc << endl << "Moment: " << silnik.max_moment_obr << endl;
}

TKlasa::TKlasa()
{
	a = 0;
}



void TZaprzyjazniona_Klasa::rob(TKlasa obiekt)
{
	cout << "Pierwotna wartosc: " << obiekt.a << endl;
	cout << "Podaj nowa wartosc" << endl;
	cin >> obiekt.a;
	cout << "Zmieniona wartosc: " << obiekt.a << endl;
}
void f_Zaprzyjazniona(TKlasa obiekt)
{

	cout << "Pierwotna wartosc: " << obiekt.a << endl;
	cout << "Podaj nowa wartosc" << endl;
	cin >> obiekt.a;
	cout << "Zmieniona wartosc: " << obiekt.a << endl;
}
