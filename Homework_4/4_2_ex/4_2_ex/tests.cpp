#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
#include "myQuickSort.h"
#include "myUtils.h"
#include "myUtilsForFiles.h"
#include "tests.h"

void compareFind(int length, int sortArray[], int answer)
{
	assert(findOftenElement(length, sortArray) == answer);
}

void compareSort(int length, int sortArray[])
{
	myQuickSort(length, sortArray, 0, length - 1);
	for (int i = 0; i < length - 1; ++i)
	{
		assert(sortArray[i] <= sortArray[i + 1]);
	}
}

void tests()
{
	FILE *inputData = fopen("tests.txt", "r");
	if (!inputData)
	{
		printf("File - tests.txt - not found :(");
		assert(false);
	}
	const int maxLength = 1000000;
	while (!feof(inputData))
	{
		int testLength = readNumberFromFile(inputData, maxLength);
		if (testLength == maxLength * 10)
		{
			break;
		}

		int *testArray = new int[testLength] {};
		if (readArrayOfNumbersFromFile(inputData, maxLength, testArray, testLength) == maxLength * 10)
		{
			delete[] testArray;
			break;
		}

		int testAnswer = readNumberFromFile(inputData, maxLength);
		if (testAnswer == maxLength * 10)
		{
			break;
		}

		compareSort(testLength, testArray);
		compareFind(testLength, testArray, testAnswer);
		delete[] testArray;
	}
	fclose(inputData);
}