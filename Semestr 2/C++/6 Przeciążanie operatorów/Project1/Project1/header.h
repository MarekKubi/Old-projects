#pragma once


#include <iostream>
#include <string>

using namespace std;

class Class
{
public:
	int x, y;
	Class(int x = 0, int y = 0);
	Class operator+ (Class& obj)
	{
		Class wynik;
		wynik.x = x + obj.x;
		wynik.y = y + obj.y;
		return wynik;
	}
};

class klassa_2
{
	int x, y;
public:
	klassa_2(int x = 0, int y = 0);
	klassa_2(Class a);
	int daj_x()
	{
		return x;
	}
	int daj_y()
	{
		return y;
	}
	friend Class operator+ (Class& obj);

	klassa_2 operator+ (klassa_2& obj)
	{
		Class a(this->x, this->y);
		Class b(obj.x, obj.y);
		return klassa_2(a + b);
	}
};

class Punkt2D
{
public:
	int x, y;
	Punkt2D(int a = 0, int b = 0);
	friend ostream& operator<<(ostream& str, Punkt2D c);
	friend istream& operator>>(istream& str, Punkt2D c);
};

void zadanie1();
void zadanie2();
void zadanie3();/*
void zadanie4();
void zadanie5();
void zadanie6();
void zadanie7();
void zadanie8();
void zadanie9();*/