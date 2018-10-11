#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

void pyramidSort(int length, int sortArray[])
{

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
	pyramidSort(length, sortArray);
	delete[] sortArray;
	system("pause");
	return 0;
}