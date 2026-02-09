#include "header.h"
int liczba = 0;


queue::queue()
{
	n = -1;
	point = NULL;
}
queue::queue(int a)
{
	n = a;
	point = NULL;
}
queue* queue::add_q(int a)
{
	point = new queue(a);
	return point;
}
int queue::de_q()
{
	return n;
}
queue* queue::next()
{
	return point;
}


stos::stos()
{
	n = -1;
	point = NULL;
}
stos::stos(int a, stos* p)
{
	n = a;
	point = p;
}
stos* stos::add_s(int a)
{
	return new stos(a, this);
}
int stos::de_s()
{
	return n;
}
stos* stos::next()
{
	return point;
}

point::point(int a, point* po)
{
	n = a;
	p = po;
}

void node::add(int a)
{
	point* poi = po;
	while(poi)
	{
		if (a == (*poi).n)
		{
			return;
		}
		poi = (*poi).p;
	}
	point* temp = new point(a, po);
	po = temp;
}

node::node()
{
	po = NULL;
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
	ilosc = 0;;
	A = true;
	q_p = new queue(0);
	q_k = q_p;
	s = new stos(0,NULL);
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
	//cout << "AAAAAa";
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

	czy = new bool[max+1];
	tab = new node * [max+1];
	//cout << "Max:" << max;
	for (j = 0; j < max+1; j++)
	{
		tab[j] = new node;
		czy[j] = true;
		//cout << "b";
	}

	plik.open("email-Eu-core.txt", ios::in);
	if (plik.good() == false)
	{
		cout << "ERROR" << endl;
		exit(0);
	}

	for (j = 0; j < i; j++)
	{
		getline(plik, x, ' ');
		a = atoi(x.c_str());
		//cout << "A = " << a << endl;
		getline(plik, x, '\n');
		b = atoi(x.c_str());
		//cout << "B = " << b << endl;
		(*tab[a]).add(b);
		(*tab[b]).add(a);
	}

	plik.close();
}

Graf::~Graf()
{
	for (int i = 0; i < size+1; i++)
	{
		delete tab[i];
	}
}

void Graf::pokaz()
{
	node temp;
	point* poin;
	for (int i = 0; i < size; i++)
	{
		temp = *tab[i];
		poin = temp.po;
		cout <<"I:	"<< i << "	";
		while (poin)
		{
			cout << (*poin).n << "	";
			poin = (*poin).p;
		}
		cout << endl;
	}
}

bool Graf::Q_G(int s, int k)
{
	point* temp = (*tab[s]).po;
	if ((*temp).n == k)
	{
		cout << (*temp).n << "	";
		return true;
	}
	
	while (!czy[(*temp).n])
	{
		cout << "aaaaaaa";
		if ((*temp).n == k)
		{
			cout << (*temp).n << "	";
			return true;
		}
		temp = (*temp).p;
		cout << "N:	" << (*temp).n;
		if (!temp)
		{
			break;
		}
	}

	if (!temp)
	{
		cout << "bbbbbbbbbb";
		if (Q_G(de_q(), k))
		{
			cout << s << "	";
			return true;
		}
		return false;
	}
	int i = 1;
	cout << "kkkkkkkkkk";
	queue* t_q = new queue(de_q());
	while (A)
	{
		cout << "3";
		i++;
		(*t_q).add_q(de_q());
	}
	cout << s << " ";
	q_p = new queue((*temp).n);
	while (i)
	{
		cout << "3";
		i--;
		add_q((*t_q).de_q());
	}
	while (temp)
	{
		cout << "cccccccc";
		if ((*temp).n == k)
		{
			cout << (*temp).n << "	";
			return true;
		}
		if (czy[(*temp).n])
		{
			add_q((*temp).n);
			czy[(*temp).n] = false;
		}
		temp = (*temp).p;
	}
	for (int j = 0; j < i; j++)
	{
		add_q((*t_q).de_q());
	}
	cout << "2";
	if (Q_G(de_q(), k))
	{
		cout << (*temp).n << "	";
		return true;
	}
	return false;
	

	/*
	point* temp = (*tab[s]).po;
	while (temp)
	{
		if ((*temp).n == k)
		{
			cout << (*temp).n << "	";
			return true;
		}
		if (czy[(*temp).n])
		{
			add_q((*temp).n);
			czy[(*temp).n] = false;
		}
		temp = (*temp).p;
	}
	liczba--;
	if (Q_S(de_q(), k))
	{
		cout << s << "	";
		return true;
	}
	return false;
	*/
}

bool Graf::Q_S(int s, int k)
{
	ilosc++;
	point* temp = (*tab[s]).po;
	while (temp)
	{
		if ((*temp).n == k)
		{
			cout << (*temp).n << "	";
			return true;
		}
		if (czy[(*temp).n])
		{
			add_q((*temp).n);
			czy[(*temp).n] = false;
		}
		temp = (*temp).p;
	}
	liczba--;
	if (Q_S(de_q(), k))
	{
		cout << s << "	";
		return true;
	}
	return false;
}

bool Graf::S_G(int s, int k)
{
	ilosc++;
	point* temp = (*tab[s]).po;
	while (temp)
	{
		if ((*temp).n == k)
		{
			cout << (*temp).n << "	";
			return true;
		}
		if (czy[(*temp).n])
		{
			add_s((*temp).n);
			czy[(*temp).n] = false;
		}
		temp = (*temp).p;
	}
	liczba--;
	if (S_G(de_s(), k))
	{
		cout << s << "	";
		return true;
	}
	return false;
}


void Graf::szukanie(int s, int k)
{
	clock_t start;
	czy[s] = false;
	cout << "S_G: ";
	start = clock();

	Q_G(s, k);

	cout << clock() - start << "ms" << endl;
	cout << ilosc << " krokow" << endl;
	ilosc = 0;
	add_s(s);
	for (int j = 0; j < size + 1; j++)
	{
		czy[j] = true;
	}
	/*
	cout << "Q_S: ";
	start = clock();

	Q_S(s, k);

	cout << clock() - start << "ms" << endl;
	add_q(s);
	for (int j = 0; j < size + 1; j++)
	{
		czy[j] = true;
	}

	cout << "Q_G: ";
	start = clock();

	Q_G(s, k);

	cout << clock() - start << "ms" << endl;
	add_q(s);
	for (int j = 0; j < size + 1; j++)
	{
		czy[j] = true;
	}

	for (int j = 0; j < size; j++)
	{
		czy[j] = FALSE;
	}
	*/
}


int Graf::de_q()
{
	int temp = (*q_p).de_q();
	queue* del = q_p;
	q_p = (*q_p).next();
	A = q_p;
	cout <<"A" << A;
	delete del;
	return temp;
}
void Graf::add_q(int a)
{
	q_k = (*q_k).add_q(a);
}
int Graf::de_s()
{
	int temp = (*s).de_s();
	stos* del = s;
	s = (*s).next();
	A = s;
	delete del;
	return temp;
}
void Graf::add_s(int a)
{
	s = (*s).add_s(a);
	double tab[2];
	int rozmiar = 2;

}