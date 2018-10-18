#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

int middle(int first, int firstIndex, int second, int secondIndex, int third, int thirdIndex)
{
	if ((second > first) && (second < third))
	{
		return secondIndex;
	}
	if ((first > second) && (first < third))
	{
		return firstIndex;
	}
	return thirdIndex;
}

int medianElement(int sortArray[], int left, int right)
{
	int sameElementsDetect = 0;
	int sameElementsFix = 0;
	int firstIndex = left;
	int firstElement = sortArray[firstIndex];
	int lastIndex = right;
	int lastElement = sortArray[lastIndex];
	if (lastElement == firstElement)
	{
		++sameElementsDetect;
		for (int i = right - 1; i > left; --i)
		{
			if (sortArray[i] != firstElement)
			{
				lastElement = sortArray[i];
				lastIndex = i;
				++sameElementsFix;
				break;
			}
		}
	}
	int middleIndex = left + 1;
	int middleElement = sortArray[middleIndex];
	if ((middleElement == lastElement) || (middleElement == firstElement))
	{
		++sameElementsDetect;
		for (int i = middleIndex; i < right; ++i)
		{
			if ((sortArray[i] != firstElement) && (sortArray[i] != lastElement))
			{
				middleElement = sortArray[i];
				middleIndex = i;
				++sameElementsFix;
				break;
			}
		}
	}
	if ((sameElementsDetect > 0) && (sameElementsFix != sameElementsDetect))
	{
		if (sameElementsDetect - sameElementsFix == 1)
		{
			return -2;
		}
		return -1;
	}
	return middle(firstElement, firstIndex, lastElement, lastIndex, middleElement, middleIndex);
}

void swap(int sortArray[], int index1, int index2)
{
	const int tmp = sortArray[index1];
	sortArray[index1] = sortArray[index2];
	sortArray[index2] = tmp;
}

void insertionSort(int sortArray[], int left, int rigth)
{
	for (int i = left + 1; i <= rigth; ++i)
	{
		int sortElement = sortArray[i];
		int index = i;
		for (int j = index - 1; j >= left; --j)
		{
			if (sortArray[j] <= sortElement)
			{
				break;
			}
			else
			{
				swap(sortArray, j, index);
				--index;
			}
		}
	}
}

void quickSort(int length, int sortArray[], int left, int right)
{
	if (length < 10)
	{
		insertionSort(sortArray, left, right);
	}
	else
	{
		int supportElementIndex = medianElement(sortArray, left, right);
		if (supportElementIndex >= 0)
		{
			int supportElement = sortArray[supportElementIndex];
			int indexLeft = left;
			int indexRight = right;
			while (indexLeft < indexRight)
			{
				while ((sortArray[indexLeft] <= supportElement) && (indexLeft < indexRight))
				{
					++indexLeft;
				}
				while ((sortArray[indexRight] > supportElement) && (indexLeft < indexRight))
				{
					--indexRight;
				}
				swap(sortArray, indexLeft, indexRight);
			}
			int left1 = left;
			int right1 = indexLeft - 1;
			int left2 = indexLeft;
			int right2 = right;
			int length2 = length - left2;
			int length1 = length - length2;
			quickSort(length1, sortArray, left1, right1);
			quickSort(length2, sortArray, left2, right2);
		}
		else
		{
			insertionSort(sortArray, left, right);
		}
	}
}

int binarySearch(int indexLeft, int indexRight, int randomArray[], int number)
{
	int length = indexRight - indexLeft + 1;
	if (length == 1)
	{
		if (number == randomArray[indexLeft])
		{
			return 1;
		}
		return 0;
	}
	int indexMiddleElement = indexLeft + length / 2 - 1;
	if (number == randomArray[indexMiddleElement])
	{
		return 1;
	}
	if (number > randomArray[indexMiddleElement])
	{
		if (indexMiddleElement != indexRight)
		{
			return binarySearch(indexMiddleElement + 1, indexRight, randomArray, number);
		}
		return 0;
	}
	if (number < randomArray[indexMiddleElement])
	{
		if (indexMiddleElement != indexLeft)
		{
			return binarySearch(indexLeft, indexMiddleElement - 1, randomArray, number);
		}
		return 0;
	}
}

int isPresentInArray(int length, int randomArray[], int number)
{
	return binarySearch(0, length - 1, randomArray, number);
}

void inputRandomArray(int length, int block[], int maximum)
{
	for (int i = 0; i < length; ++i)
	{
		block[i] = rand() % maximum;
	}
}

void outputArray(int length, int block[])
{
	for (int i = 0; i < length; ++i)
	{
		printf("%d ", block[i]);
	}
}

void checkingPresence(int length, int randomArray[], int countNumbers, int maximum)
{
	for (int i = 0; i < countNumbers; ++i)
	{
		int number = rand() % maximum;
		outputArray(length, randomArray);
		printf("\n");
		if (isPresentInArray(length, randomArray, number))
		{
			printf("There is (%d) in the array\n\n", number);
		}
		else
		{
			printf("There is no (%d) in the array\n\n", number);
		}
	}
}

//////////////////////////////////////////////////////////////////

void compare(int testLength, int testArray[], int testCount, int testNumbers[], int testAnswer[])
{
	quickSort(testLength, testArray, 0, testLength - 1);
	for (int i = 0; i < testCount; ++i)
	{
		assert(isPresentInArray(testLength, testArray, testNumbers[i]) == testAnswer[i]);
	}
}

void tests()
{
	const int testLen1 = 5;
	int testArray1[testLen1] {0, 5, 1, 5, 2};
	const int testCount1 = 10;
	int testNumbers1[testCount1] {0, 1, 1, 5, 2, 3, 3, 7, -1, 4};
	int testAnswer1[testCount1] {1, 1, 1, 1, 1, 0, 0, 0, 0, 0 };
	const int testLen2 = 1;
	int testArray2[testLen2] {-1};
	const int testCount2 = 5;
	int testNumbers2[testCount2] { 0, 1, 2, -1, -2};
	int testAnswer2[testCount2] { 0, 0, 0, 1, 0 };
	compare(testLen1, testArray1, testCount1, testNumbers1, testAnswer1);
	compare(testLen2, testArray2, testCount2, testNumbers2, testAnswer2);
}

//////////////////////////////////////////////////////////////////

int main()
{
	printf("Now program is testing, please, wait.\n");
	tests();
	printf("Tests are ok!\n");
	const int maximum = 1000000000;
	srand(time(nullptr));
	int length = 0;
	printf("Please, enter the length of array for random numbers:\n");
	scanf("%d", &length);
	int *randomArray = new int[length] {};
	inputRandomArray(length, randomArray, maximum);
	printf("Random array:\n");
	outputArray(length, randomArray);
	printf("\n\n");
	quickSort(length, randomArray, 0, length - 1);
	printf("Sorted random array:\n");
	outputArray(length, randomArray);
	printf("\n\n");
	int countNumbers = 0;
	printf("Please, enter the count of numbers for checking the presence of numbers in the array:\n");
	scanf("%d", &countNumbers);
	checkingPresence(length, randomArray, countNumbers, maximum);
	delete[] randomArray;
	system("pause");
	return 0;
}
