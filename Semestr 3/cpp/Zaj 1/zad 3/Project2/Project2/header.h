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
	friend class Queue;
	friend class Stack;
public:
	node(node* poi, int v);
	node();
};
class Queue
{
	int k;
	node* ob_k;
	node* ob_p;
public:
	Queue();
	~Queue();
	void enqueue(int element);
	int dequeue();
	bool is_empty();
	int size();
};
class Stack
{
	int k;
	node* ob_k;
	node* ob_p;
public:
	Stack();
	~Stack();
	void push(int element);
	int pop();
	bool is_empty();
	int size();
};
