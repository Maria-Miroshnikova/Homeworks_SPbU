#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
#include <limits.h>

void sortBubble(int length, int block[])
{
	for (int i = 0; i < length; ++i)
	{
		for (int j = 0; j < length - i - 1; ++j)
		{
			if (block[j] > block[j + 1])
			{
				int tmp = block[j];
				block[j] = block[j + 1];
				block[j + 1] = tmp;
			}
		}
	}
}

void sortCounting(int length, int block[])
{
	const int veryFew = INT_MIN;
	int maximum = veryFew;
	int minimum = 0;
	for (int i = 0; i < length; ++i)
	{
		if (block[i] > maximum)
		{
			maximum = block[i];
		}
		if (block[i] < minimum)
		{
			minimum = block[i];
		}
	}
	int lengthCountBlock = maximum + 1 - minimum;
	int *countBlock = new int[lengthCountBlock] {};
	for (int i = 0; i < length; ++i)
	{
		++countBlock[block[i] - minimum];
	}
	int indexForSortElement = 0;
	for (int i = 0; i < lengthCountBlock; ++i)
	{
		while (countBlock[i] > 0)
		{
			block[indexForSortElement] = i + minimum;
			++indexForSortElement;
			--countBlock[i];
		}
	}
	delete[] countBlock;
}

void pathSelection(int way, int length, int block[])
{
	if (way == 1)
	{
		sortBubble(length, block);
	}
	else
	{
		sortCounting(length, block);
	}
}

bool hasLengthProblem(int length)
{
	if (length <= 0)
	{
		if (length == 0)
		{
			printf("It is sorted.");
		}
		else
		{
			printf("Incorrect input: length < 0.");
		}
		return true;
	}
	return false;
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

///////////////////////////////////////////////////////////

void comparisonBlocks(int length, int block1[], int block2[], int answer[])
{
	pathSelection(1, length, block1);
	pathSelection(2, length, block2);
	for (int i = 0; i < length; ++i)
	{
		assert((block1[i] == block2[i]) && (block1[i] == answer[i]));
	}
}

void tests()
{
	const int lengthTestBlock = 6;
	int testBlock11[lengthTestBlock]{ -2, 9, 0, 0, -1, -2 };
	int testBlock21[lengthTestBlock]{ 100, 57, 32, 9, 2, 0 };
	int testBlock31[lengthTestBlock]{ -100, -1, 0, -100, 100, -100 };
	int testBlock41[lengthTestBlock]{ -1, -1, -1, -1, -1, -1 };
	int testBlock12[lengthTestBlock]{ -2, 9, 0, 0, -1, -2 };
	int testBlock22[lengthTestBlock]{ 100, 57, 32, 9, 2, 0 };
	int testBlock32[lengthTestBlock]{ -100, -1, 0, -100, 100, -100 };
	int testBlock42[lengthTestBlock]{ -1, -1, -1, -1, -1, -1 };
	int answer1[lengthTestBlock]{ -2, -2, -1, 0, 0, 9 };
	int answer2[lengthTestBlock]{ 0, 2, 9, 32, 57, 100 };
	int answer3[lengthTestBlock]{ -100, -100, -100, -1, 0, 100 };
	int answer4[lengthTestBlock]{ -1, -1, -1, -1, -1, -1 };
	comparisonBlocks(lengthTestBlock, testBlock11, testBlock12, answer1);
	comparisonBlocks(lengthTestBlock, testBlock21, testBlock22, answer2);
	comparisonBlocks(lengthTestBlock, testBlock31, testBlock32, answer3);
	comparisonBlocks(lengthTestBlock, testBlock41, testBlock42, answer4);
}

///////////////////////////////////////////////////////////

int main()
{
	printf("Now program is testing, please, wait.\n");
	tests();
	printf("Tests are ok!\n");
	printf("This program will push out the biggest element to the end of array.\n");
	printf("Please, enter the length of array:\n");
	int length = 0;
	scanf("%d", &length);
	if (hasLengthProblem(length))
	{
		return 0;
	}
	int *block = new int[length] {};
	printf("Please, enter the elements of array one by one with space between them:\n");
	inputArray(length, block);
	printf("Which way of sort would you prefer: 1 - bubble, 2 - counting? Please, enter 1 or 2:\n");
	int way = 0;
	scanf("%d", &way);
	if ((way != 1) && (way != 2))
	{
		printf("Incorrect input: nonexistent way of sort.");
		return 0;
	}
	pathSelection(way, length, block);
	outputArray(length, block);
	delete[] block;
	return 0;
}