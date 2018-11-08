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
		return;
	}
	int supportElementIndex = medianElement(sortArray, left, right);
	if (supportElementIndex >= 0)
	{
		const int supportElement = sortArray[supportElementIndex];
		int indexLeft = left;
		int indexRight = right;
		while (indexLeft < indexRight)
		{
			while ((sortArray[indexLeft] <= supportElement) && (indexLeft < indexRight))
<<<<<<< HEAD:Homework_3/3_3_ex/3_3_ex/3_3_ex.cpp
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

int findOftenElement(int length, int sortArray[])
{
	int oftenElement = sortArray[0];
	int countOftenElement = 1;
	int maxOftenElement = sortArray[0];
	int maxCountOftenElement = -1;
	for (int i = 1; i < length; ++i)
	{
		if (sortArray[i] == oftenElement)
		{
			++countOftenElement;
		}
		if ((sortArray[i] != oftenElement) || (i == length - 1))
		{
			if (countOftenElement > maxCountOftenElement)
			{
				maxOftenElement = oftenElement;
				maxCountOftenElement = countOftenElement;
			}
			countOftenElement = 1;
			oftenElement = sortArray[i];
=======
			{
				++indexLeft;
			}
			while ((sortArray[indexRight] > supportElement) && (indexLeft < indexRight))
			{
				--indexRight;
			}
			swap(sortArray, indexLeft, indexRight);
>>>>>>> master:Homework_3/3_1_ex/3_1_ex/3_1_ex.cpp
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
	return maxOftenElement;
}

void inputArray(int length, int block[])
{
	for (int i = 0; i < length; ++i)
	{
		block[i] = rand() % 10;
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

void compareFind(int length, int sortArray[], int answer)
{
<<<<<<< HEAD:Homework_3/3_3_ex/3_3_ex/3_3_ex.cpp
	assert(findOftenElement(length, sortArray) == answer);
}

void compareSort(int length, int sortArray[])
{
=======
>>>>>>> master:Homework_3/3_1_ex/3_1_ex/3_1_ex.cpp
	quickSort(sortArray, 0, length - 1);
	for (int i = 0; i < length - 1; ++i)
	{
		assert(sortArray[i] <= sortArray[i + 1]);
	}
}

void tests()
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
}

//////////////////////////////////////////

int main()
{
	printf("Now program is testing, please, wait.\n");
	tests();
	printf("Tests are ok!\n");
	printf("If there is more then one the most common element, program will output the first of these elements.\n");
	srand(time(nullptr));
	int length = rand() % 10 + 1;
	int *sortArray = new int[length] {};
	inputArray(length, sortArray);
	printf("Array:\n");
	outputArray(length, sortArray);
	printf("\n");
	int left = 0;
	int right = length - 1;
	quickSort(sortArray, left, right);
	outputArray(length, sortArray);
	printf("\n");
	int oftenElement = findOftenElement(length, sortArray);
	printf("%d", oftenElement);
	delete[] sortArray;
	return 0;
}