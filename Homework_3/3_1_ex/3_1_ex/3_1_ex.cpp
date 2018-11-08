#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>

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

void insertionSort(int sortArray[], int left, int right)
{
	for (int i = left + 1; i <= right; ++i)
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

void quickSort(int sortArray[], int left, int right)
{
	int length = right - left + 1;
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
			quickSort(sortArray, left1, right1);
			quickSort(sortArray, left2, right2);
		}
		else
		{
			insertionSort(sortArray, left, right);
		}
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
//////////////////////////////////////////

void compare(int length, int sortArray[])
{
	quickSort(sortArray, 0, length - 1);
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
		int length = rand() % 500 + 9;
		int *sortArray = new int[length] {};
		inputArray(length, sortArray);
		compare(length, sortArray);
		++testOk;
		delete[] sortArray;
	}
}

//////////////////////////////////////////

int main()
{
	printf("Now program is testing, please, wait.\n");
	tests();
	printf("Tests are ok!\n");
	srand(time(nullptr));
	int length = rand() % 500 + 9;
	int *sortArray = new int[length] {};
	inputArray(length, sortArray);
	printf("Array:\n");
	outputArray(length, sortArray);
	printf("\n");
	int left = 0;
	int right = length - 1;
	quickSort(sortArray, left, right);
	outputArray(length, sortArray);
	delete[] sortArray;
	return 0;
}