#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

void swap(int sortArray[], int index1, int index2)
{
	const int tmp = sortArray[index1];
	sortArray[index1] = sortArray[index2];
	sortArray[index2] = tmp;
}

int findMinElement(int length, int sortArray[], int indexSorted)
{
	int minElement = INT_MAX;
	int indexMinElement = 0;
	for (int i = indexSorted; i < length; ++i)
	{
		if (sortArray[i] < minElement)
		{
			minElement = sortArray[i];
			indexMinElement = i;
		}
	}
	return indexMinElement;
}

void selectionSort(int length, int sortArray[])
{
	int indexSorted = 0;
	while (indexSorted < length)
	{
		int indexMinElement = findMinElement(length, sortArray, indexSorted);
		swap(sortArray, indexMinElement, indexSorted);
		++indexSorted;
	}
}

void inputRandomArray(int length, int block[])
{
	srand(time(nullptr));
	for (int i = 0; i < length; ++i)
	{
		block[i] = rand() % 200 - 100;
	}
}

void inputArray(int length, int block[])
{
	for (int i = 0; i < length; ++i)
	{
		scanf("%d", &block[i]);
	}
}

void outputArray(int length, int block[])
{
	for (int i = 0; i < length; ++i)
	{
		printf("%d ", block[i]);
	}
}

////////////////////////////////////////////////////////////

void compare(int length, int sortArray[])
{
	selectionSort(length, sortArray);
	for (int i = 0; i < length - 1; ++i)
	{
		assert(sortArray[i] <= sortArray[i + 1]);
	}
}

void tests()
{
	const int testCount = 20;
	int testOk = 0;
	while (testOk < 20)
	{
		const int length = 10;
		int sortArray[length] {};
		inputRandomArray(length, sortArray);
		compare(length, sortArray);
		++testOk;
	}
}

////////////////////////////////////////////////////////////

int main()
{
	printf("Now program is testing, please, wait.\n");
	tests();
	printf("Tests are ok!\n");
	const int length = 10;
	int sortArray[10] {};
	printf("Please, enter the array for 10 elements:\n");
	inputArray(length, sortArray);
	selectionSort(length, sortArray);
	printf("\n");
	outputArray(length, sortArray);
	return 0;
}