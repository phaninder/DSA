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
	if(stackObj->GetSize()<=0)
		return true;
	return false;
}

void Stack::Top()
{
	stackObj->DisplayElementAt(0);
}

int Stack::GetTop()
{
	return (stackObj->GetElementAt(0));
}

void Stack::Display()
{
	stackObj->Display();
}