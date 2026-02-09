#include "header.h"


int main()
{
	Queue a;
	cout << "Q empty?:: " << a.is_empty() << endl;
	cout << "Q size?:: " << a.size() << endl;
	a.enqueue(1);
	a.enqueue(2);
	a.enqueue(3);

	cout << "Q empty?:: " << a.is_empty() << endl;
	cout << "Q size?:: " << a.size() << endl;
	cout << "Q 1:: " << a.dequeue() << endl;
	cout << "Q 2:: " << a.dequeue() << endl;
	cout << "Q 3:: " << a.dequeue() << endl;

	cout << endl << "/////////////////////////"<< endl << endl;

	Stack b;
	cout << "S empty?:: " << b.is_empty() << endl;
	cout << "S size?:: " << b.size() << endl;
	b.push(1);
	b.push(2);
	b.push(3);

	cout << "S empty?:: " << b.is_empty() << endl;
	cout << "S size?:: " << b.size() << endl;
	cout << "S 1:: " << b.pop() << endl;
	cout << "S 2:: " << b.pop() << endl;
	cout << "S 3:: " << b.pop() << endl;
	return 0;
}