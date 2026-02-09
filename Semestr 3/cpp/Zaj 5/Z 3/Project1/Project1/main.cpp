#include "header.h"

int main()
{
	cout << "a" << endl;
	Bin_tree a;
	a.add(3, 'c');
	//a.sort();
	a.add(2, 'c');
	//a.sort();
	a.add(4, 'c');
	//a.sort();
	a.add(1, 'c');
	//a.sort();
	a.add(5, 'c');
	//a.sort();
	//a.rm();
	//a.rm();
	//a.rm();
	a.pokaz_w();
	a.sort();
	a.sort();
	a.sort();
	a.sort();
	a.sort();
	cout << endl;
	a.pokaz_w();
	cout << a.rm().l;
	cout << endl;
	a.pokaz_w();
	Bin_tree b;
	b.add(6, 'c');
	b.add(0, 'c');
	b.add(7, 'c');
	b.add(8, 'c');
	b.add(9, 'c');
	cout << endl;
	b.pokaz_w();
	cout << endl << "////////////" << endl;
	a.merge(b);
	a.pokaz_w();
	//a.search_val(4);
	//a.search_range();
	//a.search_hight();
	return 0;
}