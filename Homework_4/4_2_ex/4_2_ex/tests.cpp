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

int findSpace(char charArray[], int startIndex)
{
	int endIndex = -1;
	int checkEndOfArray = 1;
	int i = startIndex;
	while (charArray[i] != '\0')
	{
		if (charArray[i] == ' ')
		{
			endIndex = i;
			break;
		}
		checkEndOfArray = 0;
		++i;
	}
	if ((checkEndOfArray == 0) && (endIndex = -1))
	{
		endIndex = startIndex;
	}
	return endIndex;
}

void tests()
{
	FILE *testsData = fopen("tests.txt", "r");
	if (!testsData)
	{
		printf("File - tests.txt - not found :(");
	}
	while (!feof(testsData))
	{
		const int maxLen = 10000;
		char *bufferLength = new char[maxLen] {};
		fscanf(testsData, "%s", bufferLength);
		int testArrayLength = charToInt(bufferLength, 0, maxLen - 1);
		delete[] bufferLength;
		printf("Length is %d\n", testArrayLength);
		if (testArrayLength <= 0)
		{
			printf("Wrong tests data: length of testArray <= 0!");
		}
		int *testArray = new int[testArrayLength] {};
		int countElementsInArray = 0;
		char *buffer = new char[maxLen] {};
		char *checkingScanf = fgets(buffer, maxLen, testsData);
		if (!checkingScanf)
		{
			break;
		}
		int i = 0;
		int startIndex = 0;
		int endIndex = findSpace(buffer, startIndex);
		while (endIndex != startIndex)
		{
			testArray[i] = charToInt(buffer, startIndex, endIndex - 1);
			startIndex = endIndex + 1;
			endIndex = findSpace(buffer, startIndex);
			++i;
		}
		if (endIndex == startIndex)
		{
			testArray[i] = charToInt(buffer, startIndex, maxLen - 1);
		}
		outputArray(testArrayLength, testArray);
		printf("\n");
		delete[] buffer;
		char *bufferAnswer = new char[maxLen] {};
		fscanf(testsData, "%s", bufferAnswer);
		int testAnswer = charToInt(bufferAnswer, 0, maxLen - 1);
		printf("Answer is %d\n", testAnswer);
		delete[] bufferAnswer;
		compareSort(testArrayLength, testArray);
		compareFind(testArrayLength, testArray, testAnswer);
		delete[] testArray;
	}
	fclose(testsData);
	

}

/*void tests()
{
	const int testLen1 = 6;
	int testArray1[testLen1] = { 1, 0, 1, 5, 5, 5 };
	int testAnswer1 = 5;
	const int testLen2 = 7;
	int testArray2[testLen2] = { 1, 0, 1, 0, 0, 1, -1 };
	int testAnswer2 = 0;
	const int testLen3 = 6;
	int testArray3[testLen3] = { 3, 1, 2, 2, 2, 3 };
	int testAnswer3 = 2;
	compareSort(testLen1, testArray1);
	compareFind(testLen1, testArray1, testAnswer1);
	compareSort(testLen2, testArray2);
	compareFind(testLen2, testArray2, testAnswer2);
	compareSort(testLen3, testArray3);
	compareFind(testLen3, testArray3, testAnswer3);
}*/