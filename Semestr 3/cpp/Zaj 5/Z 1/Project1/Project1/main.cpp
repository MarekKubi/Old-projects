#include "header.h"

int main()
{
	Bin_tree a;
	a.add(9);
	a.sort();
	a.add(3);
	a.sort();
	a.add(4);
	a.sort();
	a.add(0);
	a.sort();
	a.add(5);
	a.sort();
	a.add(2);
	a.sort();
	a.add(7);
	a.sort();
	a.add(8);
	a.sort();
	//a.rm();
	//a.rm();
	//a.rm();
	a.pokaz_w();
	cout << endl;
	a.pokaz_w();
	cout << a.rm();
	cout << a.rm();
	cout << a.rm();
	cout << a.rm();
	cout << a.rm();
	cout << endl;
	a.pokaz_w();
	//a.search_val(4);
	//a.search_range();
	//a.search_hight();
	return 0;
}