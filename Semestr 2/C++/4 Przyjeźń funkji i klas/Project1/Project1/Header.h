#pragma once


#include <iostream>
#include <string>

using namespace std;

class TZaprzyjazniona_Klasa;
class TSamochod;

class TSilnik
{
    int moc;
    int max_moment_obr;
public:
    friend TSamochod;
    TSilnik(int moc, int moment);
    TSilnik();
};

class TSamochod
{
    TSilnik silnik;
    string model;
public:
    TSamochod(string MODEL, int MOC, int MOMENT);
    void wypisz();
};







class TKlasa
{
    int a;
public:
    friend class TZaprzyjazniona_Klasa;
    friend void f_Zaprzyjazniona(TKlasa obiekt);
    TKlasa();
};


class TZaprzyjazniona_Klasa
{
public:
    void rob(TKlasa obiekt);
};


void f_Zaprzyjazniona(TKlasa obiekt);

void zadanie1();
void zadanie2();/*
void zadanie4();
void zadanie5();
void zadanie6();
void zadanie7();
void zadanie8();
void zadanie9();*/