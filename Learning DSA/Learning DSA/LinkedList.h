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
	int noOfElements;
	node *list;
	node * SearchAndReturn(int e);
public:
	LinkedList();
	void Insert(int e);
	void InsertAt(int index, int e);
	void Display();
	void DisplayElementAt(int index);
	void Search(int e);
	void Delete(int e);
	void DeleteAt(int index);
	void Reverse();
};