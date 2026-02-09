#include "header.h"

Sort::Sort()
{
	k = 0;
	tab = NULL;
}
Sort::Sort(int* ka, int a)
{
	k = a;
	tab = ka;
}
void Sort::pokaz()
{
	cout << "Tablica:" << endl;
	for (int i = 0; i < k; i++)
	{
		cout << tab[i] << " ";
	}
	cout << endl;
}

void Sort::buble()
{
	int temp;
	for (int i = 0; i < k; i++)
	{
		for (int j = 1; j < k - i; j++)
		{
			if (tab[j] > tab[j - 1])
			{
				temp = tab[j];
				tab[j] = tab[j - 1];
				tab[j - 1] = temp;
			}
		}
	}
}

void Sort::selection()
{
	int max;
	int temp;
	for (int i = 0; i < k-1; i++)
	{
		max = i;
		for (int j = i; j < k; j++)
		{
			if (tab[i] < tab[j])
			{
				max = j;
			}
		}
		if (max != i)
		{
			temp = tab[i];
			tab[i] = tab[max];
			tab[max] = temp;
		}
	}
}

void Sort::insertion()
{
	int temp;
	for (int i = 1; i < k; i++)
	{
		for (int j = i; j > 0; j--)
		{
			if (tab[j] > tab[j - 1])
			{
				temp = tab[j];
				tab[j] = tab[j - 1];
				tab[j - 1] = temp;
			}
			else
			{
				break;
			}
		}
	}
}

//////////////////////////////////

void Sort::merge()
{
	merge(0, k-1);
}

void Sort::merge(int l, int p)
{
	if (l >= p)
	{
		return;
	}
	int s = l + ((p - l) / 2);
	merge(l, s);
	merge(s+1, p);
	mergemerge(l, s, p);
}
void Sort::mergemerge(int l, int s, int p)
{
	int* tablica = new int[((p-l)+1)];
	int i = 0;
	int j = 0;
	while ((i < s - l) && (j < p - s))
	{
		if (tab[l + i] > tab[s + j])
		{
			tablica[i + j] = tab[l + i];
			i++;
		}
		else
		{
			tablica[i + j] = tab[s + j];
			j++;
		}
	}
	while (i < s - l)
	{
		tablica[i + j] = tab[l + i];
		i++;
	}
	while (j < p - s)
	{
		tablica[i + j] = tab[s + j];
		j++;
	}
	for (i = 0; i < (p - l)+1; i++)
	{
		tab[i] = tablica[i];
	}
	delete[] tablica;
}
void Sort::quick()
{
	quick(0, k - 1);
}
void Sort::quick(int l, int p)
{
	//cout << "a" << endl;
	int temp;
	if (p <= l)
	{
		return;
	}

	int i = l - 1;
	int j = p + 1;
	int pivot = tab[(l + p) / 2];

	while (1)
	{
		while (pivot > tab[++i]);
		while (pivot < tab[--j]);

		if (i <= j)
		{
			temp = tab[i];

			tab[i] = tab[j];

			tab[j] = temp;
		}
		else
		{
			break;
		}
	}
	//cout << "a" << endl;

	if (j > l)
	{
		quick(l, j);
	}
	if (i < p)
	{
		quick(i, p);
	}
}




void Sort::kopcowanie()
{
	Bin_tree a;
	for (int i = 0; i < k; i++)
	{
		a.add(tab[i]);
	}
	for (int i = 0; i < k; i++)
	{
		tab[i] = a.rm();
	}
}

//////////////////////
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

node::node(node* a, int k)
{
	kategoria = 'a';
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
		if ((*a).lt == NULL)
		{
			(*a).lt = new class node(a, k);
			break;
		}
		else if ((*a).rt == NULL)
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
	sort();
	//pokaz_w();
	//cout << endl;
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


int Bin_tree::rm()
{
	if ((*root).emp)
	{
		cout << "Drzewo jest puste!!!\n";
		return -1;
	}
	int a;
	bool lr = 0;
	int  c = -1;
	node* nd = root;
	node* pr = nd;
	int r = 0;
	int ba = (*root).val;

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
			//cout << "L" << endl;
			nd = (*nd).lt;
			lr = 0;
		}
		else if ((*nd).rt && !(*nd).lt)
		{
			pr = nd;
			(*nd).val = (*(*nd).rt).val;
			//cout << "R" << endl;
			nd = (*nd).rt;
			lr = 1;
		}
		else if ((*(*nd).lt).val >= (*(*nd).rt).val)
		{
			pr = nd;
			(*nd).val = (*(*nd).lt).val;
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
	cout << "Wysokosc drzewa to: " << max << endl;
}

bool node::sort(node* point)
{
	//cout << "v = " << val << endl;
	int c;
	int tmp;
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

	}
	if (lt == NULL && rt == NULL)
	{
		return 0;
	}//(((!(*nd).rt) && ((*nd).lt) || (*(*nd).lt).val > (*(*nd).t).val) && ((*(*nd).lt).val > (*nd).val))
	else if (lt || !rt)
	{
		if (lt)
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
		if (rt && !c)
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
	}
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
	int a = 0;
	while (!brr.is_emp())
	{
		a = brr.rm();
		//cout << "RM: " << a.l << endl;
		add(a);
		sort();
	}
}

bool Bin_tree::is_emp()
{
	return (*root).emp;
}