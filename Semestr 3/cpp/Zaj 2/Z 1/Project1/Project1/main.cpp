#include "header.h"


int main()
{
	//srand((unsigned)time(0));
	List_tab a;
	a.add(3, 0);
	a.add(1, 0);
	a.add(2, 1);
	cout << a.remove(0) << endl;
	cout << a.remove(0) << endl;
	cout << a.remove(0) << endl;
	cout << a.remove(0) << endl;
}