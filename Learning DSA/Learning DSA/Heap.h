#pragma once

class Heap
{
private:
	int *arr;
	int noOfElements;
	void MaxHeap(int index,int size);
	void Swap(int x, int y);
public:
	Heap();
	Heap(int noOfElements);
	~Heap();
	void InsertElementsToArray(int noOfElements);
	void BuildHeap();
	void PrintHeap();
	void HeapSort();
};