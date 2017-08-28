#pragma once
#include "LinkedList.h"

class Queue
{
private:
	LinkedList *queueObj;
	int noOfElements;
public:
	Queue();
	void EnQueue(int ele);
	void DeQueue();
	void Front();
	void Display();
	bool IsEmpty();
};