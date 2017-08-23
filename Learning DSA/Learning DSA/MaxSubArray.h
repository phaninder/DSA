#pragma once

class MaxSubArray
{
private:
	int size, *arr;
	int maxSum, leftIndex, rightIndex;
	void BruteForce();
	void KandaneMethod();
	int DivideAndConquer(int arr[], int lowerIndex, int higherIndex);
	int FindMax(int a, int b);
public:
	MaxSubArray();
	MaxSubArray(int n, int temp[]);
	void PrintArrayProp();
	void FindMaxSum();
};