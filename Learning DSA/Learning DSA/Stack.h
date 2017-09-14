#pragma once

#include "LinkedList.h"

class Stack
{
private:
	LinkedList *stackObj;
public:
	Stack();
	void Push(int val);
	void Pop();
	void Top();
	bool IsEmpty();
	void Display();
	int GetTop();
};