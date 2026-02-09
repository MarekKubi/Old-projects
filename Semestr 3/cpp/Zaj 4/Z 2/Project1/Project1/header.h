#pragma once

#include <iostream>
//#include <string>
//#include <fstream>

//#define _USE_MATH_DEFINES
//#include <math.h>
using namespace std;
class node
{
	node* lt;
	node* rt;
	node* parent;
	string val;
	bool emp;
	friend class Bin_tree;
public:
	node();
	node(node* a, string k);
	void search_emp(bool* a, bool* b, int i, string k);
	bool az(string k, string nie_k);
	int search_val(bool* a, int i, string v);
	int search_val_b(bool* a, string v, int max);
	void search_range(int i, int* min, int* max);
	bool check(string k, string czy_k);
};
class Bin_tree
{
	int min;
	int max;
	bool tab[10];
	node* root;
	void pokaz(node* a);
	void search_emp(string k);
public:
	Bin_tree();
	void add(string k);
	void rm();
	void pokaz_w();
	void search_val(string val);
};