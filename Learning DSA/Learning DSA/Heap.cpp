#include<iostream>
#include "Heap.h"

using namespace std;

Heap::Heap()
{
	noOfElements = 0;
}

Heap::Heap(int val)
{
	noOfElements = val;
	arr = new int[val];
	for (int i = 0; i < val; i++)
	{
		arr[i] = INT32_MIN;
	}
}

Heap::~Heap()
{
	delete(arr);
	arr = nullptr;
}

void Heap::InsertElementsToArray(int n)
{
	noOfElements = n;
	arr = new int[n];
	int temp;
	cout << "Enter values to array" << endl;

	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		arr[i] = temp;
	}
}

void Heap::BuildHeap()
{
	//if (!maxHeap)
	//{
	//	// For building max heap
	//	for (int i = 0; i <noOfElements; i++)
	//	{
	//		arr[i] *= -1; //perform a multiplication by -1 to make them negative
	//	}
	//}

	// For building max heap
	for (int i = (noOfElements/2 -1); i>=0; i--)
	{
		MaxHeap(i, noOfElements);
	}

	//if (!maxHeap)
	//{
	//	// For building max heap
	//	for (int i = 0; i <noOfElements; i++)
	//	{
	//		arr[i] *= -1; //perform a multiplication by -1 to make them positive again
	//	}
	//}

}

void Heap::HeapSort()
{
	for (int i = noOfElements-1; i >=0; i--)
	{
		Swap(0, i);
		MaxHeap(0, i);
	}
}

void Heap::MaxHeap(int index,int size)
{
	int leftIndex = (index * 2) + 1;
	int rightIndex = (index * 2) + 2;

	int largestIndex = index;

	if (leftIndex<size && arr[leftIndex]>arr[largestIndex])
	{
		largestIndex = leftIndex;
	}

	if (rightIndex<size && arr[rightIndex] > arr[largestIndex])
	{
		largestIndex = rightIndex;
	}

	if (largestIndex != index)
	{
		Swap(index, largestIndex);
		MaxHeap(largestIndex,size);
	}	
}

void Heap::Swap(int x, int y)
{
	int temp = arr[x];
	arr[x] = arr[y];
	arr[y] = temp;
}

void Heap::PrintHeap()
{
	cout << "Elements in heap" << endl;
	for (int i = 0; i < noOfElements; i++)
	{
		cout << "" << arr[i] << endl;
	}
}