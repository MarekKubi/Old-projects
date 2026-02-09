#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include<cmath>
#include <chrono>  
#include <windows.h>  
#include <thread>

using namespace std;


class Pozycja
{
public:
	int X;
	int Y;
	int krok;
	int distance;
	char kierunek;
	Pozycja* point;
	Pozycja(int x, int y, int k, int dis, char dir, Pozycja* p);

	Pozycja();
};

Pozycja::Pozycja()
{
	X = 22;
	Y = 22;
	krok = 0;
	distance = 0;
	kierunek = 'A';
	point = NULL;
}
Pozycja::Pozycja(int x, int y, int k, int dis, char dir, Pozycja* p)
{
	X = x;
	Y = y;
	krok = k;
	distance = dis + k;
	kierunek = dir;
	point = p;
}

class node
{
public:
	node* point;
	Pozycja* poz;
	node();
	~node();
	node(Pozycja* aa);
	Pozycja* give();
	bool addn(node* a);
};
node::node()
{
	poz = NULL;
	point = NULL;
}

node::~node()
{
}

node::node(Pozycja* aa)
{
	poz = aa;
	point = NULL;
}

Pozycja* node::give()
{
	return poz;
}

bool node::addn(node* a)
{
	int k = 0;
	node* temp = this;
	node* ptemp = this;
	while (((*temp).point != NULL) && (((*(*a).poz).distance + (*(*a).poz).X + (*(*a).poz).Y) >= ((*(*temp).poz).distance) + ((*(*temp).poz).Y) + ((*(*temp).poz).X)))
	//while (((*temp).point != NULL) && (((*(*a).poz).distance + sqrt((((*(*a).poz).X - 1) * ((*(*a).poz).X - 1)) + (((*(*a).poz).Y - 1) * ((*(*a).poz).Y - 1)))) >= ((*(*temp).poz).distance) + sqrt(((((*(*temp).poz).Y - 1))* (((*(*temp).poz).Y) - 1)) + ((((*(*temp).poz).X - 1)) * (((*(*temp).poz).X - 1))))))
	//while (((*temp).point != NULL) && (((*(*a).poz).distance) >= ((*(*temp).poz).distance)))
	{
		k++;
		ptemp = temp;
		temp = (*temp).point; 
	}
	if (k!=0)
	{
		(*ptemp).point = a;
		(*a).point = temp;
		return 0;
	}
	else
	{
		return 1;
	}
}

class Artefakty
{
public:
	Pozycja* tab1[1000];
	int ilosc;
	char tab2[100][100];
	int MX;
	int MY;
	node* root;


	Artefakty();
	~Artefakty();
	bool add(Pozycja* a);
	void scierzka(Pozycja* A);
	void dikstra();

	Pozycja* give()
	{
		Pozycja* a = (*root).give();
		root = (*root).point;
		return a;
	}
	void wyswietl()
	{
		cout << endl << "MX\\MY   " << MX<<"\\" << MY << endl;
		for (int i = 0; i < MY; i++)
		{
			for (int j = 0; j < MX; j++)
			{
				cout << tab2[j][i];
			}
			cout << endl;
		}
	}
};

Artefakty::~Artefakty()
{
	for (int i = 0; i < ilosc; i++)
	{
		delete tab1[i];
	}
	node* temp = root;
	node* tempu = root->point;
	while (tempu != NULL)
	{
		delete temp;
		temp = tempu;
		tempu = tempu->point;
	}
	delete temp;
}
Artefakty::Artefakty()
{
	Pozycja tab1[100][100];
	ilosc = 0;
	fstream plik;
	plik.open("labirynt_v2.txt", ios::in);
	if (plik.good() == false)
	{
		cout << "ERROR" << endl;
		exit(0);
	}
	string x;
	getline(plik, x, '\n');
	//cout << x;
	int i = 0, j = 1;
	MX = x.length() + 1;
	//cout << endl << "MX\\MY  " << MX << "\\" << MY << endl;
	//getline(plik, x, '\n');
	int k = MX/3;
	int l = 0;
	int xs = 1, ys = 1;
	if ((MX % 3)==2)
	{
		k++;
	}
	while (x[0]!='k')
	{
		cout << x;
		cout << endl;
		while (i < MX)
		{
			if (((i+1) % 3))
			{
				tab2[i + 1-l][j] = x[i];
				//cout << x[i];
				if (x[i] == 'B')
				{
					xs = i + 1 - l;
					ys = j;
				}
			}
			else
			{
				l++;
			}
			i++;
		}
		l = 0;
		i = 0;
		j++;
		getline(plik, x, '\n');
	}
	MY = j;
	//cout << "TIIIII" << MX<< endl;
	for (int l = 0; l < (MX - k +2); l++)
	{
		tab2[l][0] = 'x';
		tab2[l][MY] = 'x';
	}
	//cout << "TIIIII" << k << endl;
	for (int l = 0; l < (MY+ 1); l++)
	{
		tab2[0][l] = 'x';
		tab2[MX-k+1][l] = 'x';
	}
	root = new node(new Pozycja(xs, ys, 0, 0, 'B', NULL));
	//max = tab1[0];
	MX -= k-2;
	MY++;
	wyswietl();
	plik.close();
}

bool Artefakty::add(Pozycja* a)
{
	for (int i = 0; i < ilosc; i++)
	{
		if ((*tab1[i]).X == (*a).X && (*tab1[i]).Y == (*a).Y)
		{
			if ((*tab1[i]).distance > (*a).distance)
			{
				(*tab1[i]).distance = (*a).distance;
				(*tab1[i]).krok = (*a).krok;
				(*tab1[i]).kierunek = (*a).kierunek;
				(*tab1[i]).point = (*a).point;
			}
			delete a;
			return 1;
		}
	}
	tab1[ilosc] = a;
	ilosc++;
	return 0;
}

void Artefakty::scierzka(Pozycja* A)
{
	Pozycja* temp = A;
	int suma = 0;
	while ((*temp).kierunek != 'B')
	{
		//suma += (*temp).krok;
		cout << (*temp).kierunek << "	" << (*temp).krok << endl;
		//cout << " Dystans:	" << (*temp).distance << endl;
		temp = temp->point;
	}
	suma += (*temp).krok;
	cout << (*temp).kierunek << "	" << (*temp).krok << endl;
	//cout << " Dystans:	" << suma << endl;
}

void Artefakty::dikstra()
{
	Pozycja* poz;
	int k = 0;
	int px = 0;
	int py = 0;
	bool czy = 0;
	node* temp;
	node* tempa;
	//cout << "a" << endl;
	while (1)
	{
		while (1)
		{
			//cout << "a" << endl;
			poz = root->give();
			//cout << "a" << endl;
			//cout << tab2[(*poz).X + px][(*poz).Y + py] << endl;
			//cout << (*poz).X + px << (*poz).Y + py << endl;
			// 
			// 
			//W
			px = 1;
			k++;
			if (tab2[(*poz).X + px][(*poz).Y + py] != 'x')
			{
				while (tab2[(*poz).X + px + 1][(*poz).Y + py] != 'x' && tab2[(*poz).X + px][(*poz).Y + py + 1] == 'x' && tab2[(*poz).X + px][(*poz).Y + py - 1] == 'x')
				{
					px++;
				}
				if (tab2[(*poz).X + px + 1][(*poz).Y + py] == 'x' && tab2[(*poz).X + px][(*poz).Y + py + 1] == 'x' && tab2[(*poz).X + px][(*poz).Y + py - 1] == 'x')
				{
					px = 0;
				}
				else if (tab2[(*poz).X + px][(*poz).Y + py] == 'A')
				{
					Pozycja* pozt = new Pozycja((*poz).X + px, (*poz).Y + py, px, (*poz).distance, 'W', poz);
					add(pozt);
					cout << " Iteracje:	" << k << endl;
					cout << " Dystans:	" << (*pozt).distance << endl;
					scierzka(poz);
					return;
				}
				else
				{
					Pozycja* pozt = new Pozycja((*poz).X + px, (*poz).Y + py, px, (*poz).distance, 'W', poz);
					if (!add((pozt)))
					{
						tempa = new node(pozt);
						if (root->addn(tempa))
						{
							tempa->point = root->point;
							root->point = tempa;
						}
					}
				}
			}
			px = 0;

			//E
			px = -1;
			if (tab2[(*poz).X + px][(*poz).Y + py] != 'x')
			{
				while (tab2[(*poz).X + px - 1][(*poz).Y + py] != 'x' && tab2[(*poz).X + px][(*poz).Y + py + 1] == 'x' && tab2[(*poz).X + px][(*poz).Y + py - 1] == 'x')
				{
					//cout << "1" << endl;
					px--;
				}
				if (tab2[(*poz).X + px - 1][(*poz).Y + py] == 'x' && tab2[(*poz).X + px][(*poz).Y + py + 1] == 'x' && tab2[(*poz).X + px][(*poz).Y + py - 1] == 'x')
				{
					//cout << "2" << endl;
					px = 0;
				}
				else if (tab2[(*poz).X + px][(*poz).Y + py] == 'A')
				{
					//cout << "3" << endl;
					Pozycja* pozt = new Pozycja((*poz).X + px, (*poz).Y, -px, (*poz).distance, 'E', poz);
					add(pozt);
					cout << " Iteracje:	" << k << endl;
					cout << " Dystans:	" << (*pozt).distance << endl;
					scierzka(pozt);
					return;
				}
				else
				{
					//cout << "4" << endl;
					Pozycja* pozt = new Pozycja((*poz).X + px, (*poz).Y, -px, (*poz).distance, 'E', poz);
					//cout << "pozt" << pozt << endl;
					if (!add((pozt)))
					{
						tempa = new node(pozt);
						if (root->addn(tempa))
						{
							tempa->point = root->point;
							root->point = tempa;
						}
					}
				}
			}
			px = 0;

			//S
			py = -1;
			if (tab2[(*poz).X + px][(*poz).Y + py] != 'x')
			{
				while (tab2[(*poz).X + px][(*poz).Y + py -1] != 'x' && tab2[(*poz).X + px + 1][(*poz).Y + py] == 'x' && tab2[(*poz).X + px - 1][(*poz).Y + py] == 'x')
				{
					py--;
				}
				if (tab2[(*poz).X + px - 1][(*poz).Y + py] == 'x' && tab2[(*poz).X + px + 1][(*poz).Y + py] == 'x' && tab2[(*poz).X + px][(*poz).Y + py - 1] == 'x')
				{
					py = 0;
				}
				else if (tab2[(*poz).X + px][(*poz).Y + py] == 'A')
				{
					Pozycja* pozt = new Pozycja((*poz).X + px, (*poz).Y + py, -py, (*poz).distance, 'S', poz);
					add(pozt);
					cout << " Iteracje:	" << k << endl;
					cout << " Dystans:	" << (*pozt).distance << endl;
					scierzka(pozt);
					return;
				}
				else
				{
					Pozycja* pozt = new Pozycja((*poz).X + px, (*poz).Y + py, -py, (*poz).distance, 'S', poz);
					if (!add((pozt)))
					{
						tempa = new node(pozt);
						if (root->addn(tempa))
						{
							tempa->point = root->point;
							root->point = tempa;
						}
					}
				}
			}
			py = 0;

			//N
			py = 1;
			if (tab2[(*poz).X + px][(*poz).Y + py] != 'x')
			{
				while (tab2[(*poz).X + px][(*poz).Y + py + 1] != 'x' && tab2[(*poz).X + px + 1][(*poz).Y + py] == 'x' && tab2[(*poz).X + px - 1][(*poz).Y + py] == 'x')
				{
					py++;
				}
				if (tab2[(*poz).X + px - 1][(*poz).Y + py] == 'x' && tab2[(*poz).X + px + 1][(*poz).Y + py] == 'x' && tab2[(*poz).X + px][(*poz).Y + py + 1] == 'x')
				{
					py = 0;
				}
				else if (tab2[(*poz).X + px][(*poz).Y + py] == 'A')
				{
					Pozycja* pozt = new Pozycja((*poz).X + px, (*poz).Y + py, py, (*poz).distance, 'N', poz);
					add(pozt);
					cout << " Iteracje:	" << k << endl;
					cout << " Dystans:	" << (*pozt).distance << endl;
					scierzka(pozt);
					return;
				}
				else
				{
					Pozycja* pozt = new Pozycja((*poz).X + px, (*poz).Y + py, py, (*poz).distance, 'N', poz);
					if (!add((pozt)))
					{
						tempa = new node(pozt);
						if (root->addn(tempa))
						{
							tempa->point = root->point;
							root->point = tempa;
						}
					}
				}
			}
			py = 0;
			temp = root;
			root = (*root).point;
			delete temp;
		}
	}
}

int main()
{
	clock_t start;
	Artefakty abc;

	cout << "A*: ";
	start = clock();
	abc.dikstra();
	cout << endl << "////////////////////" << endl << endl;
	cout << clock() - start << "ms" << endl;

	//abc.wyswietl();
	//abc.wyswietl_j();
	//cout << endl << "////////////////////" << endl << endl;


	return 0;
}