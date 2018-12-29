#include "myUtilsForStrings.h"
#include <string.h>

void readStr(char str[], char buffer[], int startIndex, int endIndex)
{
	int j = 0;
	for (int i = startIndex; i < endIndex; ++i)
	{
		if ((buffer[i] == '\0') || (buffer[i] == '\n'))
		{
			break;
		}
		else
		{
			str[j] = buffer[i];
			++j;
		}
	}
}