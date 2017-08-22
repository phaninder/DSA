#pragma once

class MaxSubArray
{
private:
	int size, *arr;
	int maxSum, leftIndex, rightIndex;
	void BruteForce();
	void KandaneMethod();
public:
	MaxSubArray();
	MaxSubArray(int n, int temp[]);
	void PrintArrayProp();
	void FindMaxSum();
};