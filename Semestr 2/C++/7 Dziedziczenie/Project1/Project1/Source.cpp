#include "header.h"

void Figura::Ustaw_wartosc(int h, int d)
{
	wysokosc = h;
	szerokosc = d;
}

int Prostokat::daj_V()
{
	return wysokosc * szerokosc;
}
int Trojkat::daj_V()
{
	return wysokosc * szerokosc /2;
}


void A::met_a() 
{
	cout << "Metoda klasy A" << endl;
}
void B::met_b()
{
	cout << "Metoda klasy B" << endl;
}
void C::met_c()
{
	cout << "Metoda klasy C" << endl;
}

void Z::met_z()
{
	Z helper;
	helper.met_a();
	helper.met_b();
	helper.met_c();
}

void Punkt::pokaz_wsp()
{
	cout << "x = " << x << endl << "y = " << y << endl;
}

Punkt::Punkt(string srodek, float a, float b)
{
	nazwa_p = srodek;
	x = a;
	y = b;
}

void Kolo::Wyswietl()
{
	cout << "Nazwa kola: " << nazwa_k << endl;
	pokaz_wsp();
	cout << "Promien = " << promien << endl;
	cout << "Pole = " << (promien * promien * M_PI) << endl; 
}

Kolo::Kolo(string nazwa_kola, string nazwa_punktu, float a, float b, float r)
{
	Punkt(nazwa_punktu, a, b);
	nazwa_k = nazwa_kola;
	promien = r;
}


Zwierze::Zwierze(int w, int n)
{
	wiek = w;
	ilosc_nog = n;
}

Zwierze_domowe::Zwierze_domowe(string im, string kolor, int w, int n)
{
	Zwierze(w, n);
	imie = im;
	kolor_sierci = kolor;
}

Pies::Pies(string im, string kolor, int w, int n)
{
	Zwierze(w, n);
	imie = im;
	kolor_sierci = kolor;
}
void Kot::pokaz()
{
	cout << "wiek = " << wiek << endl << "ilosc_nog = " << ilosc_nog << endl << "imie: " << imie << endl << "kolor: " << kolor_sierci << endl;
}
void Pies::pokaz()
{
	cout << "wiek = " << wiek << endl << "ilosc_nog = " << ilosc_nog << endl << "imie: " << imie << endl << "kolor: " << kolor_sierci << endl;
}
