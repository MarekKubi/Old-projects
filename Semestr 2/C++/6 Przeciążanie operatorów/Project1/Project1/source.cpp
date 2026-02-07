#include "header.h"

Class::Class(int a, int b)
{
	x = a;
	y = b;
}


klassa_2::klassa_2(int a, int b)
{
	x = a;
	y = b;
}
klassa_2::klassa_2(Class a)
{
	x = a.x;
	y = a.y;
}


Punkt2D::Punkt2D(int a, int b)
{
	x = a;
	y = b;
}

ostream& operator<<(ostream& str, Punkt2D c) 
{
	str << "(" << c.x << ", " << c.y << ")";
	return str;
}

istream& operator>>(istream& str, Punkt2D c) 
{
	cout << "Podaj wspolzedne" << endl;
	str>> c.x>> c.y;
	return str;
}

