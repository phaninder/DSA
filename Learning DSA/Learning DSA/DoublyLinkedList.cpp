#include "DoublyLinkedList.h"
#include <iostream>

using namespace std;

DoublyLinkedList::DoublyLinkedList()
{
	list = new node();
	list->next = nullptr;
	list->prev = nullptr;
}

// To insert element
void DoublyLinkedList::Insert(int e)
{
	if (list->next == nullptr)
	{
		node *tempList = new node();
		tempList->value = e;
		tempList->next = nullptr;
		tempList->prev = list;
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
	dummyNode->next = tempPtr->next;
	dummyNode->prev = tempPtr;
	tempPtr->next = dummyNode;
	noOfElements++;

}

void DoublyLinkedList::InsertAt(int index, int e)
{
	if (index < 0 || index >= noOfElements)
	{
		cout << "Index out of range, can't insert" << endl;
		return;
	}

	// if at the beginning
	if (index == 0)
	{
		node *temp = new node();
		temp->value = e;
		temp->next = list->next;
		list->next->prev = temp;
		temp->prev = list;
		list->next = temp;
		
		noOfElements++;
	}
	else
	{
		node *temp, *dummyNode = new node();
		temp = list->next;//start of node

		for (int i = 1; i < index; i++)
		{
			temp = temp->next;
		}
		dummyNode->value = e;
		dummyNode->next = temp->next;
		dummyNode->prev = temp;
		(temp->next)->prev = dummyNode;// change for the next one after insertion
		temp->next = dummyNode;
		noOfElements++;
	}
}

void DoublyLinkedList::Display()
{
	if (list->next == nullptr)
	{
		cout << "List is empty" << endl;
		return;
	}
	node *temp;
	temp = list->next;
	cout << "No of elements: " << noOfElements << "\nList Elements:" << endl;
	while (temp != nullptr)
	{
		cout << "" << temp->value << endl;
		temp = temp->next;
	}
}

void DoublyLinkedList::DisplayInReverse()
{
	if (list->next == nullptr)
	{
		cout << "List is empty" << endl;
		return;
	}
	node *temp;
	temp = list->next;
	cout << "No of elements: " << noOfElements << "\nList Elements in reverse order:" << endl;
	while (temp->next != nullptr)
	{
		temp = temp->next;
	}

	while (temp != nullptr)
	{
		cout << "" << temp->value << endl;
		temp = temp->prev;
	}
}

void DoublyLinkedList::Search(int e)
{
	if (list->next == nullptr)
	{
		cout << "List is Empty" << endl;
		return;
	}
	node *prevNode, *temp;
	prevNode = list->next;
	temp = list->next;

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

DoublyLinkedList::node* DoublyLinkedList::SearchAndReturn(int e)
{
	if (list->next == nullptr)
	{
		cout << "List is Empty" << endl;
		return nullptr;
	}
	node *prevNode, *temp;
	prevNode = list;
	temp = list->next;
	while (temp != nullptr)
	{
		if (temp->value == e)
		{
			cout << "Element found in the list" << endl;
			return temp;
		}
		temp = temp->next;
	}
	
	return nullptr;
}

void DoublyLinkedList::Delete(int e)
{
	node *eleNode;
	eleNode = SearchAndReturn(e);
	if (eleNode != nullptr)
	{
		node *left, *right;
		left = eleNode->prev;
		right = eleNode->next;
		if(left!=nullptr)
			left->next = right;
		if(right!=nullptr)
			right->prev = left;
		delete(eleNode);
/*
		//We are having only one node
		if (eleNode->next == nullptr && eleNode->prev == nullptr)
		{
			delete(list->next);
			list->next = nullptr;
		}
		else if (eleNode->next!=nullptr && eleNode->prev ==nullptr)
		{
			list->next = eleNode->next;
			(eleNode->next)->prev = nullptr;
			delete(eleNode);
		}
		else
		{
			node *delNode;
			delNode = eleNode->next;
			if (delNode->next != nullptr)
			{
				eleNode->next = delNode->next;
				(delNode->next)->prev = eleNode;
			}
			else
			{
				eleNode->next = nullptr;
			}
			delete(delNode);
		}
		*/
		noOfElements--;
	}
	else
		cout << "Element not found in List" << endl;
}

void DoublyLinkedList::Reverse()
{
	if (list->next == nullptr)
	{
		cout << "List is empty" << endl;
	}
	node *currentNode, *prevNode, *nextNode;
	currentNode = list->next;
	prevNode = nullptr;
	nextNode = nullptr;
	while (currentNode != nullptr)
	{
		nextNode = currentNode->next;
		currentNode->next = prevNode;
		currentNode->prev = nextNode;

		prevNode = currentNode;
		currentNode = nextNode;
	}
	list->next = prevNode;
	
}