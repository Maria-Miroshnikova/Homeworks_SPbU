#include <vector>
#include <limits>
#include <iostream>

using namespace std;

void outputVectors(vector<int>& outputX, vector<int>& outputY)
{
	for (int i = 0; i < outputX.size(); ++i)
	{
		cout << "(" << outputX[i] << " , " << outputY[i] << ")" << endl;
	}
}

void inputArrange(vector<vector<int>>& numbers, const int sizeI, const int sizeJ)
{
	vector<int> lineI;
	for (int i = 0; i < sizeI; ++i)
	{
		for (int j = 0; j < sizeJ; ++j)
		{
			int newNumber = 0;
			cin >> newNumber;
			lineI.push_back(newNumber);
		}
		numbers.push_back(lineI);
		lineI.resize(0);

	}
}

void findSaddle(vector<vector<int>>& numbers, const int sizeI, const int sizeJ, vector<int>& saddleX, vector<int>& saddleY)
{
	vector<int> minInLine;
	for (int i = 0; i < sizeI; ++i)
	{
		minInLine.push_back(INT_MAX);
	}

	vector<int> maxInColumn;
	for (int i = 0; i < sizeJ; ++i)
	{
		maxInColumn.push_back(INT_MIN);
	}

	int indexLine = 0;

	for (int i = 0; i < sizeI; ++i)
	{
		for (int j = 0; j < sizeJ; ++j)
		{
			if (minInLine[indexLine] >= numbers[i][j])
			{
				minInLine[indexLine] = numbers[i][j];
			}
		}
		++indexLine;
	}

	int indexColumn = 0;

	for (int j = 0; j < sizeJ; ++j)
	{
		for (int i = 0; i < sizeI; ++i)
		{
			if (maxInColumn[indexColumn] <= numbers[i][j])
			{
				maxInColumn[indexColumn] = numbers[i][j];
			}
		}
		++indexColumn;
	}

	for (int i = 0; i < sizeI; ++i)
	{
		for (int j = 0; j < sizeJ; ++j)
		{
			if ((numbers[i][j] == minInLine[i]) && (numbers[i][j] == maxInColumn[j]))
			{
				saddleX.push_back(i);
				saddleY.push_back(j);
			}
		}
	}
}