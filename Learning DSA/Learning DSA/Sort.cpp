#include <iostream>
#include "Sort.h"

using namespace std;

Sort::Sort()
{

}

void Sort::CreateArray()
{
	cout << "Enter Size of array" << endl;
	cin >> size;
	A = new int[size];
	cout << "Enter Elements in to array" << endl;
	for (int i = 0; i < size; i++)
	{
		cin >> A[i];
	}
}

void Sort::BubbleSort()
{
	int temp;
	bool swapped;

	for (int i = 0; i < size; i++)
	{
		swapped = false;
		for (int j = 0; j < (size - i-1); j++)
		{
			if (A[j] > A[j + 1])
			{
				temp = A[j+1];
				A[j + 1] = A[j];
				A[j] = temp;
				swapped = true;
			}
		}
		if (!swapped)
			break;
	}
}

void Sort::Display()
{
	for (int i = 0; i < size; i++)
	{
		cout << A[i] << endl;
	}
}

void Sort::InsertionSort()
{
	int a = A[0];
	int temp;
	for (int i = 1; i < size; i++)
	{
		a = A[i];
		for (int j = 0; j <= i; j++)
		{
			if (A[j] > a)
			{
				temp = A[j];
				A[j] = a;
				a = temp;
			}
		}
		A[i] = a;
	}
}

void Sort::SelectionSort()
{
	//Find Min among the values
	int min = A[0];
	int minIndex = 0,temp;
	bool swap = false;
	for (int j = 0; j < size; j++)
	{
		min = A[j];
		swap = false;
		for (int i = j+1; i < size-j; i++)
		{
			if (min > A[i])
			{
				min = A[i];
				minIndex = i;
				swap = true;
			}
		}
		if (swap)
		{
			// Swap the values
			temp = A[j];
			A[j] = min;
			A[minIndex] = temp;
		}
	}

}

void Sort::MergeSort()
{
	MergeProcedure(A, size);
}

void Sort::MergeProcedure(int Arr[], int n)
{
	if (n < 2)
	{
		return;
	}
	int mid = (n/2);
	int *leftArray = new int[mid];
	for (int i = 0; i < mid; i++)
	{
		leftArray[i] = Arr[i];
	}
	int *rightArray = new int[n - mid];
	for (int i = 0,j=mid; i < (n-mid); i++,j++)
	{
		rightArray[i] = Arr[j];
	}
	//int rSize = (n - mid);
	MergeProcedure(leftArray, mid);
	MergeProcedure(rightArray, (n - mid));
	Merge(leftArray, rightArray, Arr,mid, (n - mid),n);
}
void Sort::Merge(int left[], int right[], int A[],int leftASize,int rightASize,int mainASize)
{
	int i = 0, j = 0,k=0;
	while (i < leftASize && j < rightASize)
	{
		if (left[i] < right[j])
		{
			A[k] = left[i];
			k++;
			i++;
		}
		else
		{
			A[k] = right[j];
			k++;
			j++;
		}
	}

	while (i < leftASize)
	{
		A[k] = left[i];
		k++;
		i++;
	}

	while (j < rightASize)
	{
		A[k] = right[j];
		k++;
		j++;
	}
}

void Sort::QuickSort()
{
	QuickSorting(A, 0, size-1);
}

void Sort::QuickSorting(int A[], int lb, int ub)
{
	if (lb >= ub)
		return;
	int partionIndex = Partition(A, lb, ub);
	QuickSorting(A, lb, partionIndex-1);
	QuickSorting(A, partionIndex + 1, ub);
}

int Sort::Partition(int A[], int lb, int ub)
{
	int head=lb, tail=ub;
	int mid = (head + tail) / 2;
	int partitionEle = A[mid];
	int temp;

	while (head < tail)
	{
		if (A[head] < partitionEle)
		{
			head++;
		}

		if (A[tail] > partitionEle)
		{
			tail--;
		}

		if (head < tail)
		{
			temp = A[head];
			A[head] = A[tail];
			A[tail] = temp;
		}
	}

	A[tail] = partitionEle;
	return tail;
}