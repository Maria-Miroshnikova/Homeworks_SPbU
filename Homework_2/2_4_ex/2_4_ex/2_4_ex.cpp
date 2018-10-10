#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>

void swap(int sortArray[], int index1, int index2)
{
	const int tmp = sortArray[index1];
	sortArray[index1] = sortArray[index2];
	sortArray[index2] = tmp;
}

void likeaQuickSort(int length, int sortArray[])
{
	const int firstElement = sortArray[0];
	int countNonSortElements = 0;
	for (int i = 1; i < length; ++i)
	{
		if (sortArray[i] <= firstElement)
		{
			++countNonSortElements;
		}
	}
	swap(sortArray, 0, countNonSortElements);
	int indexLeft = 0;
	int indexRight = length - 1;
	while ((indexLeft < countNonSortElements) && (countNonSortElements < indexRight))
	{
		while ((sortArray[indexLeft] <= firstElement) && (indexLeft < countNonSortElements))
		{
			++indexLeft;
		}
		while ((sortArray[indexRight] > firstElement) && (countNonSortElements < indexRight))
		{
			--indexRight;
		}
		swap(sortArray, indexLeft, indexRight);
	}
}

void inputArray(int length, int block[])
{
	for (int i = 0; i < length; ++i)
	{
		block[i] = rand() % 200 - 100;
	}
}

void outputArray(int length, int block[])
{
	for (int i = 0; i < length; ++i)
	{
		printf("%d ", block[i]);
	}
}

////////////////////////////////////////////////////////////////////////////

void comparisonArrays(int lenght, int testArray[], int answer[])
{
	likeaQuickSort(lenght, testArray);
	for (int i = 0; i < lenght; ++i)
	{
		assert(testArray[i] == answer[i]);
	}
}

void tests()
{
	const int lengthTest = 8;
	int testArray1[lengthTest]{ 5, 1, 3, 8, 4, 6, 2, 9 };
	int testArray2[lengthTest]{ 0, -1, -2, -3, -4, -5, -6, -7 };
	int testArray3[lengthTest]{ 1, 2, 3, 4, 5, 6, 7, 8 };
	int testArray4[lengthTest]{ 6, 1, 9, 4, 2, -1, 6, 6 };
	int answer1[lengthTest]{ 4, 1, 3, 2, 5, 6, 8, 9 };
	int answer2[lengthTest]{ -7, -1, -2, -3, -4, -5, -6, 0 };
	int answer3[lengthTest]{ 1, 2, 3, 4, 5, 6, 7, 8 };
	int answer4[lengthTest]{ 6, 1, 6, 4, 2, -1, 6, 9 };
	comparisonArrays(lengthTest, testArray1, answer1);
	comparisonArrays(lengthTest, testArray2, answer2);
	comparisonArrays(lengthTest, testArray3, answer3);
	comparisonArrays(lengthTest, testArray4, answer4);
}

////////////////////////////////////////////////////////////////////////////

int main()
{
	printf("Now program is testing, please, wait.\n");
	tests();
	printf("Tests are ok!\n");
	srand(time(nullptr));
	int length = rand() % 20 + 1;
	int *sortArray = new int[length] {};
	inputArray(length, sortArray);
	printf("Array:\n");
	outputArray(length, sortArray);
	printf("\n");
	likeaQuickSort(length, sortArray);
	outputArray(length, sortArray);
	delete[] sortArray;
	return 0;
}