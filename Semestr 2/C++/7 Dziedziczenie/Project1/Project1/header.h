#pragma once


#include <iostream>
#include <string>

#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

class Figura
{
	friend class Prostokat;
	friend class Trojkat;
	int wysokosc, szerokosc;
public:
	void Ustaw_wartosc(int h, int d);
};

class Prostokat : public Figura
{
public:
	int daj_V();
};
class Trojkat : public Figura 
{
public:
	int daj_V();
};

class A
{
public:
	void met_a();
};
class B
{
public:
	void met_b();
};
class C
{
public:
	void met_c();
};

class Z : public A, public B, public C
{
public:
	void met_z();
};

class Punkt
{
	friend class Kolo;
	float x, y;
	string nazwa_p;
public:
	void pokaz_wsp();
	Punkt(string srodek = "S", float a = 0., float b = 0.);
};
class Kolo : public Punkt
{
	float promien;
	string nazwa_k;
public:
	void Wyswietl();
	Kolo(string nazwa_kola = "kolko", string nazwa_punktu = "S", float a = 0., float b = 0., float r = 1.);
};

class Zwierze
{
public:
	int wiek, ilosc_nog;
	Zwierze(int w = 0, int n = 4);
};
class Zwierze_domowe : public Zwierze
{
public:
	string imie, kolor_sierci;
	Zwierze_domowe(string im = "Puszek", string kolor = "brozowy", int w = 0, int n = 4);
};
class Hipopotam : public Zwierze
{
};
class Kot : public Zwierze_domowe
{
public:
	void pokaz();
};
class Pies : public Zwierze_domowe
{
public:
	Pies(string im = "Puszek", string kolor = "brozowy", int w = 0, int n = 4);
	void pokaz();
};

void zadanie1();
void zadanie2();
void zadanie3();
void zadanie4();/*
void zadanie5();
void zadanie6();
void zadanie7();
void zadanie8();
void zadanie9();*/