#include "header.h"


point::point(int a, point* po)
{
	n = a;
	p = po;
}

void node::add(int a)
{
	point* temp = new point(a, po);
	po = temp;
}

node::~node()
{
	point* temp;
	while (po)
	{
		temp = po;
		po = (*po).p;
		delete temp;
	}
}

Graf::Graf()
{
	int a;
	int b;
	int j;
	int max = 0;
	fstream plik;
	plik.open("email-Eu-core.txt", ios::in);
	if (plik.good() == false)
	{
		cout << "ERROR" << endl;
		exit(0);
	}
	string x;
	int i = 0;
	while (getline(plik, x))
	{
		i++;
	}
	plik.close();


	plik.open("email-Eu-core.txt", ios::in);
	if (plik.good() == false)
	{
		cout << "ERROR" << endl;
		exit(0);
	}
	while (getline(plik, x))
	{
		getline(plik, x, ' ');
		a = atoi(x.c_str());
		if (a > max)
		{
			max = a;
		}
		getline(plik, x, '\n');
		b = atoi(x.c_str());
		if (b > max)
		{
			max = b;
		}
	}
	plik.close();

	size = max;

	czy = new bool[max];
	tab = new node*[max];

	for (j = 0; j < max; j++)
	{
		tab[i] = new node;
	}
	czy = new bool[max];

	plik.open("email-Eu-core.txt", ios::in);
	if (plik.good() == false)
	{
		cout << "ERROR" << endl;
		exit(0);
	}

	for (j = 0; j < max; j++)
	{
		getline(plik, x, ' ');
		a = atoi(x.c_str());
		getline(plik, x, '\n');
		b = atoi(x.c_str());
		(*tab[a]).add(b);
		(*tab[b]).add(a);
	}

	plik.close();
}

Graf::~Graf()
{
	for (int i = 0; i < size; i++)
	{
		delete tab[i];
	}
	delete tab;
}

void Graf::pokaz()
{
	node temp = *tab[0];
	point* poin = temp.po;
	for (int i = 0; i < size; i++)
	{
		cout << i << "	";
		while (poin)
		{
			cout << (*poin).n << "	";
			poin = (*poin).p;
		}
	}
}