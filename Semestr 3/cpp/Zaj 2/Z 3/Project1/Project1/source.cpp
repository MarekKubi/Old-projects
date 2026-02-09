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
	else if (poz == 0)
	{
		cout << tail << "/" << (*tail).point << endl;
		node* a = tail;
		tail = new node(a, element);
	}
	else if (poz > k - 1)
	{
		k--;
		cout << endl << endl << "!!! LISTA NIE JEST TAKA DUZA !!!" << endl << endl;
	}
	else
	{
		node* a = tail;
		for (int i = 0; i < poz - 1; i++)
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
	if (poz > k - 1)
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

void List::print()
{
	node* a = tail;
	for (int i = 0; i < k; i++)
	{
		cout << (*a).val << endl;
		a = (*a).point;
	}
}

int List::give(int a)
{
	node* b= tail;
	for (int i = 0; i < a; i++)
	{
		b = (*b).point;
	}
	return (*b).val;
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

int fun_fun(List l)
{
	int a = 0;
	int w = l.give(0);
	//cout << "AAA" << endl;
	for (int i = 0; i < l.k; i++)
	{
		if (l.give(i) % w == 0)
		{
			a++;
		}
	}
	return a;
}