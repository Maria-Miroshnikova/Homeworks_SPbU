#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <alg.h>
#include <iostream>

/// tree -> heap
/// swap head and root
/// add hew root to unvisible zone

void makeHeap(int sortArray[], int invisibleIndex)
{
	for (int i = invisibleIndex; i > 0; i += 2)
	{
		int leftSon = INT_MIN;
		int rightSon = INT_MIN;
		int father = INT_MIN;
		int justOneSon = 0;
		if ((i % 2) == 0)
		{
			leftSon = sortArray[i - 1];
			rightSon = sortArray[i];
			father = sortArray[(i - 1) / 2];
		}
		else
		{
			leftSon = sortArray[i];
			father = sortArray[i / 2];
			++justOneSon;
		}
		

	}
}



void heapSort(int length, int sortArray[], int invisibleIndex)
{
	while (invisibleIndex >= 0)
	{
		makeHeap();
		swapRootHead();
		--invisibleIndex;
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

int main()
{
	int length = 0;
	scanf("%d", &length);
	int *sortArray = new int[length] {};
	inputArray(length, sortArray);
	printf("Array:\n");
	outputArray(length, sortArray);
	printf("\n");
	int invisibleIndex = length - 1;
	heapSort(length, sortArray, invisibleIndex);
	delete[] sortArray;
	system("pause");
	return 0;
}