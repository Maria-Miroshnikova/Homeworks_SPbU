#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>
#include "myUtilsForFiles.h"

int main()
{
	FILE *inputData = fopen("f.txt", "r");
	if (!inputData)
	{
		fclose(inputData);
		printf("File 'f.txt' not found!\n");
		return 0;
	}
	FILE *compareNumber = fopen("g.txt", "r");
	if (!compareNumber)
	{
		fclose(compareNumber);
		printf("File 'g.txt' not found!\n");
		return 0;
	}
	const int maxLength = 100;
	int number = readNumberFromFile(compareNumber, maxLength);
	
	FILE *outputData = fopen("h.txt", "w");
	workingWithData(inputData, outputData, number);

	fclose(outputData);
	fclose(compareNumber);
	fclose(inputData);
	return 0;
}