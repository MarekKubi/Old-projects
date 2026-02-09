#include "header.h"

Queue::Queue()
{
	k = -1;
}

void Queue::enqueue(int element)
{
	if (k >= 9)
	{
		cout << "Kolejka jest pelna!!!" << endl;
	}
	else
	{
		for (int i = 0; i <= k; i++)
		{
			Q[k + 1 - i] = Q[k - i];
		}
		Q[0] = element;
		k++;
	}
}
int Queue::dequeue()
{
	if (k <= -1)
	{
		cout << "Kolejka jest pusta!!!" << endl;
	}
	else
	{
		k = k - 1;
		return Q[k + 1];
	}
}
bool Queue::is_empty()
{//return k+1;
	if (k >= 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int Queue::size()
{
	return k + 1;
}

/////////////////////////////////////////////////

Stack::Stack()
{
	k = 0;
}

void Stack::push(int element)
{
	if (k >= 9)
	{
		cout << "Stos jest pelny!!!" << endl;
	}
	else
	{
		k = k + 1;
		S[k] = element;
	}
}
int Stack::pop()
{
	if (k <= -1)
	{
		cout << "Stos jest pusty!!!" << endl;
	}
	else
	{
		k = k - 1;
		return S[k + 1];
	}
}
bool Stack::is_empty()
{//return k+1;
	if (k >= 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int Stack::size()
{
	return k + 1;
}
