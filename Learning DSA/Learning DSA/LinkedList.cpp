#include "LinkedList.h"
#include <iostream>

using namespace std;

LinkedList::LinkedList()
{
	list = new node();
	list->value = INT32_MIN;
	list->next = nullptr;
}

// To insert element
void LinkedList::Insert(int e)
{
	if (list->next == nullptr)
	{
		node *tempList = new node();
		tempList->value = e;
		tempList->next = nullptr;
		list->next = tempList;
		noOfElements++;
		return;
	}

	node *tempPtr, *dummyNode;
	//tempPtr = new node();
	tempPtr = list->next;

	while (tempPtr->next != nullptr)
	{
		tempPtr = tempPtr->next;
	}
	// Create space for temp node
	dummyNode = new node();
	dummyNode->value = e;
	dummyNode->next = nullptr;

	tempPtr->next = dummyNode;
	noOfElements++;

}

void LinkedList::InsertAt(int index, int e)
{
	if (index < 0)
	{
		cout << "Cannot insert at negative index";
		return;
	}

	// if at the beginning
	if (index == 0)
	{
		node *temp = new node();
		temp->value = e;
		temp->next = list->next;
		list->next = temp;
		noOfElements++;
	}
	else
	{
		if (index > noOfElements)
		{
			cout << "Index out of range, can't insert" << endl;
			return;
		}

		node *temp,*dummyNode = new node();
		temp = list;//start of node

		for (int i = 0; i < index; i++)
		{
			temp = temp->next;
		}
		dummyNode->value = e;
		dummyNode->next = temp->next;
		temp->next = dummyNode;
		noOfElements++;
	}
}

void LinkedList::Display()
{
	if (list->next == nullptr)
	{
		cout << "List is empty" << endl;
		return;
	}
	node *temp;
	temp = list->next;
	cout << "No of elements: "<<noOfElements<<"\nList Elements:" << endl;
	while (temp != nullptr)
	{
		cout << "" << temp->value << endl;
		temp = temp->next;
	}
}

void LinkedList::DisplayElementAt(int index)
{
	if (index > noOfElements)
	{
		cout << "Out of range" << endl;
		return;
	}

	if (noOfElements <= 0)
	{
		cout << "List is empty" << endl;
		return;
	}
	node *temp = list;
	for (int i = 0; i <= index; i++)
	{
		temp = temp->next;
	}
	cout << "Value is: " << temp->value << endl;
}

int LinkedList::GetElementAt(int index)
{
	if (index > noOfElements)
	{
		cout << "Out of range" << endl;
		return -1;
	}

	if (noOfElements <= 0)
	{
		cout << "List is empty" << endl;
		return -1;
	}
	node *temp = list;
	for (int i = 0; i <= index; i++)
	{
		temp = temp->next;
	}
	return (temp->value);
}

void LinkedList::Search(int e)
{
	if (list->next == nullptr)
	{
		cout << "List is Empty" << endl;
		return;
	}
	node *prevNode, *temp;
	prevNode = list;
	temp = list;
	while (temp != nullptr)
	{
		if ((temp)->value == e)
		{
			cout << "Element found in the list" << endl;
			break;
		}
		prevNode = temp;
		temp = prevNode->next;
	}

	if (temp == nullptr)
		cout << "Element not found in list" << endl;
}

LinkedList::node* LinkedList::SearchAndReturn(int e)
{
	if (list->next == nullptr)
	{
		cout << "List is Empty" << endl;
		return nullptr;
	}
	node *prevNode,*temp;
	prevNode = list;
	temp = list;
	while (temp != nullptr)
	{
		if ((temp)->value == e)
		{
			cout << "Element found in the list" << endl;
			break;
		}
		prevNode = temp;
		temp = prevNode->next;
	}
	if (temp != nullptr)
		return prevNode;
	else
		return nullptr;
}

void LinkedList::Delete(int e)
{
	node *eleNode;
	eleNode = SearchAndReturn(e);
	if (eleNode != nullptr)
	{
		//We are having only one node
		if (eleNode->next == nullptr)
		{
			delete(list->next);
			list->next = nullptr;
		}
		else
		{
			node *delNode;
			delNode = eleNode->next;
			eleNode->next = delNode->next;
			delNode->next = nullptr;
			delete(delNode);
		}
		noOfElements--;
	}
	else
		cout << "Element not found in List" << endl;
}
int LinkedList::GetSize()
{
	return noOfElements;
}

void LinkedList::DeleteAt(int index)
{
	if (index > noOfElements)
	{
		cout << "Index is out of range" << endl;
		return;
	}
	
	node *temp;
	temp = list;

	for (int i = 0; i < index; i++)
	{
		temp = temp->next;
	}

	if (temp != nullptr)
	{
		//We are having only one node
		if (temp->next != nullptr)
		{		
			node *delNode;
			delNode = temp->next;
			temp->next = delNode->next;
			delNode->next = nullptr;
			delete(delNode);
			noOfElements--;
		}
	}
	else
		cout << "List is empty" << endl;
}

void LinkedList::Reverse()
{
	if (list->next == nullptr)
	{
		cout << "List is empty" << endl;
	}
	node *current, *prev, *next;
	current = list->next;
	prev = nullptr;
	next = nullptr;
	while (current != nullptr)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	list->next = prev;
}