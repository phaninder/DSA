#include "Stack.h"
#include "LinkedList.h"
#include <iostream>

using namespace std;

Stack::Stack()
{
	stackObj = new LinkedList();
}

void Stack::Push(int val)
{
	// Always insert at the beginning of the list
	stackObj->InsertAt(0, val);
}

void Stack::Pop()
{
	stackObj->DeleteAt(0);
}

bool Stack::IsEmpty()
{
	return true;
}

void Stack::Top()
{
	stackObj->DisplayElementAt(0);
}

void Stack::Display()
{
	stackObj->Display();
}