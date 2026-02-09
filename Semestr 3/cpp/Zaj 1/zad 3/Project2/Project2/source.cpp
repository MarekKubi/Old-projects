#include "header.h"



node::node(node* poi, int v)
{
	point = poi;
	val = v;
	is_empty = 0;
}
node::node()
{
	point = 0;
	val = 0;
	is_empty = 1;
}


Queue::Queue()
{
	node* a = new node;
	ob_k = a;
	ob_p = a;
	k = 0;
}

void Queue::enqueue(int element)
{
	k++;
	if ((*ob_k).is_empty)
	{
		(*ob_k).val = element;
		(*ob_k).is_empty = 0;
	}
	else
	{
		node* a = ob_k;
		ob_k = new node(a, element);
		(*a).point = ob_k;
	}
}
int Queue::dequeue()
{
	if ((*ob_p).is_empty)
	{
		cout<<endl<<endl << "!!! KOLEJKA JEST PUSTA!!!" << endl<<endl;
		return 0;
	}
	else if (ob_p==ob_k)
	{
		(*ob_p).is_empty = 1;
		k--;
		return (*ob_p).val;
	}
	else
	{
		int w = (*ob_p).val;
		node* d = ob_p;
		ob_p = (*ob_p).point;
		delete d;
		k--;
		return w;
	}
}
bool Queue::is_empty()
{
	return (*ob_p).is_empty;
}
int Queue::size()
{
	return k;
}

Queue::~Queue()
{
	node* d;
	while (!(ob_k = ob_p))
	{
		d = ob_p;
		ob_p = (*ob_p).point;
		delete d;
	}
	delete ob_p;
}

/////////////////////////////////////////////////

Stack::Stack()
{
	node* a = new node;
	ob_k = a;
	ob_p = a;
	k = 0;
}

void Stack::push(int element)
{
	k++;
	if ((*ob_k).is_empty)
	{
		(*ob_k).val = element;
		(*ob_k).is_empty = 0;
	}
	else
	{
		node* a = ob_k;
		ob_k = new node(ob_k, element);
	}
}
int Stack::pop()
{
	if ((*ob_k).is_empty)
	{
		cout << endl << endl << "!!! KOLEJKA JEST PUSTA!!!" << endl << endl;
		return 0;
	}
	else if (ob_p == ob_k)
	{
		(*ob_k).is_empty = 1;
		k--;
		return (*ob_k).val;
	}
	else
	{
		int w = (*ob_k).val;
		node* d = ob_k;
		ob_k = (*ob_k).point;
		delete d;
		k--;
		return w;
	}
}
bool Stack::is_empty()
{
	return (*ob_p).is_empty;
}
int Stack::size()
{
	return k;
}

Stack::~Stack()
{
	node* d;
	while (!(ob_k = ob_p))
	{
		d = ob_k;
		ob_k = (*ob_k).point;
		delete d;
	}
	delete ob_k;
}
