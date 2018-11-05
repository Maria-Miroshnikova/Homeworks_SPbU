#include "myUtilsForStrings.h"

bool isSameStrs(char str1[], char str2[])
{
	if ((lengthStr(str1) > lengthStr(str2)) || (lengthStr(str1) > lengthStr(str2)))
	{
		return false;
	}
	else
	{
		int i = 0;
		while ((str1[i] != '\0') && (str1[i] != '\n'))
		{
			if ((str2[i] == '\0') || (str2[i] == '\n'))
			{
				return false;
			}
			else if (str2[i] != str1[i])
			{
				return false;
			}
			else
			{
				++i;
			}
		}
		return true;
	}
}

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