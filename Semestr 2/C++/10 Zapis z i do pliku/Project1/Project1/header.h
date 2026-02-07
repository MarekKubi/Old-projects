#pragma once

#include <iostream>
#include <string>
#include <fstream>

#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

class t10X10
{
	int tab[10][10];
public:
	void czytaj_dane();
	void zapisz_dane_do_pliku();
	void czytaj_dane_z_pliku();

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