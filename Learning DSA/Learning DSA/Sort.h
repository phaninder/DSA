#pragma once

class Sort
{
private:
	int *A,*leftArray,*rightArray, size;
	void MergeProcedure(int A[],int n);
	void Merge(int left[], int right[], int A[],int leftASize,int rightASize,int mainAsize);
	void QuickSorting(int A[], int lb, int ub);
	int Partition(int A[], int lb, int ub);
public:
	Sort();
	void CreateArray();
	void BubbleSort();
	void InsertionSort();
	void SelectionSort();
	void MergeSort();
	void MergeSort(int *Ar, int size);
	void QuickSort();
	void QuickSort(int *A,int lastIndex);
	void Display();

};
