#pragma once


#include <iostream>
#include <string>

using namespace std;

class TUlamek
{
	int licznik;
	int mianownik;
public:
	TUlamek(int licznik, int mianownik);
	TUlamek(int a);
	int daj_l();
	int daj_m();
	void wyswietl();
	float konwert();
	float Kwadrat();
};

TUlamek mnozenie(TUlamek ulamek1, TUlamek ulamek2);


class TZespolona
{
	double rzeczywista;
	double urojona;
public:
	friend void Pokaz(TZespolona a);
	TZespolona(double rz =0., double ur =0.);
};


void Pokaz(TZespolona);

void zadanie1();
void zadanie2();/*
void zadanie4();
void zadanie5();
void zadanie6();
void zadanie7();
void zadanie8();
void zadanie9();*/