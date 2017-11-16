#include <iostream>
using namespace std;

int max(int x, int y)
{
	return (x > y) ? x : y;
}

void PrintArray(int totalmat[][8],int r,int c)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
			cout << "" << totalmat[i][j]<<"\t";
		cout << endl;
	}
}

void Knapsack()
{
	int val[] = { 1,4,5,7 };
	int wt[] = { 1,3,4,5 };
	int maxWeight = 7;
	int totalVal[4][8] = { 0 };

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j <= maxWeight; j++)
		{
			if (j > 0)
			{
				if (j >=wt[i])
				{
					if (i > 0)
						totalVal[i][j] = max(val[i] + totalVal[i - 1][j-wt[i]], totalVal[i - 1][j]);
					else
						totalVal[i][j] = val[i];
				}
				else
				{
					if (i > 0)
						totalVal[i][j] = totalVal[i - 1][j];
					else
						totalVal[i][j] = 0;
				}
			}
			else
			{
				totalVal[i][j] = 0;
			}
		}
	}
	cout << "Matrix" << endl;
	PrintArray(totalVal, 4, 8);
}