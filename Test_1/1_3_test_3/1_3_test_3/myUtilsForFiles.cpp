#include <stdio.h>
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

int lengthStr(char str[])
{
	int length = 0;
	int i = 0;
	while (str[i] != '\0')
	{
		++length;
		++i;
	}
	return length;
}

void writeNumber(FILE *outputData, char bufferArray[], int startIndex, int endIndex, int maxLength)
{
	for (int i = startIndex; i <= endIndex; ++i)
	{
		char bufferChar[2] = { bufferArray[i] };
		fwrite(bufferChar, 1, sizeof(bufferChar), outputData);
	}
}

void workingWithData(FILE *inputData, FILE *outputData, int compareNumber)
{
	while (!feof(inputData))
	{
		const int maxLength = 10000;
		char *bufferArray = new char[maxLength];
		if (!fgets(bufferArray, maxLength, inputData))
		{
			delete[] bufferArray;
			break;
		}
		int i = 0;
		int startIndex = 0;
		int endIndex = findSpace(bufferArray, startIndex);
		while (endIndex != startIndex)
		{
			const int number = charToInt(bufferArray, startIndex, endIndex);
			if (number < compareNumber)
			{
				writeNumber(outputData, bufferArray, startIndex, endIndex, maxLength);
			}

			startIndex = endIndex + 1;
			endIndex = findSpace(bufferArray, startIndex);
			++i;
		}
		if (endIndex == startIndex)
		{
			const int number = charToInt(bufferArray, startIndex, maxLength);
			if (number < compareNumber)
			{
				writeNumber(outputData, bufferArray, startIndex, lengthStr(bufferArray) - 1, maxLength);
			}

		}
		delete[] bufferArray;
	}
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