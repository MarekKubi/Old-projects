#pragma once

#include <iostream>
//#include <string>
//#include <fstream>

//#define _USE_MATH_DEFINES
//#include <math.h>
using namespace std;


class tablica
{
public:
	int tab[3];
	int score[3];
	tablica();
	tablica(int t[3], int s[3]);
};
class node
{
	int val[3];
	int score[3];
	node* point;
	bool is_empty;
	int total;
	char wyd;
	friend class List;
	friend class Dzban;
public:
	node(node* poi, tablica v);
	node(node* poi, int v[3]);
	node();
};
class List
{
	int k;
	node* head;
	node* tail;
public:
	List();
	~List();
	void add(int element[3], int poz);
	void add(tablica element, int poz);
	void add_s(tablica element, int poz, char c);
	tablica remove(int poz);
	bool is_empty();
	int size();
	void print();
	void print_s();
	tablica give(int a);
    tablica give_s(int a);
	void ev();
	void sortd(int* tab, int v, int l, int p);
	void sortu(int* tab, int v, int l, int p);
	void sorts(int* tab, int v, int l, int p);
	void swap_m(int* tab,int a, int b);
	void swap_s(int* tab, int a, int b);
	void bud(List* budbud, List* wimip, List* wimir, List* wieit);
	void total(List* wimip, List* wimir, List* wieit);
};
class dzban
{
	List Master;
	List WIMiIP;
	List WIMiR;
	List WIEiT;
	List Budowlanka;
	List NMaster;
public:
	dzban();
	void split();
	void print();
	void ev();
	void bud();
	void total();
};