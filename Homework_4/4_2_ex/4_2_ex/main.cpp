#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "myUtils.h"
#include "myQuickSort.h"
#include "tests.h"
#include "myUtilsForFiles.h"
#include <iostream>

int main()
{
	printf("Now program is testing, please, wait.\n");
	tests();
	printf("Tests are ok!\n");
	FILE *inputData = fopen("inputData.txt", "r");
	if (!inputData)
	{
		printf("File - inputData.txt - not found :(");
		system("pause");
		return 0;
	}
	const int maxLen = 10000;
	char *length = new char[maxLen] {};
	fscanf(inputData, "%s", length);
	int arrayLength = charToInt(length, 0, maxLen - 1);
	delete[] length;
	if (arrayLength <= 0)
	{
		printf("Wrong input data: length of array <= 0!");
		system("pause");
		return 0;
	}
	int *sortArray = new int[arrayLength] {};
	int countElementsInArray = 0;
	while (!feof(inputData))
	{
		char *buffer = new char[maxLen] {};
		const int checkingScanf = fscanf(inputData, "%s", buffer);
		if (checkingScanf < 0)
		{
			break;
		}
		sortArray[countElementsInArray] = charToInt(buffer, 0, arrayLength - 1);
		delete[] buffer;
		++countElementsInArray;
	}
	if (countElementsInArray != arrayLength)
	{
		printf("Count of elements of the array is less then length of the array!");
		system("pause");
		return 0;
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
	system("pause");
	return 0;
}

/*int main()
{
	printf("Now program is testing, please, wait.\n");
	tests();
	printf("Tests are ok!\n");
	printf("If there is more then one the most common element, program will output the first of these elements.\n");
	const int mod = 10;
	const int constant = 0;
	srand(time(nullptr));
	int length = rand() % mod + 1;
	int *sortArray = new int[length] {};
	inputRandomArray(length, sortArray, mod, constant);
	printf("Array:\n");
	outputArray(length, sortArray);
	printf("\n");
	int left = 0;
	int right = length - 1;
	myQuickSort(length, sortArray, left, right);
	outputArray(length, sortArray);
	printf("\n");
	int oftenElement = findOftenElement(length, sortArray);
	printf("%d", oftenElement);
	delete[] sortArray;
	return 0;
}
*/