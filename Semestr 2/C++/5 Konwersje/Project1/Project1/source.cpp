#include "Header.h"

TUlamek::TUlamek(int licz, int mia)
{
	licznik = licz;
	mianownik = mia;
}
TUlamek::TUlamek(int a)
{
	licznik = a;
	mianownik = 1;
}



int TUlamek::daj_l()
{
	return licznik;
}
int TUlamek::daj_m()
{
	return mianownik;
}
void TUlamek::wyswietl() 
{
	cout << "Ulamek: " << licznik << "/" << mianownik << endl;
}

TUlamek mnozenie(TUlamek ulamek1, TUlamek ulamek2)
{
	TUlamek obiekt(ulamek1.daj_l() * ulamek2.daj_l(), ulamek1.daj_m() * ulamek2.daj_m());
	return obiekt;
}

float TUlamek::Kwadrat()
{
	TUlamek obiekt(licznik*licznik, mianownik*mianownik);

	return obiekt.konwert();
}

float TUlamek::konwert()
{
	float licz = licznik * 1.;
	float mian = mianownik * 1.;
	return licz / mian;
}

/////////////////////////////////////////////////////////////////////////

TZespolona::TZespolona(double rz, double ur)
{
	rzeczywista = rz;
	urojona = ur;
}


void Pokaz(TZespolona a)
{
	cout << "Liczba zlozona: [ " << a.rzeczywista << ", " << a.urojona << " ]" << endl;
}