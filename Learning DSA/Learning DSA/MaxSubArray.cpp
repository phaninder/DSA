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
	//BruteForce();
	//KandaneMethod();
	maxSum = DivideAndConquer(arr, 0, size-1);
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



void MaxSubArray::KandaneMethod()
{
	int tempMax = 0;

	for (int i = 0; i < size; i++)
	{
		tempMax += arr[i];

		if (tempMax < 0)
			tempMax = 0;

		if (maxSum < tempMax)
		{
			maxSum = tempMax;
		}
	}
}

int MaxSubArray::DivideAndConquer(int a[], int lowerIndex, int higherIndex)
{
	if (lowerIndex == higherIndex)
		return a[lowerIndex];
	int middleIndex = (lowerIndex + higherIndex) / 2;
	
	int leftMSS = DivideAndConquer(a, lowerIndex, middleIndex);
	int rightMSS = DivideAndConquer(a, middleIndex + 1, higherIndex);

	int tempSum = 0, sumLeft = INT32_MIN, sumRight = INT32_MIN;
	
	for (int i = middleIndex; i >= lowerIndex; i--)
	{
		tempSum += a[i];
		if (tempSum > sumLeft)
			sumLeft = tempSum;
	}

	tempSum = 0;
	for (int j = middleIndex+1; j <= higherIndex; j++)
	{
		tempSum += a[j];
		if (tempSum > sumRight)
			sumRight = tempSum;
	}
	int ans = FindMax(leftMSS, rightMSS);

	return(FindMax(ans, (sumLeft + sumRight)));
}

int MaxSubArray::FindMax(int a, int b)
{
	return (a > b) ? a : b;
}