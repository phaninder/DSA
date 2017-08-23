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
	cout << "List Elements:" << endl;
	while (temp != nullptr)
	{
		cout << "" << temp->value << endl;
		temp = temp->next;
	}
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
	}
}