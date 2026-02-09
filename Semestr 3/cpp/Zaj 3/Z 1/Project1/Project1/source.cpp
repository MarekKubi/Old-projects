#include "header.h"
//int sum = 0;



node::node(node* poi, int v[3])
{
	point = poi;
	for (int i = 0; i < 3; i++)
	{
		val[i] = v[i];
		score[i] = 0;
	}
	is_empty = 0;
	total = 0;
}
node::node(node* poi, tablica v)
{
	point = poi;
	for (int i = 0; i < 3; i++)
	{
		val[i] = v.tab[i];
		score[i] = v.score[i];
	}
	is_empty = 0;
	total = 0;
}
node::node()
{
	point = 0;
	for (int i = 0; i < 3; i++)
	{
		val[i] = 0;
		score[i] = 0;
	}
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
void List::add(int element[3], int poz)
{
	k++;
	if ((*head).is_empty && poz == 0)
	{
		for (int i = 0; i < 3; i++)
		{
			(*head).val[i] = element[i];
		}
		(*head).is_empty = 0;
	}
	else if (poz == 0)
	{
		//cout << tail << "/" << (*tail).point << endl;
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
		for (int i = 0; i < 3; i++)
		{
			(*b).val[i] = element[i];
		}
		(*a).point = b;
	}
}
void List::add(tablica element, int poz)
{
	//cout << 1 << endl;
	k++;
	if ((*head).is_empty && poz == 0)
	{
		for (int i = 0; i < 3; i++)
		{
			(*head).val[i] = element.tab[i];
			(*head).score[i] = element.score[i];
		}
		(*head).is_empty = 0;
		//cout << 2 << endl;
	}
	else if (poz == 0)
	{
		//cout << tail << "aaaaaaaaaaaaaaaaaaaaaaaaa" << (*tail).point << endl;
		//cout << tail << "/" << (*tail).point << endl;
		//cout << 3 << endl;
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
		//cout << 4 << endl;
		node* a = tail;
		for (int i = 0; i < poz - 1; i++)
		{
			a = (*a).point;
		}
		node* b = new node;
		(*b).point = (*a).point;
		for (int i = 0; i < 3; i++)
		{
			(*b).val[i] = element.tab[i];
			(*b).score[i] = element.score[i];
		}
		(*a).point = b;
	}
}
tablica List::remove(int poz)
{
	//cout<<endl<<endl<<"k=" << k << endl << endl;
	//cout << endl << endl << "tail=" << tail << endl << endl;
	//cout << endl << endl << "head=" << head << endl << endl;
	if (poz > k - 1)
	{
		cout << endl << endl << "!!! TAKI ELEMEN NIE ISTNIEJE !!!" << endl << endl;
		tablica a;
		return a;
	}
	else if (tail == head)
	{
		//cout << endl << endl << "!!!!!!!!!!!!!!!!!!!!!!!" << endl << endl;
		(*tail).is_empty = 1;
		k--;
		tablica tab;
		for (int i = 0; i < 3; i++)
		{
			tab.tab[i] = (*tail).val[i];
			tab.score[i] = (*tail).score[i];
		}
		return tab;
	}
	else if (poz == 0)
	{
		//cout << endl << endl << "mmmmmmmmmmmmm" << endl << endl;
		//cout << "AAAAAAAAAAAAAAAAAAAAA" << endl;
		//cout << tail << "/" << (*tail).point << endl;
		k--;
		tablica w;
		for (int i = 0; i < 3; i++)
		{
			w.tab[i] = (*tail).val[i];
			w.score[i] = (*tail).score[i];
		}
		node* b = tail;
		tail = (*tail).point;
		delete b;
		return w;
	}
	else
	{
		//cout << endl << endl << "mmmmmmmmmmmmm" << endl << endl;
		//	cout << "nnnnnnnnnnnnnnnnnnnnn" << endl;
			//cout << tail << "/" << (*tail).point << endl;
		k--;
		node* a = tail;
		for (int i = 0; i < poz - 1; i++)
		{
			a = (*a).point;
		}
		tablica w;
		for (int i = 0; i < 3; i++)
		{
			w.tab[i] = (*(*a).point).val[i];
		}
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
		for (int j = 0; j < 3; j++)
		{
			cout << (*a).val[j] << "	";
		}
		for (int j = 0; j < 3; j++)
		{
			cout << (*a).score[j] << "	";
		}
		cout << endl;
		a = (*a).point;
	}
}
void List::print_s()
{
	node* a = tail;
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << (*a).val[j] << "	";
		}
		for (int j = 0; j < 3; j++)
		{
			cout << (*a).score[j] << "	";
		}
		cout << (*a).total << "	" << (*a).wyd;
		cout << endl;
		a = (*a).point;
	}
}

tablica List::give(int a)
{
	node* b = tail;
	for (int i = 0; i < a; i++)
	{
		b = (*b).point;
	}
	tablica w;
	for (int i = 0; i < 3; i++)
	{
		//cout <<"give = " << (*b).val[i] << endl;
		w.tab[i] = (*b).val[i];
	}
	return w;
}
tablica List::give_s(int a)
{
	node* b = tail;
	for (int i = 0; i < a; i++)
	{
		b = (*b).point;
	}
	tablica w;
	for (int i = 0; i < 3; i++)
	{
		w.tab[i] = (*b).val[i];
		w.score[i] = (*b).score[i];
	}
	return w;
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

tablica::tablica()
{

	for (int i = 0; i < 3; i++)
	{
		tab[i] = 2137;
		score[i] = 420;
	}
}
tablica::tablica(int t[3], int s[3])
{

	for (int i = 0; i < 3; i++)
	{
		tab[i] = t[i];
		score[i] = s[i];
	}
}

dzban::dzban()
{
	int a[3];
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			a[j] = (rand() % 10) + 1;
		}
		Master.add(a, 0);
	}
}

void dzban::split()
{
	tablica a;
	for (int i = 0; i < 30; i++)
	{
		//cout << i << endl;
		a = Master.give_s(0);
		if (a.score[0]> a.score[1] && a.score[0]> a.score[2])
		{
			//cout << "aaaaa" << endl;
			WIMiIP.add(Master.remove(0),0);
		}
		else if (a.score[1] > a.score[2])
		{
			//cout << "bbbb" << endl;
			WIMiR.add(Master.remove(0), 0);
		}
		else
		{
			//cout << "cccc" << endl;
			WIEiT.add(Master.remove(0), 0);
		}
	}
}


void dzban::print()
{
	cout << "WIMiIP" << endl;
	WIMiIP.print();
	cout << "WIMiR" << endl;
	WIMiR.print();
	cout << "WIEiT" << endl;
	WIEiT.print();
	if (!Budowlanka.is_empty())
	{
		cout << "Budowlanka" << endl;
		Budowlanka.print();
	}
	cout << "......................."<< endl;
	if (!NMaster.is_empty())
	{
		cout << "Master" << endl;
		NMaster.print_s();
	}
}


void dzban::ev()
{
	Master.ev();
}

void List::ev()
{
	int tab[30];
	node* a;
	int b;
	int c;
	for (int i = 0; i < 3; i++)
	{
		a = tail;
		for (int j = 0; j < 30; j++)
		{
			tab[j] = (*a).val[i];
			a = (*a).point;

		}
		sortu(tab, i, 0, 29);
		a = tail;
		b = 0;
		c = 0;
		for (int j = 0; j < 30; j++)
		{
			if (c== (*a).val[i] && (*a).val[(i + 1) % 3] < b)
			{
				swap_m(tab, j, j - 1);
			}
			c = (*a).val[i];
			b = (*a).val[(i + 1) % 3];
			a = (*a).point;
		}
		a = tail;
		b = 0;
		c = 0;
		for (int j = 0; j < 30; j++)
		{
			if (c == (*a).val[i]&& (*a).val[(i + 2) % 3] < b)
			{
				swap_m(tab, j, j - 1);
			}
			c = (*a).val[i];
			b = (*a).val[(i + 2) % 3];
			a = (*a).point;
		}
		a = tail;
		b = 0;
		c = 0;
		for (int j = 0; j < 30; j++)
		{
			(*a).score[i] = j;
			a = (*a).point;
		}
	}
}

void List::sortd(int* tab, int v, int l, int p)
{/*
	node* a;
	if (1)
	{
		a = tail;
		for (int j = 0; j < k; j++)
		{
			cout << (*a).val[v] << "/";
			a = (*a).point;
		}
		cout << endl << "a" << endl;
		for (int j = 0; j < k; j++)
		{
			cout << tab[j] << "/";
		}
		cout << endl << endl;
	}*/
	//sum++;
	if (p <= l) return;

	int i = l - 1;
	int j = p + 1;
	int pivot = tab[(l + p) / 2];
	while (1)
	{
		//szukam elementu wiekszego lub rownego piwot stojacego
		//po prawej stronie wartosci pivot
		while (pivot < tab[++i]);

		//szukam elementu mniejszego lub rownego pivot stojacego
		//po lewej stronie wartosci pivot
		while (pivot > tab[--j]);

		//jesli liczniki sie nie minely to zamieñ elementy ze soba
		//stojace po niewlasciwej stronie elementu pivot
		if (i <= j)
			//funkcja swap zamienia wartosciami tab[i] z tab[j]
			swap_m(tab, i, j);
		else
			break;
	}

	if (j > l)
		sortd(tab, v, l, j);
	if (i < p)
		sortd(tab, v, i, p);
}

void List::sortu(int* tab, int v, int l, int p)
{/*
	node* a;
	if (1)
	{
		a = tail;
		for (int j = 0; j < k; j++)
		{
			cout << (*a).val[v] << "/";
			a = (*a).point;
		}
		cout << endl << "a" << endl;
		for (int j = 0; j < k; j++)
		{
			cout << tab[j] << "/";
		}
		cout << endl << endl;
	}*/
	//sum++;
	if (p <= l) return;

	int i = l - 1;
	int j = p + 1;
	int pivot = tab[(l + p) / 2];
	while (1)
	{
		//szukam elementu wiekszego lub rownego piwot stojacego
		//po prawej stronie wartosci pivot
		while (pivot > tab[++i]);

		//szukam elementu mniejszego lub rownego pivot stojacego
		//po lewej stronie wartosci pivot
		while (pivot < tab[--j]);

		//jesli liczniki sie nie minely to zamieñ elementy ze soba
		//stojace po niewlasciwej stronie elementu pivot
		if (i <= j)
			//funkcja swap zamienia wartosciami tab[i] z tab[j]
			swap_m(tab, i, j);
		else
			break;
	}

	if (j > l)
		sortu(tab, v, l, j);
	if (i < p)
		sortu(tab, v, i, p);
}

void List::swap_m(int* tab, int a, int b)
{
	node* a_l = tail;
	for (int i = 0; i < a; i++)
	{
		a_l = (*a_l).point;
	}
	node* b_l = tail;
	for (int i = 0; i < b; i++)
	{
		b_l = (*b_l).point;
	}
	int temp = tab[a];
	int tval[3];
	int tsc[3];
	for (int i = 0; i < 3; i++)
	{
		tval[i] = (*a_l).val[i];
		tsc[i] = (*a_l).score[i];
	}

	for (int i = 0; i < 3; i++)
	{
		(*a_l).val[i] = (*b_l).val[i];
		(*a_l).score[i] = (*b_l).score[i];
	}
	tab[a] = tab[b];

	for (int i = 0; i < 3; i++)
	{
		(*b_l).val[i] = tval[i];
		(*b_l).score[i] = tsc[i];
	}
	tab[b] = temp;
}

void dzban::bud()
{
	Master.bud(& Budowlanka, & WIMiIP,& WIMiR,& WIEiT);
}

void List::bud(List* budbud, List* wimip, List* wimir, List* wieit)
{
	int tab[30];
	node* a;
	int l=0;
	List temp;
	for (int i = 0; i < (*wimip).k; i++)
	{
		//cout << "tail" << "= " << temp.tail<< endl;
		//cout << "point" << "= " << (*temp.tail).point << endl;
		l++;
		//cout <<"i= " << i << endl;
		temp.add((*wimip).give_s(i),0);
	}
	for (int i = 0; i < (*wieit).k; i++)
	{
		//cout << "tail" << "= " << temp.tail << endl;
		//cout << "point" << "= " << (*temp.tail).point << endl;
		l++;
		temp.add((*wieit).give_s(i), 0);
	}
	a = temp.tail;
	//cout << "print1 =" << endl << endl;
	//temp.print();
	for (int i = 0; i < temp.k; i++)
	{
		tab[i]= (*a).val[0];
		//cout <<"tab =" << (*a).val[0] << endl;
		a = (*a).point;
	}
	//cout << "print2 =" << endl << endl;
	//temp.print();
	temp.sortd(tab, 0, 0, temp.k-1);
	for (int i = 0; i < (*wimir).k; i++)
	{
		(*budbud).add((*wimir).give_s(i), 0);
	}
	for (int i = 3; i >=0 ; i--)
	{
		if (l >= i)
		{
			(*budbud).add(temp.give_s(i), 0);
		}
	}
}

void List::total(List* wimip, List* wimir, List* wieit)
{
	node* a = tail;
	for (int i = 0; i < (*wimip).k; i++)
	{
		add_s((*wimip).give(i),0, 80);
	}
	for (int i = 0; i < (*wimir).k; i++)
	{
		add_s((*wimir).give(i), 0,82);
	}
	for (int i = 0; i < (*wieit).k; i++)
	{
		add_s((*wieit).give(i), 0,84);
	}
	a = tail;
	int* tab = new int[k];
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			(*a).total += (*a).val[j];
		}
		tab[i] = (*a).total;
		a = (*a).point;
	}
	sorts(tab, 0, 0, 29);
}
void List::add_s(tablica element, int poz, char c)
{
	//cout << 1 << endl;
	k++;
	if ((*head).is_empty && poz == 0)
	{
		for (int i = 0; i < 3; i++)
		{
			(*head).val[i] = element.tab[i];
			(*head).score[i] = element.score[i];
		}
		(*head).is_empty = 0;
		//cout << 2 << endl;
		(*head).wyd = c;
	}
	else if (poz == 0)
	{
		//cout << tail << "aaaaaaaaaaaaaaaaaaaaaaaaa" << (*tail).point << endl;
		//cout << tail << "/" << (*tail).point << endl;
		//cout << 3 << endl;
		node* a = tail;
		tail = new node(a, element);
		(*tail).wyd = c;
	}
	else if (poz > k - 1)
	{
		k--;
		cout << endl << endl << "!!! LISTA NIE JEST TAKA DUZA !!!" << endl << endl;
	}
	else
	{
		//cout << 4 << endl;
		node* a = tail;
		for (int i = 0; i < poz - 1; i++)
		{
			a = (*a).point;
		}
		node* b = new node;
		(*b).point = (*a).point;
		for (int i = 0; i < 3; i++)
		{
			(*b).val[i] = element.tab[i];
			(*b).score[i] = element.score[i];
		}
		(*b).wyd = c;
		(*a).point = b;
	}
}
void List::sorts(int* tab, int v, int l, int p)
{/*
	node* a;
	if (1)
	{
		a = tail;
		for (int j = 0; j < k; j++)
		{
			cout << (*a).val[v] << "/";
			a = (*a).point;
		}
		cout << endl << "a" << endl;
		for (int j = 0; j < k; j++)
		{
			cout << tab[j] << "/";
		}
		cout << endl << endl;
	}*/
	//sum++;
	if (p <= l) return;

	int i = l - 1;
	int j = p + 1;
	int pivot = tab[(l + p) / 2];
	while (1)
	{
		//szukam elementu wiekszego lub rownego piwot stojacego
		//po prawej stronie wartosci pivot
		while (pivot > tab[++i]);

		//szukam elementu mniejszego lub rownego pivot stojacego
		//po lewej stronie wartosci pivot
		while (pivot < tab[--j]);

		//jesli liczniki sie nie minely to zamieñ elementy ze soba
		//stojace po niewlasciwej stronie elementu pivot
		if (i <= j)
			//funkcja swap zamienia wartosciami tab[i] z tab[j]
			swap_s(tab, i, j);
		else
			break;
	}

	if (j > l)
		sorts(tab, v, l, j);
	if (i < p)
		sorts(tab, v, i, p);
}
void List::swap_s(int* tab, int a, int b)
{
	node* a_l = tail;
	for (int i = 0; i < a; i++)
	{
		a_l = (*a_l).point;
	}
	node* b_l = tail;
	for (int i = 0; i < b; i++)
	{
		b_l = (*b_l).point;
	}
	int temp = tab[a];
	int tval[3];
	int tsc[3];
	int sca = (*a_l).total;
	char wyd= (*a_l).wyd;
	for (int i = 0; i < 3; i++)
	{
		tval[i] = (*a_l).val[i];
		tsc[i] = (*a_l).score[i];
	}

	for (int i = 0; i < 3; i++)
	{
		(*a_l).val[i] = (*b_l).val[i];
		(*a_l).score[i] = (*b_l).score[i];
	}
	tab[a] = tab[b];
	(*a_l).total = (*b_l).total;
	(*a_l).wyd = (*b_l).wyd;

	for (int i = 0; i < 3; i++)
	{
		(*b_l).val[i] = tval[i];
		(*b_l).score[i] = tsc[i];
	}
	tab[b] = temp;
	(*b_l).total = sca;
	(*b_l).wyd = wyd;
}


void dzban::total()
{
	NMaster.total((&WIMiIP), ( & WIMiR), (& WIEiT));
}