#include <iostream>
#include <stdlib.h>
#include "MaxSubArray.h"

using namespace std;

int main()
{
	int size, *dummyArr;
	cout << "No of elements:" << endl;
	cin >> size;
	cout << "Enter values for Array:" << endl;

	dummyArr = new int[size];
	for (int i = 0; i < size; i++)
	{
		cin >> dummyArr[i];
	}

	MaxSubArray maxSub(size, dummyArr);
	maxSub.FindMaxSum();
	// prints the array props
	maxSub.PrintArrayProp();
	system("PAUSE");
	return 0;
}