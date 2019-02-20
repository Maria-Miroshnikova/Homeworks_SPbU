#include "myQuickSort.h"
#include "myUtils.h"
#include <vector>

using namespace std;

int middle(vector<int>& sortArray, int firstIndex, int secondIndex, int thirdIndex)
{
	if ((sortArray[secondIndex] > sortArray[firstIndex]) && (sortArray[secondIndex] < sortArray[thirdIndex]))
	{
		return secondIndex;
	}
	if ((sortArray[firstIndex] > sortArray[secondIndex]) && (sortArray[firstIndex] < sortArray[thirdIndex]))
	{
		return firstIndex;
	}
	return thirdIndex;
}

int medianElement(vector<int>& sortArray, int left, int right)
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
	return middle(sortArray, firstIndex, lastIndex, middleIndex);
}

void insertionSort(vector<int>& sortArray, int left, int rigth)
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

void quickSort(vector<int>& sortArray, int left, int right)
{
	int length = right - left + 1;
	if (length < 10)
	{
		insertionSort(sortArray, left, right);
		return;
	}
	const int supportElementIndex = medianElement(sortArray, left, right);
	if (supportElementIndex >= 0)
	{
		const int supportElement = sortArray[supportElementIndex];
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