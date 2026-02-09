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
	int val;
	bool emp;
	friend class Bin_tree;
public:
	node();
	node(node* a, int k);
	void search_emp(bool* a, bool* b, int i, int* max);
	int search_val(bool* a, int i, int v);
	void search_range(int i, int* min, int* max);
};
class Bin_tree
{
	int min;
	int max;
	bool tab[10];
	node* root;
	void pokaz(node* a);
	void search_emp();
public:
	Bin_tree();
	void add(int k);
	void rm();
	void pokaz_w();
	void search_val(int val);
	void search_range();
	void search_hight();
};