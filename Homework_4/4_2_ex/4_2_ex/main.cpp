#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "myUtils.h"
#include "myQuickSort.h"
#include "tests.h"
#include "myUtilsForFiles.h"

int main()
{
	printf("Now program is testing, please, wait.\n");
	tests();
	printf("Tests are ok!\n");
	FILE *inputData = fopen("inputData.txt", "r");
	if (!inputData)
	{
		printf("File - inputData.txt - not found :(");
		return 1;
	}

	const int maxLength = 10000;
	int arrayLength = readNumberFromFile(inputData, maxLength);
	if (arrayLength <= 0)
	{
		printf("Wrong input data: length of array <= 0!");
		return 1;
	}

	int *sortArray = new int[arrayLength] {};
	int checkingReadArray = readArrayOfNumbersFromFile(inputData, maxLength, sortArray, arrayLength);
	if (checkingReadArray == maxLength * 10)
	{
		printf("Count of elements of the array is less then length of the array!");
		return 1;
	}
	if (checkingReadArray == -(maxLength * 10))
	{
		printf("Count of elements of the array is grater then length of the array!");
		return 1;
	}

	outputArray(arrayLength, sortArray);
	printf("\n");
	int left = 0;
	int right = arrayLength - 1;
	myQuickSort(arrayLength, sortArray, left, right);
	outputArray(arrayLength, sortArray);
	printf("\n");
	int oftenElement = findOftenElement(arrayLength, sortArray);
	printf("%d", oftenElement);
	delete[] sortArray;
	fclose(inputData);
	return 0;
}