#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "myUtils.h"

int findOftenElement(int length, int sortArray[])
{
	int oftenElement = sortArray[0];
	int countOftenElement = 1;
	int maxOftenElement = sortArray[0];
	int maxCountOftenElement = -1;
	for (int i = 1; i < length; ++i)
	{
		if (sortArray[i] == oftenElement)
		{
			++countOftenElement;
		}
		if ((sortArray[i] != oftenElement) || (i == length - 1))
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

void swap(int sortArray[], int index1, int index2)
{
	const int tmp = sortArray[index1];
	sortArray[index1] = sortArray[index2];
	sortArray[index2] = tmp;
}

void inputRandomArray(int length, int block[], int mod, int constant)
{
	srand(time(nullptr));
	for (int i = 0; i < length; ++i)
	{
		block[i] = rand() % mod + constant;
	}
}

void outputArray(int length, int block[])
{
	for (int i = 0; i < length; ++i)
	{
		printf("%d ", block[i]);
	}
}