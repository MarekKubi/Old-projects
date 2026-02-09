#pragma once

#include <iostream>
//#include <string>
//#include <fstream>

//#define _USE_MATH_DEFINES
//#include <math.h>
using namespace std;


class node
{
	int val;
	node* point;
	bool is_empty;
	friend class List;
	friend int fun_fun(List l);
public:
	node(node* poi, int v);
	node();
};
class List
{
	int k;
	node* head;
	node* tail;
	friend int fun_fun(List l);
public:
	List();
	~List();
	void add(int element, int poz);
	int remove(int poz);
	bool is_empty();
	int size();
	void print();
	int give(int a);
};
int fun_fun(List);