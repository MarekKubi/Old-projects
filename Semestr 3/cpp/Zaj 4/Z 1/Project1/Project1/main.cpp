#include "header.h"

int main()
{
	Bin_tree a;
	a.add(1);
	a.add(2);
	a.add(3);
	a.add(4);
	a.add(5);
	a.pokaz_w();
	cout << endl;
	a.rm();
	a.rm();
	//a.rm();
	a.pokaz_w();
	a.search_val(4);
	a.search_range();
	a.search_hight();
	return 0;
}