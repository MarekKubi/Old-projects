#include "header.h"


Bin_tree::Bin_tree()
{
	root = new class node();
	for (int i = 0; i < 10; i++)
	{
		tab[i] = 0;
	}
}
node::node()
{
	lt = NULL;
	rt = NULL;
	parent = NULL;
	val = 0;
	emp = 1;
}

node::node(node* a, int k)
{
	lt = NULL;
	rt = NULL;
	parent = a;
	val = k;
	emp = 0;
}
//(*root).left ==NULL && (*root).right == NULL

void Bin_tree::add(int k)
{
	node* a = root;
	if ((*root).emp)
	{
		(*root).val = k;
		(*root).emp = 0;
		return;
	}
	this->search_emp();
	int i = 0;
	while (1)
	{
		if ((*a).lt == NULL )
		{
			(*a).lt = new class node(a, k);
			break;
		}
		else if ((*a).rt == NULL)
		{
			(*a).rt = new class node(a, k);
			break;
		}
		else if (tab[i] ==0)
		{
			a = (*a).lt;
		}
		else
		{
			a = (*a).rt;
		}
		i++;
	}
}

void Bin_tree::search_emp()
{
	bool tmp[10];
	min = 100;
	for (int i = 0; i < 10; i++)
	{
		tmp[i] = 0;
	}
	(*root).search_emp(tab, tmp, 0, &min);
}
void node::search_emp(bool* a, bool* b, int i, int* min)
{
	if (lt == NULL || rt == NULL)
	{
		if (i < (*min))
		{
			(*min) = i;
			for (int i = 0; i < 10; i++)
			{
				a[i] = b[i];
			}
		}
	}
	else
	{
		b[i] = 0;
		(*lt).search_emp(a, b, i + 1, min);
		b[i] = 1;
		(*rt).search_emp(a, b, i + 1, min);
	}
}


void Bin_tree::rm()
{
	if ((*root).emp)
	{
		cout << "Drzewo jest puste!!!\n";
		return;
	}
	int a;
	bool lr = 0;
	int  c = 1;
	node* nd =root;
	node* pr =nd;
	int r = 0;
	while (1)
	{
		cout << "Wartosc = "<< (*nd).val << "\nLewo = 0\nPrawo = 1\nUsun = -1\n";
		cin >> a;
		a++;
		if (a)
		{
			pr = nd;
			a--;
			if (a == 0)
			{
				lr = 0;
				if ((*nd).lt)
				{
					tab[r] = 0;
					nd = (*nd).lt;
				}
				else
				{
					cout << "BRAK ELEMENTU!!!\n";
					return;
				}
			}
			else
			{
				if ((*nd).rt)
				{
					lr = 1;
					tab[r] = 1;
					nd = (*nd).rt;
				}
				else
				{
					cout << "BRAK ELEMENTU!!!\n";
					return;
				}
			}
			r++;
		}
		else
		{
			break;
		}
	}
	if ((*nd).parent == NULL)
	{
		(*nd).val = 0;
		c = 0;
		if ((*nd).lt == NULL && (*nd).rt == NULL)
		{
			(*nd).emp = 1;
		}
	}
	while (1)
	{
		//cout << "l = "  << (*nd).lt << endl;
		//cout << "r= " << (*nd).rt << endl;
		if ((*nd).lt == NULL && (*nd).rt == NULL)
		{
			delete nd;
			if (lr)
			{
				cout << "B" << endl;
				(*pr).rt = NULL;
			}
			else
			{
				cout << "A" << endl;
				(*pr).lt = NULL;
			}
			cout << "D" << endl;
			break;
		}
		else if ((*nd).lt)
		{
			pr = nd;
			(*nd).val = (*(*nd).lt).val;
			cout << "L" << endl;
			nd = (*nd).lt;
			lr = 0;
		}
		else
		{
			pr = nd;
			(*nd).val = (*(*nd).rt).val;
			cout << "R" << endl;
			nd = (*nd).rt;
			lr = 1;
		}
	}
}

void Bin_tree::pokaz(node* a)
{
	//cout << "l = " << (*a).lt << endl;
	//cout << "r= " << (*a).rt << endl;
	cout << (*a).val;
	if ((*a).lt)
	{
		cout << "L> ";
		pokaz((*a).lt);
	}
	else
	{
		cout << "L| ";
	}
	if ((*a).rt)
	{
		cout << "R> ";
		pokaz((*a).rt);
	}
	else
	{
		cout << "R| ";
	}
}
void Bin_tree::pokaz_w()
{
	pokaz(root);
}


void Bin_tree::search_val(int val)
{
	//cout << "AAAAAAAAAAAAAA\n";
	bool a[10];
	for (int i = 0; i < 10; i++)
	{
		a[i] = 0;
	}
	if ((*root).val == val)
	{
		cout << "Wartosc znalezionaw pierwszym wezle\n";
	}
	node* b = root;
	int i = 0;
	if ((*root).search_val(a, 0, val))
	{
		cout << "Wartosc znaleziona, scierzka:\n";
		while ((*b).val != val)
		{
			if (a[i]) 
			{
				cout << "R > ";
				b = (*b).rt;
			}
			else
			{
				cout << "L > ";
				b = (*b).lt;
			}
			i++;
		}
	}

}

int node::search_val(bool* a, int i, int v)
{
	//cout << "v = " << val << endl;
	int c;
	if (val == v)
	{
		return 1;
	}
	if (lt == NULL && rt == NULL)
	{
		return 0;
	}
	else
	{
		//cout << "i = " << i << endl;
		a[i] = 0;
		if (lt)
		{
			//cout << "l = " << lt << endl;
			c = (*lt).search_val(a, i + 1, v);
			if (c)
			{
				return 1;
			}
		}
		a[i] = 1;
		if (rt)
		{
			//cout << "r= " << rt << endl;
			c = (*rt).search_val(a, i + 1, v);
			if (c)
			{
				return c;
			}
		}
		i++;
	}
	if (parent == NULL)
	{
		return -1;
	}
	return 0;
}

void node::search_range(int i, int* min, int* max)
{
	cout << "i: " << i << endl;
	if (lt == NULL && rt == NULL)
	{
		if (i < (*min))
		{
			cout << "min: " << val << endl;
			(*min) = i;
		}
		if (i > (*max))
		{
			cout << "max: " << val << endl;
			(*max) = i;
		}
	}
	else
	{
		if (lt)
		{
			(*lt).search_range(i + 1, min, max);
		}
		if (rt)
		{
			(*rt).search_range(i + 1, min, max);
		}
	}
}
void Bin_tree::search_range()
{
	min = 100;
	max = 0;
	(*root).search_range(0, &min, &max);
	cout << "Rozpietosc drzewa to: " << (max - min) << endl;
}
void Bin_tree::search_hight()
{
	min = 100;
	max = 0;
	(*root).search_range(0, &min, &max);
	cout << "Wysokosc drzewa to: " << max<< endl;
}