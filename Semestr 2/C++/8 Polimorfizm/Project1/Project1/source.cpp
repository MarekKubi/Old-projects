#include "header.h"

void Rodzic::Metoda()
{
	cout << "Nazwa klasy: Rodzic" << endl;
}

void Potomek::Metoda()
{
	cout << "Nazwa klasy: Potomek" << endl;
}

Kula::Kula(double r)
{
	promien = r;
}


double Kula::Pole_Powierzchni()
{
	return (4 * M_PI * promien * promien);
}

double Kula::Objetosc()
{
	return (4 * M_PI * promien * promien * promien / 3);
}

Prostopadloscian::Prostopadloscian(double aa, double bb, double hh)
{
	a = aa;
	b = bb;
	h = hh;
}


double Prostopadloscian::Pole_Powierzchni()
{
	return ((a * b * 2) + (a * h * 2) + (b* h * 2));
}

double Prostopadloscian::Objetosc()
{
	return (a * b * h);
}
