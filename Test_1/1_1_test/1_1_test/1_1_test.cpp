#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>

int findStartNumber(int length, int number[], int indexStart)
{
	for (int i = 0; i < length; ++i)
	{
		if (number[i] == 1)
		{
			indexStart = i;
			break;
		}
	}
	return indexStart;
}

int maxNumber(int  length1, int length2, int number1[], int number2[])
{
	int index1 = -1;
	int index2 = -1;
	index1 = findStartNumber(length1, number1, index1);
	index2 = findStartNumber(length2, number2, index2);
	if ((index1 == -1) || (index2 == -1))
	{
		if ((index1 == -1) && (index2 == -1))
		{
			return 0;
		}
		if (index1 == -1)
		{
			return 2;
		}
		if (index1 == -1)
		{
			return 1;
		}
	}
	int truelength1 = length1 - index1;
	int truelength2 = length2 - index2;
	if (truelength1 > truelength2)
	{
		return 1;
	}
	if (truelength1 < truelength2)
	{
		return 2;
	}
	int countCompares = 0;
	while (countCompares < truelength1)
	{
		if (number1[index1] < number2[index2])
		{
			return 2;
		}
		if (number1[index1] > number2[index2])
		{
			return 1;
		}
		++index1;
		++index2;
	}
	return 0;
}

 void inputRandomArray(int length, int block[])
{
	for (int i = 0; i < length; ++i)
	{
		block[i] = rand() % 2 ;
	}
}

 void outputArray(int length, int block[])
 {
	 for (int i = 0; i < length; ++i)
	 {
		 printf("%d ", block[i]);
	 }
 }

 ////////////////////////////////////////////////////

 void compare(int length1, int length2, int number1[], int number2[], int answer)
 {
	 int numberMaxNumber = maxNumber(length1, length2, number1, number2);
	 assert(numberMaxNumber == answer);
 }

 void tests()
 {
	 const int testLen11 = 1;
	 const int testLen12 = 4;
	 int testNumber11[testLen11] = { 0 };
	 int testNumber12[testLen12] = { 0, 0, 0, 0 };
	 int testAnswer1 = 0;
	 const int testLen21 = 2;
	 const int testLen22 = 4;
	 int testNumber21[testLen21] = { 1, 1 };
	 int testNumber22[testLen22] = { 0, 0, 0, 1 };
	 int testAnswer2 = 1;
	 const int testLen31 = 5;
	 const int testLen32 = 4;
	 int testNumber31[testLen31] = { 0, 0, 1, 0, 0 };
	 int testNumber32[testLen32] = { 0, 1, 0, 1 };
	 int testAnswer3 = 2;
	 compare(testLen11, testLen12, testNumber11, testNumber12, testAnswer1);
	 compare(testLen21, testLen22, testNumber21, testNumber22, testAnswer2);
	 compare(testLen31, testLen32, testNumber31, testNumber32, testAnswer3);
 }

 ////////////////////////////////////////////////////

int main()
{
	srand(time(nullptr));
	printf("Now program is testing, please, wait.\n");
	tests();
	printf("Tests are ok!\n");
	int length1 = rand() % 10 + 1;
	int length2 = rand() % 10 + 1; 
	int *number1 = new int[length1] {};
	int *number2 = new int[length2] {};
	inputRandomArray(length1, number1);
	inputRandomArray(length2, number2);
	outputArray(length1, number1);
	printf("\n");
	outputArray(length2, number2);
	printf("\n");
	int numberMaxNumber = maxNumber(length1, length2, number1, number2);
	if (numberMaxNumber == 0)
	{
		printf("Numbers are the same!");
		return 0;
		delete[] number1;
		delete[] number2;
	}
	printf("%d\n", numberMaxNumber);
	delete[] number1;
	delete[] number2;
	return 0;
}