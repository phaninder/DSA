#include "Queue.h"
#include<iostream>

using namespace std;

Queue::Queue()
{
	queueObj = new LinkedList();
	noOfElements = 0;
}

void Queue::EnQueue(int ele)
{
	queueObj->InsertAt(noOfElements,ele);
	noOfElements++;
}

void Queue::Display()
{
	if (!IsEmpty())
	{
		queueObj->Display();
	}
	else
	{
		cout << "Queue is empty" << endl;
	}

}

void Queue::DeQueue()
{
	if (!IsEmpty())
	{
		queueObj->DeleteAt(0);//Delete the first element in the queue
		noOfElements--;
	}
	else
	{
		cout << "Queue is empty" << endl;
	}
}

void Queue::Front()
{
	if (!IsEmpty())
	{
		queueObj->DisplayElementAt(0);
	}
	else
	{
		cout << "Queue is empty" << endl;
	}
}

bool Queue::IsEmpty()
{
	if (noOfElements <= 0)
		return true;
	return false;
}