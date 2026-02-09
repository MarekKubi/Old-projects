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
	~node();
};
class Graf
{
	int size;
	node** tab;
	bool* czy;
public:
	Graf();
	~Graf();
	void pokaz();
};

