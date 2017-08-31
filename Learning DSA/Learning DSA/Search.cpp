#include <iostream>
#include "Search.h"

using namespace std;

void Search::CreateArray()
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

void Search::Display()
{
	for (int i = 0; i < size; i++)
	{
		cout << A[i] << endl;
	}
}

Search::Search()
{

}

void Search::LinearSearch(int n)
{
	for (int i = 0; i < size; i++)
	{
		if (A[i] == n)
		{
			cout << n << " Found at index :" << i << endl;
			return;
		}
	}
	cout << n << " not found in the array" << endl;
}

void Search::BinarySearch(int n)
{
	BinaryHelper(A, 0, size - 1, n);
}

void Search::BinaryHelper(int A[], int lb, int ub,int n)
{
	if ((ub-lb) <=0)
	{
		cout << "Element not found in Array" << endl;
		return;
	}

	int mid = ((ub+lb) / 2);

	if (n == A[mid])
	{
		cout <<n<<" Element found at index: " << mid << endl;
		return; 
	}

	if(n<A[mid])
		BinaryHelper(A, lb, mid - 1,n);
	else
		BinaryHelper(A, mid + 1, ub, n);
}