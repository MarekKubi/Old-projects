#include "header.h"

int main()
{
	cout << "a" << endl;
	Bin_tree a;
	a.add(3, 'c');
	//a.sort();
	a.add(2, 'b');
	//a.sort();
	a.add(8, 'd');
	//a.sort();
	a.add(1, 'a');
	//a.sort();
	a.add(5, 'a');
	a.add(6, 'b');
	a.add(7, 'c');
	a.add(4, 'd');
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
	a.sort();
	a.sort();
	a.sort();
	cout << endl;
	a.pokaz_w();
	cout << endl;
	cout << a.rm().l;
	cout << endl;
	a.pokaz_w();
	Bin_tree b;
	b.add(9, 'a');
	b.add(0, 'd');
	b.add(10, 'b');
	b.add(11, 'c');
	b.add(12, 'd');
	cout << endl;
	b.pokaz_w();
	cout << endl << "////////////" << endl;
	a.merge(b);
	a.pokaz_w();
	cout << endl << "////////////" << endl;
	//a.search_val(4);
	//a.search_range();
	//a.search_hight();

	Bin_tree a_a;
	Bin_tree a_b;
	Bin_tree a_c;
	Bin_tree a_d;
	a.split(a_a, a_b, a_c, a_d);
	a_a.pokaz_w();
	cout << endl;
	a_b.pokaz_w();
	cout << endl;
	a_c.pokaz_w();
	cout << endl;
	a_d.pokaz_w();
	cout << endl;


	return 0;
}