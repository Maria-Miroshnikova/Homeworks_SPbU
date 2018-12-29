#include "myUtils.h"
#include <vector>

using namespace std;

int findOftenElement(vector<int>& sortArray)
{
	int oftenElement = sortArray[0];
	int countOftenElement = 1;
	int maxOftenElement = sortArray[0];
	int maxCountOftenElement = -1;
	for (int i = 1; i < sortArray.size(); ++i)
	{
		if (sortArray[i] == oftenElement)
		{
			++countOftenElement;
		}
		if ((sortArray[i] != oftenElement) || (i == sortArray.size() - 1))
		{
			if (countOftenElement > maxCountOftenElement)
			{
				maxOftenElement = oftenElement;
				maxCountOftenElement = countOftenElement;
			}
			countOftenElement = 1;
			oftenElement = sortArray[i];
		}
	}
	return maxOftenElement;
}

void swap(vector<int>& sortArray, int index1, int index2)
{
	const int tmp = sortArray[index1];
	sortArray[index1] = sortArray[index2];
	sortArray[index2] = tmp;
}