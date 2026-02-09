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
	val = "";
	emp = 1;
}

node::node(node* a, string k)
{
	lt = NULL;
	rt = NULL;
	parent = a;/*
	for (int i = 0; i <= k.length(); i++)
	{
		val[i] = k[i];
	}*/
	val = k;
	emp = 0;
}
//(*root).left ==NULL && (*root).right == NULL

void Bin_tree::add(string k)
{
	node* a = root;
	if ((*root).emp)
	{
		(*root).val = k;
		(*root).emp = 0;
		return;
	}
	this->search_emp(k);
	int i = 0;
	while (1)
	{
		if ((*a).lt == NULL && tab[i] == 0)
		{
			(*a).lt = new class node(a, k);
			break;
		}
		else if ((*a).rt == NULL && tab[i] == 1)
		{
			(*a).rt = new class node(a, k);
			break;
		}
		else if (tab[i] == 0)
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

void Bin_tree::search_emp(string k)
{
	bool tmp[10];
	min = 100;
	for (int i = 0; i < 10; i++)
	{
		tmp[i] = 0;
	}
	(*root).search_emp(tab, tmp, 0, k);
}
void node::search_emp(bool* a, bool* b, int i, string k)
{
	if (emp)
	{
		return;
	}
	else
	{
		if (!az(k, val))
		{
			b[i] = 0;
			if (lt == NULL)
			{
				for (int i = 0; i < 10; i++)
				{
					a[i] = b[i];
				}
				return;
			}
			(*lt).search_emp(a, b, i + 1, k);
		}
		else
		{
			b[i] = 1;
			if (rt == NULL)
			{
				for (int i = 0; i < 10; i++)
				{
					a[i] = b[i];
				}
				return;
			}
			(*rt).search_emp(a, b, i + 1, k);
		}
	}
}

bool node::az(string k, string nie_k)
{
	string k_m;
	string k_n;
	int i;
	for (i = 0; k[i] != ' '; i++)
	{
	}
	k_m = k.substr(0, i);
	i++;
	for (int j = 0; k[i+j] < k.length(); j++)
	{
	}
	k_n = k.substr(i, k.length());
	//cout << k_n << endl;
	string nie_k_m;
	string nie_k_n;

	for (i = 0; nie_k[i] != ' '; i++)
	{
	}
	nie_k_m = nie_k.substr(0, i);
	i++;
	for (int j = 0; nie_k[i + j] < nie_k.length(); j++)
	{
	}
	nie_k_n = nie_k.substr(i, nie_k.length());

	
	int l = k_n.length();
	if (nie_k_n.length() < l)
	{
		l = nie_k_n.length();
	}
	for (int i = 0; i < l; i++)
	{
		if (k_n[i] < nie_k_n[i])
		{
			//cout << k_n[i] << "<" << nie_k_n[i] << endl;
			return 0;
		}
		if (k_n[i] > nie_k_n[i])
		{
			//cout << k_n[i] << ">" << nie_k_n[i] << endl;
			return 1;
		}
	}
	if (k_n.length() < nie_k_n.length())
	{
		return 0;
	}
	else if (k_n.length() > nie_k_n.length())
	{
		return 1;
	}
	else
	{
		l = k_m.length();
		if (nie_k_m.length() < l)
		{
			l = nie_k_m.length();
		}
		for (int i = 0; i < l; i++)
		{
			if (k_m[i] < nie_k_m[i])
			{
				return 0;
			}
			if (k_m[i] > nie_k_m[i])
			{
				return 1;
			}
		}
		if (k_m.length() < nie_k_m.length())
		{
			return 0;
		}
		else if (k_m.length() > nie_k_m.length())
		{
			return 1;
		}
		else
		{
			return 0;
		}
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
	int c = 1;
	node* nd = root;
	node* pr = nd;
	int r = 0;
	while (1)
	{
		cout << "Wartosc = " << (*nd).val << "\nLewo = 0\nPrawo = 1\nUsun = -1\n";
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
		(*nd).val = "";
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
			if (c)
			{
				delete nd;
			}
			if (lr)
			{
				//cout << "B" << endl;
				(*pr).rt = NULL;
			}
			else
			{
				//cout << "A" << endl;
				(*pr).lt = NULL;
			}
			//cout << "D" << endl;
			break;
		}
		else if ((*nd).lt)
		{
			pr = nd;
			(*nd).val = (*(*nd).lt).val;
			//cout << "L" << endl;
			nd = (*nd).lt;
			lr = 0;
		}
		else
		{
			pr = nd;
			(*nd).val = (*(*nd).rt).val;
			//cout << "R" << endl;
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

bool node::check(string k, string czy_k)
{
	if (k.length() == czy_k.length())
	{
		for (int i = 0; i < k.length(); i++)
		{
			if (k[i] != czy_k[i])
			{
				return 0;
			}
		}
	}
	else
	{
		return 0;
	}
	return 1;
}

void Bin_tree::search_val(string val)
{
	//cout << "AAAAAAAAAAAAAA\n";
	bool a[10];
	for (int i = 0; i < 10; i++)
	{
		a[i] = 0;
	}
	node* b = root;
	int i = 0;
	int czy;
	cout << "\nBFS =1 / DFS =0" << endl;
	cin >> czy;
	(*b).search_range(1, &min, &max);
	if (czy)
	{
		czy = (*root).search_val_b(a, val, max);
	}
	else
	{
		czy = (*root).search_val(a, 0,val);
	}
	if ((*root).search_val_b(a,val, max))
	{
		cout << "\nWartosc znaleziona, scierzka:\n";
		while (!(*b).check((*b).val,val))
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
	else
	{
		cout << "\nNie ma tekiej wartosci\n";
	}

}

int node::search_val(bool* a, int i, string v)
{
	//cout << "v = " << val << endl;
	int c;
	if (check(val, v))
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
		return 0;
	}
	return 0;
}
int node::search_val_b(bool* a, string v, int max)
{
	int lim = 0;
	int aaa = 1;
	int j = 1;
	int c = 1;;
	node* t = this;
	while (!a[max])
	{
		for (int tmp = 0; tmp < j; tmp++)
		{
			if (aaa)
			{
				break;
			}
			if (((*t).lt == NULL && a[tmp] == 0) || ((*t).rt == NULL && a[tmp] == 1))
			{
				break;
			}
			//cout << "j=" << j << endl;
			if (a[tmp] == 0)
			{
				//cout << "ltmp =" << tmp << endl;
				t = (*t).lt;
			}
			else
			{
				//cout << "rtmp =" << tmp << endl;
				t = (*t).rt;
			}
			if (tmp == j)
			{
				break;
			}
		}
		//cout << "l = " << lim << endl;
		c = 1;
		if ((*t).val.length() == v.length())
		{
			for (int i = 0; i < val.length(); i++)
			{
				if ((*t).val[i] != v[i])
				{
					c = 0;
				}
			}
		}
		else
		{
			c = 0;
		}
		if (c)
		{
			return 1;
		}
		for (int i = 0;; i++)
		{
			if (aaa)
			{
				aaa = 0;
				break;
			}
			if (!a[i])
			{
				for (int l = 0; l < i; l++)
				{
					a[l] = 0;
				}
				a[i] = 1;
				if (i > j)
				{
					j = i;
				//	cout << "J = " << j << endl;
				}
				break;
			}
		}
		lim++;
		t = this;
	}


}
void node::search_range(int i, int* min, int* max)
{
	//cout << "i: " << i << endl;
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