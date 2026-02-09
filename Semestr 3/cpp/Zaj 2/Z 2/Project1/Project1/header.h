#pragma once

#include <iostream>
//#include <string>
//#include <fstream>

//#define _USE_MATH_DEFINES
//#include <math.h>
using namespace std;


class node
{
	char val;
	node* point;
	bool is_empty;
	friend class List;
	friend class Zjednoczenie;
public:
	node(node* poi, int v);
	node();
};
class List
{
	int k;
	node* head;
	node* tail;
	friend class Zjednoczenie;
public:
	List();
	~List();
	void add(int element, int poz);
	int remove(int poz);
	bool is_empty();
	int size();
	void print();
};

class Zjednoczenie
{
	List boh;
	List prz;
public:
	Zjednoczenie();
	void el_listaBohaterow();
	void el_listaPrzeciwnikow();
	void Walka();
};