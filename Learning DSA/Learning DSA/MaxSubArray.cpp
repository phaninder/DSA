#include "MaxSubArray.h"
#include <iostream>

using namespace std;

MaxSubArray::MaxSubArray()
{
	size = 0;
	arr = new int[size];
	maxSum = INT32_MIN;
	leftIndex = 0;
	rightIndex = 0;
}

MaxSubArray::MaxSubArray(int n, int temp[])
{
	size = n;
	arr = new int[size];
	maxSum = INT32_MIN;
	leftIndex = 0;
	rightIndex = 0;

	for (int i = 0; i < size; i++)
	{
		arr[i] = temp[i];
	}
}

void MaxSubArray::PrintArrayProp()
{
	cout << "Max sum of sub array: " << maxSum << endl;
	cout << "Element of Max Sub array : "<< endl;

	for (int i = leftIndex; i <= rightIndex; i++)
	{
		cout << arr[i] << endl;
	}
}

void MaxSubArray::FindMaxSum()
{
	BruteForce();
}

//Uses brute force to find the max sum of sub array
void MaxSubArray::BruteForce()
{
	for (int i = 0; i < size; i++)
	{
		int sum = 0;
		for (int j = 1; j <= size; j++)
		{
			if (i + j > size)
				break;
			sum += arr[i + j -1 ]; // add to sum
			if (sum > maxSum)
			{
				maxSum = sum;
				leftIndex = i;
				rightIndex = i+j-1;
			}
		}
	}
}
