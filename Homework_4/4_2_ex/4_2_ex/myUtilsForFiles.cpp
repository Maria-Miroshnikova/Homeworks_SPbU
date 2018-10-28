#include <stdio.h>
#include "myUtils.h"
#include "myUtilsForFiles.h"

int charToInt(char charArray[], int startArray, int endArray)
{
	int number = 0;
	bool isMinus = false;
	int i = startArray;
	if (charArray[i] == '-')
	{
		isMinus = true;
		i = startArray + 1;
	}
	while (((charArray[i] != '\0') && (charArray[i] != '\n')) && (i != endArray) && (charArray[i] != ' '))
	{
		number = number * 10 + (charArray[i] - '0');
		++i;
	}
	if (isMinus)
	{
		number = -number;
	}
	return number;
}

int findSpace(char charArray[], int startIndex)
{
	int endIndex = -1;
	int checkEndOfArray = 1;
	int i = startIndex;
	while (charArray[i] != '\0')
	{
		if (charArray[i] == ' ')
		{
			endIndex = i;
			break;
		}
		checkEndOfArray = 0;
		++i;
	}
	if ((checkEndOfArray == 0) && (endIndex == -1))
	{
		endIndex = startIndex;
	}
	return endIndex;
}

int readNumberFromFile(FILE *inputData, int maxLength)
{
	char *bufferLength = new char[maxLength] {};
	if (!fgets(bufferLength, maxLength, inputData))
	{
		delete[] bufferLength;
		return maxLength * 10;
	}
	int number = charToInt(bufferLength, 0, maxLength);
	delete[] bufferLength;
	return number;
}

int readArrayOfNumbersFromFile(FILE *inputData, int maxLength, int intArray[], int length)
{
	char *bufferArray = new char[maxLength];
	if (!fgets(bufferArray, maxLength, inputData))
	{
		delete[] bufferArray;
		return maxLength * 10;
	}
	int i = 0;
	int startIndex = 0;
	int endIndex = findSpace(bufferArray, startIndex);
	while (endIndex != startIndex)
	{
		intArray[i] = charToInt(bufferArray, startIndex, endIndex);
		startIndex = endIndex + 1;
		endIndex = findSpace(bufferArray, startIndex);
		++i;
		if (i > length - 1)
		{
			return -(maxLength * 10);
		}
	}
	if (endIndex == startIndex)
	{
		intArray[i] = charToInt(bufferArray, startIndex, maxLength);
	}
	if (i < length - 1)
	{
		return maxLength * 10;
	}
	delete[] bufferArray;
	return 1;
}

void outputStr(char str[])
{
	int i = 0;
	while ((str[i] != '\0') && (str[i] != '\n'))
	{
		printf("%c", str[i]);
		++i;
	}
}

