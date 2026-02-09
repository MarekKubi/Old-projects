#pragma once

#include <iostream>
//#include <string>
//#include <fstream>

//#define _USE_MATH_DEFINES
//#include <math.h>

using namespace std;

/*
class kolejka
{
	int roz;
	friend node;
public:

};
class lista
{
	int roz;
	friend node;
public:

};
class node
{
	int val;
	node* next;
	friend kolejka;
	friend lista;
public:
	void push(int a);
	int pop();
};
*/
class Queue
{
	int k;
	int Q[10];
public:
	Queue();
	void enqueue(int element);
	int dequeue();
	bool is_empty();
	int size();
};
class Stack
{
	int k;
	int S[10];
public:
	Stack();
	void push(int element);
	int pop();
	bool is_empty();
	int size();
};
