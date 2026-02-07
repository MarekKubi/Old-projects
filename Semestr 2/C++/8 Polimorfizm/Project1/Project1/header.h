#pragma once


#include <iostream>
#include <string>

#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;


class Rodzic
{
public:
	virtual void Metoda();
};
class Potomek : public Rodzic
{
public:
	void Metoda() override;
};

class Bryla
{
public:
	virtual double Pole_Powierzchni() { return -1; }
	virtual double Objetosc() { return -1;  }
};

class Kula : public Bryla
{
	double promien;
public:
	Kula(double r = 1.0);
	double Pole_Powierzchni();
	double Objetosc();

};

class Prostopadloscian : public Bryla
{
	double a,b,h;
public:
	Prostopadloscian(double aa = 1.0, double bb = 1.0, double hh = 1.0);
	double Pole_Powierzchni();
	double Objetosc();

};

void zadanie1();
void zadanie2();/*
void zadanie3();
void zadanie4();
void zadanie5();
void zadanie6();
void zadanie7();
void zadanie8();
void zadanie9();*/