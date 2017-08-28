#pragma once


class DoublyLinkedList
{
private:
	
	struct node
	{
		int value;
		node *next;
		node *prev;
	};

	struct Head
	{
		node *next;
	};

	int noOfElements;
	node *list;
	node* SearchAndReturn(int e);
public:
	DoublyLinkedList();
	void Insert(int e);
	void InsertAt(int index, int e);
	void Display();
	void DisplayInReverse();
	void Search(int e);
	void Delete(int e);
	void DeleteAt(int index);
	void Reverse();
};