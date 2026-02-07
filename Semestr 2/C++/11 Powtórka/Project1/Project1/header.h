#pragma once

#pragma once

#include <iostream>
#include <string>
#include <fstream>

#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

class adres
{
public:
	string ulica;
	int nr_biura;
	adres(string u = "", int nr = 0);
	void pokaz();
};

class pracownik
{
	string imie;
	string nazwisko;
	adres* wsk;
public:
	pracownik(string i = "Jan", string n = "Kowalski", adres* ws = NULL);
	void pokaz_a();
	void pokaz_p();

};


template<class T>
void wypisz(T* a, int rozmiar)
{
	int i = 0;
	while(1)
	{
		cout << a[i];
		i++;
		if (i >= rozmiar)
		{
			break;
		}
		cout << ",";
	}
}

template<class T>
class znajdz_m
{
public:
	T daj_max(T* a, int roz)
	{
		T maks = a[0];
		for (int i = 1; i < roz; i++)
		{
			if (a[i] > maks)
			{
				maks = a[i];
			}
		}
		return maks;
	}
	T daj_min(T* a, int roz)
	{
		T min = a[0];
		for (int i = 1; i < roz; i++)
		{
			if (a[i] < min)
			{
				min = a[i];
			}
		}
		return min;
	}
};

class osoba
{
	friend class kadra;
	string imie;
	string nazwisko;
public:
	void pokaz();
};

class kadra : public osoba
{
	string wyksztalcenie;
public:
	kadra(string i = "Jan", string n = "Kowalski", string w = "brak");
	void pokaz_c();
};

class MyClass
{
	int value;
public:
	MyClass(int a = 0);
	MyClass(const MyClass& cl);
	void pokaz();
};

void zadanie1();
void zadanie2();
void zadanie3();
void zadanie4();
void zadanie5();/*
void zadanie6();/*
void zadanie7();/*
void zadanie8();/*
void zadanie9();*/