#pragma once

#include <iostream>
//#include <string>
//#include <fstream>

//#define _USE_MATH_DEFINES
//#include <math.h>
using namespace std;
class info
{
public:
	char c;
	int l;
	info(int k,char c);
};
class node
{
	node* lt;
	node* rt;
	node* parent;
	int val;
	char kategoria;
	bool emp;
	friend class Bin_tree;
public:
	node();
	node(node* a, info k);
	void search_emp(bool* a, bool* b, int i, int* max);
	int search_val(bool* a, int i, int v);
	void search_range(int i, int* min, int* max);
	bool sort(node* point);
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
	void add(int k, char c);
	info rm();
	void pokaz_w();
	void search_val(int val);
	void search_range();
	void search_hight();
	void sort();
	void merge(Bin_tree brr);
	bool is_emp();
	void split(Bin_tree a, Bin_tree b, Bin_tree c, Bin_tree d);
};