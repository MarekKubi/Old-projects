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
public:
	node(node* poi, int v);
	node();
};
class List
{
public:
	int k;
	node* head;
	node* tail;
	List();
	~List();
	void add(int element, int poz);
	int remove(int poz);
	bool is_empty();
	int size();
};

class List_tab
{
	int k;
	int roz;
	int* tablica;
public:
	List_tab();
	~List_tab();
	void add(int element, int poz);
	int remove(int poz);
	bool is_empty();
	int size();
};