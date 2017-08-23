#include <iostream>
#include <stdlib.h>
#include "MaxSubArray.h"
#include "LinkedList.h"

using namespace std;

void LinkedListProblem();
void FindMaxSum();
void ClearScreen();

int main()
{
	/**********************
	*Max Sub array problem*
	**********************/	
	//FindMaxSum();


	/**********************
	* Linked List         *
	**********************/
	LinkedListProblem();
	system("PAUSE");
	return 0;
}

void ClearScreen()
{
	system("cls");
}

void LinkedListProblem()
{
	int choice=-1;
	LinkedList *LinkedListObj = new LinkedList();
	while (choice != 5)
	{
		cout << "Enter your choice:" << endl;
		cout << "1. Insert value to list" << endl;
		cout << "2. Display List values" << endl;
		cout << "3. Search" << endl;
		cout << "4. Delete" << endl;
		cout << "5. Quit" << endl;
		cin >> choice;


		switch (choice)
		{
			case 1:
			{
				ClearScreen();
				int val;
				cout << "Enter value: " << endl;
				cin >> val;
				LinkedListObj->Insert(val);
				break;
			}

			case 2:
			{
				ClearScreen();
				LinkedListObj->Display();
				break;
			}
			case 3:
			{
				ClearScreen();
				int searchEle;
				cout << "Enter element to search:" << endl;
				cin >> searchEle;
				LinkedListObj->Search(searchEle);
				break;
			}
			case 4:
			{
				ClearScreen();
				int searchEle;
				cout << "Enter element to delete:" << endl;
				cin >> searchEle;
				LinkedListObj->Delete(searchEle);
				break;
			}
			case 5:
			{
				
				break;
			}
			default:
			{
				cout << "Please enter a valid choice" << endl;
				break;
			}
		}
	}
}

void FindMaxSum()
{
	int size, *dummyArr;
	cout << "No of elements:" << endl;
	cin >> size;
	cout << "Enter values for Array:" << endl;

	dummyArr = new int[size];
	for (int i = 0; i < size; i++)
	{
		cin >> dummyArr[i];
	}

	MaxSubArray maxSub(size, dummyArr);
	maxSub.FindMaxSum();
	// prints the array props
	maxSub.PrintArrayProp();
}