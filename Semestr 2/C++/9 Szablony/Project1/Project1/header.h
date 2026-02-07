#pragma once

#include <iostream>
#include <string>

#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

template <typename T>
T Dodaj(T a, T b)
{
	return a + b;
}
template <typename T>
T Max(T a, T b)
{
	return (a > b) ? a : b;
}


template <typename elementy>
class Tablica
{
	elementy* tab;
public:
	Tablica(int rozmiar)
	{
		tab = new elementy[rozmiar];
	}
	~Tablica()
	{
		delete tab;
	}
};

template <typename T>
class Kula
{
	T promien;
public:
	Kula(T a)
	{
		promien = a;
	}
	T Pole_Powierzchni()
	{
		T a = 4;
		return (M_PI * a * promien * promien);
	}
	T Objetosc()
};

void zadanie1();
void zadanie2();
void zadanie3();
void zadanie4();/*
void zadanie5();/*
void zadanie6();/*
void zadanie7();/*
void zadanie8();/*
void zadanie9();*/