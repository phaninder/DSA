#include <iostream>
#include <stdlib.h>
#include "MaxSubArray.h"
#include "LinkedList.h"
#include "DoublyLinkedList.h"
#include "Stack.h"
#include "Queue.h"
#include "Sort.h"
#include "BinaryTree.h"
#include "Search.h"
#include "Graph.h"
#include "Heap.h"
#include "Kruskal.h"
#include "DisjointSet.h"
#include "Prism.h"
#include "StronglyConnected.h"
#include "ArticulationPoint.h"

using namespace std;

void LinkedListProblem();
void FindMaxSum();
void ClearScreen();
void DoublyLinkedListProblem();
void StackProblem();
void QueueProblem();
void SortingAlgorithms();
void TreeAlgorithm();
void SearchAlgorithms();
void GraphAlgorithms();
void HeapAlgorightms();
void KruskalAlgorithm();
void MakeDisjointSet();
void PerformPrismAlgo();
void StronglyConnectedAlgo();
void ArticulationPointsAlgo();
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

	//Searching
	//SearchAlgorithms();

	//Binary search tree
	//TreeAlgorithm();

	// Tree Algorithms
	//GraphAlgorithms();

	//Heap Algorithm
	//HeapAlgorightms();
	 
	//Kruskal Algorithm
	//KruskalAlgorithm();

	//Disjoin set
	//MakeDisjointSet();

	//Prism Algo
	//PerformPrismAlgo();

	//Kosaraju Algo
	//StronglyConnectedAlgo();

	//Articulation algo
	ArticulationPointsAlgo();

	//system("PAUSE");
	return 0;
}

void ClearScreen()
{
	//	system("cls");
}

void MakeDisjointSet()
{
	int choice = -1;
	int quitOption = 100;

	DisjointSet set;

	while (choice != quitOption)
	{
		cout << "Options:" << endl;
		cout << "1. Create a Disjoint set" << endl;
		cout << "2. MakeSet" << endl;
		cout << "3. Union Set" << endl;
		cout << "4. Print Set" << endl;
		cout << "5. Has Cycle" << endl;
		cout << "100. Quit" << endl;
		cout << "Enter your choice:" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			ClearScreen();
			int noOfVertices;
			cout << "Enter no of vertices to be inserted" << endl;
			cin >> noOfVertices;
			set.CreateSet(noOfVertices);
			break;
		}
		case 2:
		{
			ClearScreen();
			int noOfVertices;
			cout << "Enter no of vertices to be inserted" << endl;
			cin >> noOfVertices;
			for (int i = 0; i < noOfVertices; i++)
			{
				int val;
				cout << "Enter val to be inserted" << endl;
				cin >> val;
				set.MakeSet(val);
			}
			break;
		}
		case 3:
		{
			ClearScreen();
			int x, y;
			cout << "Enter values to union" << endl;
			cin >> x >> y;
			set.Union(x, y);
			break;
		}
		case 4:
		{
			ClearScreen();
			set.PrintSet();
			break;
		}
		case 5:
		{
			ClearScreen();
			int x, y;
			cout << "Enter values to search for cycle" << endl;
			cin >> x >> y;
			cout << ((set.HasCycle(x, y) == 1) ? "Has a Cycle" : "No Cycle is present") << endl;
			break;
		}

		default:
		{
			break;
		}
		}
		cout << endl;
		cout << endl;
		cout << endl;
	}


}
void KruskalAlgorithm()
{
	int choice = -1;
	int quitOption = 100;

	DisjointSet set;
	Kruskal krus;

	while (choice != quitOption)
	{
		cout << "Options:" << endl;
		cout << "1. Initialise Kruskal Algo" << endl;
		cout << "2. Add edges and weights to Kruskal" << endl;
		cout << "3. Form Min Span tree" << endl;
		cout << "4. Print Tree" << endl;
		cout << "100. Quit" << endl;
		cout << "Enter your choice:" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			ClearScreen();
			int x;
			cout << "Enter no of edges" << endl;
			cin >> x;
			krus.InitialiseVal(x);
			break;
		}
		case 2:
		{
			ClearScreen();
			int noOfVertices;
			cout << "Enter no of edges" << endl;
			cin >> noOfVertices;
			cout << "Enter edge and weights" << endl;
			int weights;
			int x, y;
			for (int i = 0; i < noOfVertices; i++)
			{
				cin >> x >> y;
				cin >> weights;
				krus.SetValToArray(x, y, weights);
			}
			break;
		}
		case 3:
		{
			ClearScreen();
			krus.FormMinimumSpanTree();
			break;
		}
		case 4:
		{
			ClearScreen();
			krus.PrintMinSpanTree();
			break;
		}
		default:
		{
			break;
		}
		}
		cout << endl;
		cout << endl;
		cout << endl;
	}
}

void PerformPrismAlgo()
{
	int choice = -1;
	int quitOption = 100;

	Prism prism;

	while (choice != quitOption)
	{
		cout << "Options:" << endl;
		cout << "1. Initialise Prism Algo" << endl;
		cout << "2. Create Graph" << endl;
		cout << "3. Form Min Span tree" << endl;
		cout << "4. Print Tree" << endl;
		cout << "100. Quit" << endl;
		cout << "Enter your choice:" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			ClearScreen();
			int e,v;
			cout << "Enter no of edges" << endl;
			cin >> e;
			cout << "Enter no of vertices" << endl;
			cin >> v;
			prism.InitialiseGraph(v,e);
			break;
		}
		case 2:
		{
			ClearScreen();
			prism.CreateGraph();
			break;
		}
		case 3:
		{
			ClearScreen();
			prism.ApplyPrismAlgo();
			break;
		}
		case 4:
		{
			ClearScreen();
			prism.PrintMinSpanTree();
			break;
		}
		default:
		{
			break;
		}
		}
		cout << endl;
		cout << endl;
		cout << endl;
	}
}

void ArticulationPointsAlgo()
{
	int choice = -1;
	int quitOption = 100;

	ArticulationPoint arti;

	while (choice != quitOption)
	{
		cout << "Options:" << endl;
		cout << "1. Initialise Algo" << endl;
		cout << "2. Create Graph" << endl;
		cout << "3. Find Articulation points" << endl;
		//cout << "4. Show Strongly connected components" << endl;
		cout << "100. Quit" << endl;
		cout << "Enter your choice:" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			ClearScreen();
			int e, v;
			cout << "Enter no of edges" << endl;
			cin >> e;
			cout << "Enter no of vertices" << endl;
			cin >> v;
			arti.InitializeGraph(v, e);
			break;
		}
		case 2:
		{
			ClearScreen();
			arti.CreateGraph();
			break;
		}
		case 3:
		{
			ClearScreen();
			arti.DepthFirstSearch();
			break;
		}
		/*case 4:
		{
			ClearScreen();
			Ksr.ReverseGraph();
			break;
		}*/
		default:
		{
			break;
		}
		}
		cout << endl;
		cout << endl;
		cout << endl;
	}
}

void StronglyConnectedAlgo()
{
	int choice = -1;
	int quitOption = 100;

	KosarajuAlgo Ksr;

	while (choice != quitOption)
	{
		cout << "Options:" << endl;
		cout << "1. Initialise Kosaraju Algo" << endl;
		cout << "2. Create Graph" << endl;
		cout << "3. Perform DFS" << endl;
		cout << "4. Show Strongly connected components" << endl;
		cout << "100. Quit" << endl;
		cout << "Enter your choice:" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			ClearScreen();
			int e, v;
			cout << "Enter no of edges" << endl;
			cin >> e;
			cout << "Enter no of vertices" << endl;
			cin >> v;
			Ksr.InitializeGraph(v, e);
			break;
		}
		case 2:
		{
			ClearScreen();
			Ksr.CreateGraph();
			break;
		}
		case 3:
		{
			ClearScreen();
			Ksr.DepthFirstSearch();
			break;
		}
		case 4:
		{
			ClearScreen();
			Ksr.ReverseGraph();
			break;
		}
		default:
		{
			break;
		}
		}
		cout << endl;
		cout << endl;
		cout << endl;
	}
}

void HeapAlgorightms()
{
	int choice = -1;
	int quitOption = 100;
	Heap heap;

	while (choice != quitOption)
	{
		cout << "Options:" << endl;
		cout << "1. Enter values to array" << endl;
		cout << "2. Display Heap values" << endl;
		cout << "3. Build Max Heap" << endl;
		cout << "4. Do Heap Sort" << endl;
		cout << "100. Quit" << endl;
		cout << "Enter your choice:" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			ClearScreen();
			int n;
			cout << "Enter no of elements" << endl;
			cin >> n;
			if (n > 0)
				heap.InsertElementsToArray(n);
			else
				cout << "Enter a positive value" << endl;
			break;
		}

		case 2:
		{
			ClearScreen();
			heap.PrintHeap();
			break;
		}
		case 3:
		{
			ClearScreen();
			heap.BuildHeap();
			break;
		}
		case 4:
		{
			ClearScreen();
			heap.HeapSort();
			break;
		}
		case 6:
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

void SearchAlgorithms()
{
	int choice = -1;
	int quitOption = 5;
	Search searchAlgo;

	while (choice != quitOption)
	{
		cout << "Options:" << endl;
		cout << "1. Enter values to array" << endl;
		cout << "2. Display Array values" << endl;
		cout << "3. Linear Search" << endl;
		cout << "4. Binary Search" << endl;
		cout << "5. Quit" << endl;
		cout << "Enter your choice:" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			ClearScreen();
			searchAlgo.CreateArray();
			break;
		}

		case 2:
		{
			ClearScreen();
			searchAlgo.Display();
			break;
		}
		case 3:
		{
			ClearScreen();
			int searchVal;
			cout << "Enter value to search:" << endl;
			cin >> searchVal;
			searchAlgo.LinearSearch(searchVal);
			break;
		}
		case 4:
		{
			ClearScreen();
			int searchVal;
			cout << "Enter value to search:" << endl;
			cin >> searchVal;
			searchAlgo.BinarySearch(searchVal);
			break;
		}
		case 5:
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

void GraphAlgorithms()
{
	int choice = -1;
	int quitOption = 5;

	Graph graphAlgo(true);

	while (choice != quitOption)
	{
		cout << "Options:" << endl;
		cout << "1. Enter Edges to Graph" << endl;
		cout << "2. Print Graph values" << endl;
		cout << "3. Breadth First Search" << endl;
		cout << "4. Depth First Search" << endl;
		cout << "5. Quit" << endl;
		cout << "Enter your choice:" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			ClearScreen();
			graphAlgo.ReadGraph();
			break;
		}

		case 2:
		{
			ClearScreen();
			graphAlgo.PrintGraph();
			break;
		}
		case 3:
		{
			ClearScreen();
			graphAlgo.BreadthFirstSearch();
			break;
		}
		case 4:
		{
			ClearScreen();
			graphAlgo.DepthFirstSearch();
			break;
		}
		case 5:
		{
			//ClearScreen();
			graphAlgo.Free();
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


void TreeAlgorithm()
{
	int choice = -1;
	int quitOption = 100;
	BinarySearchTree tree;

	while (choice != quitOption)
	{
		cout << "Options:" << endl;
		cout << "1. Add values to tree" << endl;
		cout << "2. Display tree values" << endl;
		cout << "3. Find Min" << endl;
		cout << "4. Find Max" << endl;
		cout << "5. Find Height" << endl;
		cout << "6. Inorder traversal" << endl;
		cout << "7. Pre order traversal" << endl;
		cout << "8. Post order traversal" << endl;
		cout << "9. Check if binary tree" << endl;
		cout << "10. Delete a node" << endl;
		cout << "100. Quit" << endl;
		cout << "Enter your choice:" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			ClearScreen();
			int val;
			cout << "Enter data to add to tree" << endl;
			cin >> val;
			tree.AddNode(val);
			break;
		}
		case 2:
		{
			ClearScreen();
			tree.LevelOrderTraversal();
			break;
		}
		case 3:
		{
			ClearScreen();
			tree.FindMin();
			break;
		}
		case 4:
		{
			ClearScreen();
			tree.FindMax();
			break;
		}
		case 5:
		{
			ClearScreen();
			tree.FindHeight();
			break;
		}
		case 6:
		{
			ClearScreen();
			tree.InorderTraversal();
			break;
		}
		case 7:
		{
			ClearScreen();
			tree.PreOrderTraversal();
			break;
		}
		case 8:
		{
			ClearScreen();
			tree.PostOrderTraversal();
			break;
		}
		case 9:
		{
			ClearScreen();
			tree.CheckIfBinaryTree();
			break;
		}
		case 10:
		{
			ClearScreen();
			int val;
			cout << "Enter val to delete" << endl;
			cin >> val;
			tree.DeleteNode(val);
		}
		case 100:
		{
			break;
		}
		default:
		{
			cout << "Enter proper choice" << endl;
			break;
		}
		}
		cout << endl;
		cout << endl;
		cout << endl;
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