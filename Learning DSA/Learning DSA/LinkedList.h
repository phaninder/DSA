#pragma once

#include <iostream>

class LinkedList
{
private:
	struct node
	{
		int value;
		node *next;
	};

	node *list;
	node * SearchAndReturn(int e);
public:
	LinkedList();
	void Insert(int e);
	void Display();
	void Search(int e);
	void Delete(int e);
	void Reverse();
};