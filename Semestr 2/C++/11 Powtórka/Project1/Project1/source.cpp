#include "header.h"

adres::adres(string u, int nr)
{
	ulica = u;
	nr_biura = nr;
}

void adres::pokaz()
{
	cout << "Ulica: " << ulica << " nr.: " << nr_biura << endl;
}

pracownik::pracownik(string i, string n, adres* ws)
{
	imie = i;
	nazwisko = n;
	wsk = ws;
}

void pracownik::pokaz_a()
{
	(*wsk).pokaz();
}
void pracownik::pokaz_p()
{
	cout << "Imie: " << imie << " Nazwisko: " << nazwisko << endl;
}


void osoba::pokaz()
{
	cout << "Imie: " << imie << endl << "Nazwisko: " << nazwisko << endl;
}

kadra::kadra(string i, string n, string w)
{
	imie = i;
	nazwisko = n;
	wyksztalcenie = w;
}
void kadra::pokaz_c()
{
	kadra helper;
	(*this).pokaz();
	cout << "Wyksztalcenie: " << wyksztalcenie << endl;
}

MyClass::MyClass(int a)
{
	value = a;
}

MyClass::MyClass(const MyClass& cl)
{
	value = cl.value;
}

void MyClass::pokaz()
{
	cout << value << endl;
}