#include <stdio.h>
#include "myUtilsForFiles.h"

int charToInt(char charArray[], int startArray, int endArray)
{
	int number = 0;
	int i = startArray;
	if (charArray[0] == '-')
	{
		i = startArray + 1;
	}
	while ((charArray[i] != '\0') && (i != endArray))
	{
		number = number * 10 + (charArray[i] - '0');
		++i;
	}
	if (charArray[0] == '-')
	{
		number = -number;
	}
	return number;
}