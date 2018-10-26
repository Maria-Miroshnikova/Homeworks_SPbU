#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int findComment(char buffer[], int length)
{
	int countChars = 0;
	int startComment = 0;
	for (int i = 0; i < length; ++i)
	{
		if (buffer[i] == ';')
		{
			++startComment;
		}
		else
		{
			++countChars;
		}
	}
	if (startComment != 0)
	{
		if (countChars != 0)
		{
			return 2;
		}
		return 1;
	}
	return -1;
}

int main()
{
	FILE *inputData = fopen("inputData.txt", "r");
	if (!inputData)
	{
		printf("File - inputData.txt - not found!");
		return 1;
	}
	const int maxLengthWord = 100;
	const int maxLengthComment = 1000;
	while (!feof(inputData))
	{
		char *buffer = new char[maxLengthWord] {};
		const int checkingFscanf = fscanf(inputData, "%s", buffer);
		if (checkingFscanf < 0) {
			delete[] buffer;
			break;
		}
		if (findComment(buffer, maxLengthWord) > 0)
		{
			if (findComment(buffer, maxLengthWord) == 2)
			{
				printf("%s", buffer);
			}
			char *bufferRest = new char[maxLengthComment] {};
			fgets(bufferRest, maxLengthComment, inputData);
			printf("%s", bufferRest);
			delete[] bufferRest;
		}
		delete[] buffer;
	}
	fclose(inputData);
	return 0;
}