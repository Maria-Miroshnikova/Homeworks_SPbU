#include <stdio.h>
#include "myUtils.h"
#include "myQuickSort.h"

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

void myQuickSort(int length, int sortArray[], int left, int right)
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
			myQuickSort(length1, sortArray, left1, right1);
			myQuickSort(length2, sortArray, left2, right2);
		}
		else
		{
			insertionSort(sortArray, left, right);
		}
	}
}
