#pragma once
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include<cmath>
#include <chrono>  
#include <windows.h>  
#include <thread>
#include <iostream>
//#include <string>
//#include <fstream>

//#define _USE_MATH_DEFINES
//#include <math.h>
using namespace std;
class queue
{
	int n;
	queue* point;
public:
	queue();
	queue(int a);
	queue* add_q(int a);
	int de_q();
	queue* next();
};
class stos
{
	int n;
	stos* point;
public:
	stos();
	stos(int a, stos* p);
	stos* add_s(int a);
	int de_s();
	stos* next();
};
class point
{
public:
	int n;
	point* p;
	point(int a, point* po);
};
class node
{
public:
	point* po;
	void add(int a);
	node();
	~node();
};
class Graf
{
	bool A;
	int size;
	node** tab;
	bool* czy;
	queue* q_p;
	queue* q_k;
	stos* s;
	int ilosc;
public:
	Graf();
	~Graf();
	void pokaz();
	void szukanie(int s, int k);
	bool Q_G(int s, int k);
	bool Q_S(int s, int k);
	bool S_G(int s, int k);
 	bool S_S(int s, int k);
	int de_q();
	void add_q(int a);
	int de_s();
	void add_s(int a);
};

