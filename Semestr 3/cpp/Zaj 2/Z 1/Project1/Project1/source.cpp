#include "header.h"
//int ofset = 2;



node::node(node* poi, int v)
{
	point = poi;
	val = v;
	is_empty = 0;
}
node::node()
{
	point = 0;
	val = 0;
	is_empty = 1;
}


List::List()
{
	node* a = new node;
	head = a;
	tail = a;
	k = 0;
	//cout << endl << endl << "head=" << head << endl << endl;
}

void List::add(int element, int poz)
{
	k++;
	if ((*head).is_empty && poz == 0)
	{
		(*head).val = element;
		(*head).is_empty = 0;
	}
	else if (poz ==0)
	{
		//cout << tail << "/" << (*tail).point << endl;
		node* a = tail;
		tail = new node(a, element);
	}
	else if (poz >k-1)
	{
		k--;
		cout << endl << endl << "!!! LISTA NIE JEST TAKA DUZA !!!" << endl << endl;
	}
	else
	{
		cout << tail << "/" << (*tail).point << endl;
		node* a = tail;
		for (int i = 0; i < poz-1; i++)
		{
			a = (*a).point;
		}
		node* b = new node;
		(*b).point = (*a).point;
		(*b).val = element;
		(*a).point = b;
	}
}
int List::remove(int poz)
{
	//cout<<endl<<endl<<"k=" << k << endl << endl;
	//cout << endl << endl << "tail=" << tail << endl << endl;
	//cout << endl << endl << "head=" << head << endl << endl;
	if (poz>k-1)
	{
		cout << endl << endl << "!!! TAKI ELEMEN NIE ISTNIEJE !!!" << endl << endl;
		return 0;
	}
	else if (tail == head)
	{
		//cout << endl << endl << "!!!!!!!!!!!!!!!!!!!!!!!" << endl << endl;
		(*tail).is_empty = 1;
		k--;
		return (*tail).val;
	}
	else if (poz == 0)
	{
		//cout << "AAAAAAAAAAAAAAAAAAAAA" << endl;
		//cout << tail << "/" << (*tail).point << endl;
		k--;
		int w = (*tail).val;
		node* b = tail;
		tail = (*tail).point;
		delete b;
		return w;
	}
	else
	{
	//	cout << "nnnnnnnnnnnnnnnnnnnnn" << endl;
		//cout << tail << "/" << (*tail).point << endl;
		k--;
		node* a = tail;
		for (int i = 0; i < poz - 1; i++)
		{
			a = (*a).point;
		}
		int w = (*(*a).point).val;
		//(*a).point = (*(*a).point).point;
		node* b = (*a).point;
		(*a).point = (*b).point;
		delete b;
		return w;
	}
}
bool List::is_empty()
{
	return (*tail).is_empty;
}
int List::size()
{
	return k;
}

List::~List()
{
	node* d;
	while (!(head = tail))
	{
		d = tail;
		tail = (*tail).point;
		delete d;
	}
}


List_tab::List_tab()
{
	roz = 10;
	k = 0;
	tablica = new int [roz];
}

void List_tab::add(int element, int poz)
{
	if (poz > k)
	{
	cout << endl << endl << "!!! LISTA NIE JEST TAKA DUZA !!!" << endl << endl;
	exit;
	}
	if (k > roz)
	{/*
		int* temp_tab = new int[roz];
		for (int i = 0; i < (roz); i++)
		{
			temp_tab[i] = tablica[i];
		}
		roz = roz+ ofset;
		tablica = new int[roz];
		for (int i = 0; i < (roz - ofset); i++)
		{
			tablica[i] = temp_tab[i];
		}
		delete[] temp_tab;
		*/
		cout << "tablica jest za ma³a" << endl;
		exit;
	}
	k++;
	if (k==0 && poz == 0)
	{
		tablica[0] = element;
	}
	else
	{
		for (int i = k; i >poz; i--)
		{
			tablica[i] = tablica[i - 1];
		}
		tablica[poz] = element;
	}
	/*
	cout << endl << endl << "tablia=";

	for (int i = 0; i < k; i++)
	{
		cout << tablica[i];
	}
	cout<< endl << endl;
	*/
}
int List_tab::remove(int poz)
{
	//cout << endl << endl <<k << endl << endl;
	if (poz > k - 1)
	{
		cout << endl << endl << "!!! TAKI ELEMEN NIE ISTNIEJE !!!" << endl << endl;
		return 0;
	}
	else
	{
		int w = tablica[poz];
		for (int i = poz; i < k - 1; i++)
		{
			tablica[i] = tablica[i + 1];
		}
		k--;
		return w;
	}
}
bool List_tab::is_empty()
{
	return !k;/*
	if (k == 0)
	{
		return 1;
	}
	else 
	{
		return 0;
	}
	*/
}
int List_tab::size()
{
	return k;
}

List_tab::~List_tab()
{
	delete [] tablica;
}