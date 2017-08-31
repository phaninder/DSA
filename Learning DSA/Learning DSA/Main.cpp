#include <iostream>
#include <stdlib.h>
#include "MaxSubArray.h"
#include "LinkedList.h"
#include "DoublyLinkedList.h"
#include "Stack.h"
#include "Queue.h"
#include "Sort.h"
#include "BinaryTree.h"

using namespace std;

void LinkedListProblem();
void FindMaxSum();
void ClearScreen();
void DoublyLinkedListProblem();
void StackProblem();
void QueueProblem();
void SortingAlgorithms();
void TreeAlgorithm();

int main()
{
	/**********************
	*Max Sub array problem*
	**********************/
	//FindMaxSum();


	/**********************
	* Linked List         *
	**********************/

	//LinkedListProblem();

	/*******************
	*Double Linked List*
	********************/
	//DoublyLinkedListProblem();

	/*
		Stack
	*/
	//StackProblem();

	//Queue
	//QueueProblem();

	//Sorting Algorithms
	//SortingAlgorithms();

	//Binary search tree
	void TreeAlgorithm();

	system("PAUSE");
	return 0;
}

void ClearScreen()
{
	system("cls");
}

void TreeAlgorithm()
{
	int choice = -1;
	int quitOption = 3;
	BinarySearchTree tree;

	while (choice != quitOption)
	{
		cout << "Options:" << endl;
		cout << "1. Add values to tree" << endl;
		cout << "2. Display tree values" << endl;
		cout << "3. Quit" << endl;
		cin >> choice;
		switch (choice)
		{
			case 1:
			{
				int val;
				cout << "Enter data to add to tree" << endl;
				cin >> val;
				tree.AddNode(val);
				break;
			}
			case 2:
			{
				tree.Display();
				break;
			}
			case 3:
			{
				break;
			}
			default:
			{
				cout << "Enter proper choice" << endl;
				break;
			}
		}
		ClearScreen();
	}
}

void SortingAlgorithms()
{
	int choice = -1;
	int quitOption = 8;
	Sort sortingAlgo;

	while (choice != quitOption)
	{
		cout << "Options:" << endl;
		cout << "1. Enter values to array" << endl;
		cout << "2. Display Array values" << endl;
		cout << "3. Bubble sort" << endl;
		cout << "4. Insertion Sort" << endl;
		cout << "5. Selection Sort" << endl;
		cout << "6. Merge Sort" << endl;
		cout << "7. Quick Sort" << endl;
		cout << "8. Quit" << endl;
		cout << "Enter your choice:" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			ClearScreen();
			sortingAlgo.CreateArray();
			break;
		}

		case 2:
		{
			ClearScreen();
			sortingAlgo.Display();
			break;
		}
		case 3:
		{
			ClearScreen();
			sortingAlgo.BubbleSort();
			break;
		}
		case 4:
		{
			ClearScreen();
			sortingAlgo.InsertionSort();
			break;
		}
		case 5:
		{
			ClearScreen();
			sortingAlgo.SelectionSort();
			break;
		}
		case 6:
		{
			ClearScreen();
			sortingAlgo.MergeSort();
			break;
		}
		case 7:
		{
			ClearScreen();
			sortingAlgo.QuickSort();
			break;
		}
		case 8:
		{
			ClearScreen();
			break;
		}
		default:
		{
			cout << "Enter valid choice" << endl;
			break;
		}
		}
		cout << endl;
		cout << endl;
		cout << endl;
	}
}


void StackProblem()
{
	int choice = -1;
	int quitOption = 5;
	Stack *stack = new Stack();
	while (choice != quitOption)
	{

		cout << "Options:" << endl;
		cout << "1. Push value to Stack" << endl;
		cout << "2. Display Top value" << endl;
		cout << "3. Pop" << endl;
		cout << "4. Display all elements" << endl;
		cout << "5. Quit" << endl;
		cout << "Enter your choice:" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			ClearScreen();
			int val;
			cout << "Enter value: " << endl;
			cin >> val;
			stack->Push(val);
			break;
		}

		case 2:
		{
			ClearScreen();
			stack->Top();
			break;
		}
		case 3:
		{
			ClearScreen();
			stack->Pop();
			break;
		}
		case 4:
		{
			ClearScreen();
			stack->Display();
			break;
		}
		case 5:
		{
			break;
		}
		default:
		{
			cout << "Enter valid choice" << endl;
			break;
		}
		}
		cout << endl;
		cout << endl;
		cout << endl;
	}
}

void QueueProblem()
{
	int choice = -1;
	int quitOption = 5;
	Queue *queue = new Queue();
	while (choice != quitOption)
	{
		cout << "Options:" << endl;
		cout << "1. Enqueue" << endl;
		cout << "2. Display Top value" << endl;
		cout << "3. Deque" << endl;
		cout << "4. Display all elements" << endl;
		cout << "5. Quit" << endl;
		cout << "Enter your choice:" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			ClearScreen();
			int val;
			cout << "Enter value: " << endl;
			cin >> val;
			queue->EnQueue(val);
			break;
		}

		case 2:
		{
			ClearScreen();
			queue->Front();
			break;
		}
		case 3:
		{
			ClearScreen();
			queue->DeQueue();
			break;
		}
		case 4:
		{
			ClearScreen();
			queue->Display();
			break;
		}
		case 5:
		{
			break;
		}
		default:
		{
			cout << "Enter valid choice" << endl;
			break;
		}
		}
		cout << endl;
		cout << endl;
		cout << endl;
	}
}

/* Linked List Problem*/
void LinkedListProblem()
{
	int choice = -1;
	int quitChoice = 7;
	LinkedList *LinkedListObj = new LinkedList();
	while (choice != quitChoice)
	{
		cout << "Options:" << endl;
		cout << "1. Insert value to list" << endl;
		cout << "2. Display List values" << endl;
		cout << "3. Search" << endl;
		cout << "4. Delete" << endl;
		cout << "5. Reverse" << endl;
		cout << "6. Insert At" << endl;
		cout << "7. Quit" << endl;
		cout << "Enter your choice:" << endl;
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
			ClearScreen();
			cout << "Reversing List" << endl;
			LinkedListObj->Reverse();
			break;
		}
		case 6:
		{
			ClearScreen();
			int val, index;
			cout << "Enter index no: " << endl;
			cin >> index;
			cout << "Enter value: " << endl;
			cin >> val;
			LinkedListObj->InsertAt(index, val);
			break;
		}
		case 7:
		{
			break;
		}
		default:
		{
			cout << "Please enter a valid choice" << endl;
			break;
		}
		}

		cout << endl;
		cout << endl;
		cout << endl;
	}
}

/*Double linked List*/
void DoublyLinkedListProblem()
{
	int choice = -1;
	int quitChoice = 8;
	DoublyLinkedList *LinkedListObj = new DoublyLinkedList();

	while (choice != quitChoice)
	{
		cout << "Options:" << endl;
		cout << "1. Insert value to list" << endl;
		cout << "2. Display List values" << endl;
		cout << "3. Search" << endl;
		cout << "4. Delete" << endl;
		cout << "5. Reverse" << endl;
		cout << "6. Insert At" << endl;
		cout << "7. Display List values in reverse" << endl;
		cout << "8. Quit" << endl;
		cout << "Enter your choice:" << endl;
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
			ClearScreen();
			cout << "Reversing List" << endl;
			LinkedListObj->Reverse();
			break;
		}
		case 6:
		{
			ClearScreen();
			int val, index;
			cout << "Enter index no: " << endl;
			cin >> index;
			cout << "Enter value: " << endl;
			cin >> val;
			LinkedListObj->InsertAt(index, val);
			break;
		}
		case 7:
		{
			ClearScreen();
			LinkedListObj->DisplayInReverse();
			break;
		}
		case 8:
		{
			break;
		}
		default:
		{
			cout << "Please enter a valid choice" << endl;
			break;
		}
		}

		cout << endl;
		cout << endl;
		cout << endl;
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