#pragma once

class Sort
{
private:
	int *A,*leftArray,*rightArray, size;
	void MergeProcedure(int A[],int n);
	void Merge(int left[], int right[], int A[],int leftASize,int rightASize,int mainAsize);
public:
	Sort();
	void CreateArray();
	void BubbleSort();
	void InsertionSort();
	void SelectionSort();
	void MergeSort();
	void QuickSort();
	void Display();

};
