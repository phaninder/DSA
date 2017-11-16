#include <iostream>

using namespace std;


struct result
{
	char ch;
	int val;
};

void LongestConsCharacter()
{
	int length = 11;
	char ch[] = { 'A','A','B','C','D','D','E','B','B','B','B' };
	result ResultArray[11];

	int count = 1;
	int index = 0;
	for (int i = 0; i <= length-1; i++)
	{
		if (i!=length-1 && ch[i] == ch[i + 1])
		{
			count++;
		}
		else
		{
			ResultArray[index].ch = ch[i];
			ResultArray[index].val = count;
			//Rest count
			count = 1;
			index++;
		}
	}
	
	//Print the result
	for (int i = 0; i < index; i++)
	{
		cout << ResultArray[i].ch << "---" << ResultArray[i].val << endl;
	}
}
int max(int x, int y);
//Refer to video 2 of Tushar/Dynamic programming for question details
void LongestCommonSubSequence()
{
	//char ch1[] = { '3','4','1','2','1','3' };
	//char ch2[] = { '1','2','3','4','1' };

	char ch1[] = { 'a','b','c','d','a','f' };
	char ch2[] = { 'a','c','b','c','f' };
	int length1 = sizeof(ch1) / sizeof(char);
	int length2 = sizeof(ch2) / sizeof(char);

	int lcs[6][7] = { 0 };

	for (int i = 0; i < length2; i++)
	{
		for (int j = 0; j < length1; j++)
		{
			/*if (i == 0 || j == 0)
			{
				lcs[i][j] = 0;
				continue;
			}*/
			//initially fill the first row and first column with 0 
			if (ch2[i] == ch1[j])
			{
				lcs[i + 1][j + 1] = lcs[i][j]+1;
			}
			else
			{
				lcs[i+1][j+1] = max(lcs[i+1][j], lcs[i][j+1]);
			}
		}

	}
	int index = lcs[5][6];
	char *res;

	res = new char[index+1];
	res[index] = '\0';
	int i = 5, j = 6;
	while (i > 0 && j > 0)
	{
		if (ch2[i - 1] == ch1[j - 1])
		{
			res[index - 1] = ch2[i - 1];
			i--; j--; index--;
		}
		else if (lcs[i - 1][j] > lcs[i][j - 1])
			i--;
		else
			j--;		
	}
	cout << "Final result:" << res << endl;
	//print matrix
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			cout << lcs[i][j] << "\t";
		}
		cout << endl;
	}

}