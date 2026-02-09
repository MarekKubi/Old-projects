#include "header.h"

int main()
{
	Bin_tree a;
	a.add("aa a");
	a.add("dd d");
	a.add("ab a");
	a.add("ff f");
	a.add("cc c");
	a.add("ee e");
	a.pokaz_w();
	//a.rm();
	//a.rm();
	//a.rm();
	a.search_val("ab a");
	return 0;
}

