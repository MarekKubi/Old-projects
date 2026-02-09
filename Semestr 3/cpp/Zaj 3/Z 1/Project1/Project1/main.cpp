#include "header.h"


int main()
{
	srand((unsigned)time(0));
	dzban a;
	a.ev();
	a.split();
	a.print();
	a.bud();
	cout << endl << endl;
	a.print();
	a.total();
	cout << endl << endl;
	a.print();
	return 0;
}