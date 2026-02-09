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
info::info(int ka, char ce)
{
	l = ka;
	c = ce;
}

node::node(node* a, info k)
{
	kategoria = k.c;
	lt = NULL;
	rt = NULL;
	parent = a;
	val = k.l;
	emp = 0;
}
//(*root).left ==NULL && (*root).right == NULL

void Bin_tree::add(int k, char c)
{
	info ka(k, c);
	node* a = root;
	if ((*root).emp)
	{
		(*root).val = k;
		(*root).kategoria = c;
		(*root).emp = 0;
		return;
	}
	this->search_emp();
	int i = 0;
	while (1)
	{
		if ((*a).lt == NULL)
		{
			(*a).lt = new class node(a, ka);
			break;
		}
		else if ((*a).rt == NULL)
		{
			(*a).rt = new class node(a, ka);
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


info Bin_tree::rm()
{
	info def = info(-1, 'p');
	if ((*root).emp)
	{
		cout << "Drzewo jest puste!!!\n";
		return def;
	}
	int a;
	bool lr = 0;
	int  c = -1;
	node* nd = root;
	node* pr = nd;
	int r = 0;
	info ba = info((*root).val, (*root).kategoria);
	while (1)
	{
		//cout << "Wartosc = " << (*nd).val << "\nLewo = 0\nPrawo = 1\nUsun = -1\n";
		//cout << "-1";
		a = -1;
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
					return def;
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
					return def;
				}
			}
			r++;
		}
		else
		{
			//ba = info((*nd).val, (*nd).kategoria);
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
	//cout << "Wartosc = " << (*nd).val << "\nLewo = 0\nPrawo = 1\nUsun = -1\n";
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
		}//(((!(*nd).rt) && ((*nd).lt) || (*(*nd).lt).val > (*(*nd).t).val) && ((*(*nd).lt).val > (*nd).val))
		else if ((*nd).lt && !(*nd).rt)
		{
			pr = nd;
			(*nd).val = (*(*nd).lt).val;
			(*nd).kategoria = (*(*nd).lt).kategoria;
			//cout << "L" << endl;
			nd = (*nd).lt;
			lr = 0;
		}
		else if ((*nd).rt && !(*nd).lt)
		{
			pr = nd;
			(*nd).val = (*(*nd).rt).val;
			(*nd).kategoria = (*(*nd).rt).kategoria;
			//cout << "R" << endl;
			nd = (*nd).rt;
			lr = 1;
		}
		else if ((*(*nd).lt).val >= (*(*nd).rt).val)
		{
			pr = nd;
			(*nd).val = (*(*nd).lt).val;
			(*nd).kategoria = (*(*nd).lt).kategoria;
			//cout << "L" << endl;
			nd = (*nd).lt;
			lr = 0;
		}
		else
		{
			//cout << "Wartosc = " << (*nd).val << "\nLewo = 0\nPrawo = 1\nUsun = -1\n";
			//cout << "L ="  << (*(*nd).lt).val << endl;
			//cout << "R =" << (*(*nd).rt).val << endl;
			pr = nd;
			(*nd).val = (*(*nd).rt).val;
			(*nd).kategoria = (*(*nd).rt).kategoria;
			//cout << "R" << endl;
			nd = (*nd).rt;
			lr = 1;
		}
	}
	return ba;
}

void Bin_tree::pokaz(node* a)
{
	//cout << "l = " << (*a).lt << endl;
	//cout << "r= " << (*a).rt << endl;
	cout << (*a).val << (*a).kategoria;
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
	cout << "Wysokosc drzewa to: " << max << endl;
}

bool node::sort(node* point)
{
	//cout << "v = " << val << endl;
	int c;
	int tmp;
	char tmp_c;
	if (parent != NULL)
	{
		if (val > (*parent).val)
		{
			point = this;
			tmp = val;
			tmp_c = kategoria;
			val = (*parent).val;
			kategoria = (*parent).kategoria;
			(*parent).val = tmp;
			(*parent).kategoria = tmp_c;
			return 1;
		}

	}
	if (lt == NULL && rt == NULL)
	{
		return 0;
	}//(((!(*nd).rt) && ((*nd).lt) || (*(*nd).lt).val > (*(*nd).t).val) && ((*(*nd).lt).val > (*nd).val))
	else if (lt && !rt)
	{
		c = (*lt).sort(point);
		if (c)
		{
			if (parent != NULL)
			{
				if (val > (*parent).val)
				{
					point = this;
					tmp = val;
					tmp_c = kategoria;
					val = (*parent).val;
					kategoria = (*parent).kategoria;
					(*parent).val = tmp;
					(*parent).kategoria = tmp_c;
					return 1;
				}
				else
				{
					return 0;
				}

			}
		}
	}
	else if (rt && !lt)
	{
		c = (*rt).sort(point);
		if (c)
		{

			if (parent != NULL)
			{
				if (val > (*parent).val)
				{
					point = this;
					tmp = val;
					tmp_c = kategoria;
					val = (*parent).val;
					kategoria = (*parent).kategoria;
					(*parent).val = tmp;
					(*parent).kategoria = tmp_c;
					return 1;
				}
				else
				{
					return 0;
				}
			}
		}
	}
	else 
	{
		c = (*lt).sort(point);
		if (c)
		{
			if (parent != NULL)
			{
				if (val > (*parent).val)
				{
					point = this;
					tmp = val;
					tmp_c = kategoria;
					val = (*parent).val;
					kategoria = (*parent).kategoria;
					(*parent).val = tmp;
					(*parent).kategoria = tmp_c;
					return 1;
				}
				else
				{
					return 0;
				}

			}
		}c = (*rt).sort(point);
		if (c)
		{

			if (parent != NULL)
			{
				if (val > (*parent).val)
				{
					point = this;
					tmp = val;
					tmp_c = kategoria;
					val = (*parent).val;
					kategoria = (*parent).kategoria;
					(*parent).val = tmp;
					(*parent).kategoria = tmp_c;
					return 1;
				}
				else
				{
					return 0;
				}
			}
		}
	}
	/*
	if (lt == NULL && rt == NULL)
	{
		return 0;
	}
	else
	{
		//cout << "i = " << i << endl;
		if (lt)
		{
			//cout << "l = " << lt << endl;
			c = (*lt).sort(point);
			if (c)
			{
				if (parent != NULL)
				{
					if (val > (*parent).val)
					{
						point = this;
						tmp = val;
						val = (*parent).val;
						(*parent).val = tmp;
						return 1;
					}
					else
					{
						return 0;
					}

				}
			}
		}
		if (rt)
		{
			//cout << "r= " << rt << endl;
			c = (*rt).sort(point);
			if (c)
			{

				if (parent != NULL)
				{
					if (val > (*parent).val)
					{
						point = this;
						tmp = val;
						val = (*parent).val;
						(*parent).val = tmp;
						return 1;
					}
					else
					{
						return 0;
					}
				}
			}
		}
	}*/
	if (parent == NULL)
	{
		return -1;
	}
	return 0;
}

void Bin_tree::sort()
{
	node* point = NULL;
	(*root).sort(point);
}

void Bin_tree::merge(Bin_tree brr)
{
	info a = info(0, 'p');
	while (!brr.is_emp())
	{
		a = brr.rm();
		//cout << "RM: " << a.l << endl;
		add(a.l, a.c);
		sort();
	}
}

bool Bin_tree::is_emp()
{
	return (*root).emp;
}

void Bin_tree::split(Bin_tree a, Bin_tree b, Bin_tree c, Bin_tree d)
{
	info h = info(0, 'p');
	while (!(*this).is_emp())
	{
		h = (*this).rm();
		//cout << "RM: " << a.l << endl;
		cout << "h=" << h.c << h.l << endl;
		switch (h.c)
		{
		case 'a':
			a.add(h.l, h.c);
			a.sort();
			break;
		case 'b':
			b.add(h.l, h.c);
			b.sort();
			break;
		case 'c':
			c.add(h.l, h.c);
			c.sort();
			break;
		case 'd':
			d.add(h.l, h.c);
			d.sort();
			break;
		}
	}
}