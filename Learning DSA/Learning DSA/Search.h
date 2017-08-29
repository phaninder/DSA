#pragma once

class Search
{
private:
	int *A, size;
	void BinaryHelper(int A[], int lb, int ub,int n);
public:
	Search();
	void CreateArray();
	void Display();
	void LinearSearch(int n);
	void BinarySearch(int n);
};