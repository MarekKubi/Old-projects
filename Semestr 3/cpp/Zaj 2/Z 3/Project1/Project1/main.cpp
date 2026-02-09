#include "header.h"


int main()
{
	srand((unsigned)time(0));
	List a;
	for (int i = 0; i < 10; i++)
	{
		a.add((rand()%5)+1, 0);
	}
	a.print();
	cout << "Liczba z zadania: " << fun_fun(a) << endl;
	return 0;
}