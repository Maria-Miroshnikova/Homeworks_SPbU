#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "myUtilsForEntries.h"
#include "myStructures.h"
#include "interface.h"
#include "commandsPhoneBook.h"
#include "myUtilsForStrings.h"
#include <string.h>

int parseStrToPartOfEntry(char str[])
{
	int i = 0;
	while (str[i] != ':')
	{
		++i;
	}
	return i;
}

bool isCorrectEntry(char str[])
{
	int length = strlen(str);
	if (length <= 4)
	{
		return false;
	}
	for (int i = 0; i < length; ++i)
	{
		if ((str[i] == ':') && (i > 0) && (i < length - 2))
		{
			if ((str[i + 1] == ' ') && (i < (length - 2)))
			{
				if ((str[i - 1] >= 'A') && (str[i - 1] <= 'Z') || (str[i - 1] >= 'a') && (str[i - 1] <= 'z'))
				{
					if (str[i + 2] != ' ')
					{
						return true;
					}
				}
			}
		}
	}
	return false;
}

PhoneBookEntry createEntry(char buffer[], int maxLength)
{
	int indexSeparator = parseStrToPartOfEntry(buffer);
	char name[50]{};
	readStr(name, buffer, 0, indexSeparator);
	char phone[30]{};
	readStr(phone, buffer, indexSeparator + 2, maxLength);
	
	PhoneBookEntry newEntry{};
	
	strcpy(newEntry.name, name);
	strcpy(newEntry.phone, phone);

	return newEntry;
}

bool isEmptyEntry(PhoneBookEntry entry)
{
	return ((entry.name)[0] == '\0');
}

void swapEntries(PhoneBookEntry phonebook[], int index1, int index2)
{
	const PhoneBookEntry tmp = phonebook[index1];
	phonebook[index1] = phonebook[index2];
	phonebook[index2] = tmp;
}

int comparePartsOfNames(char str1[], char str2[], int indexStart)
{
	int i = indexStart;
	while ((str1[i] != ' ') && (str1[i] != '\0'))
	{
		if ((str2[i] == '\0') || (str2[i] == ' '))
		{
			return -3;
		}
		if (str1[i] > str2[i])
		{
			return -3;
		}
		if (str1[i] < str2[i])
		{
			return -2;
		}
		if (str1[i] == str2[i])
		{
			++i;
		}
	}
	if (str2[i] == '\0')
	{
		return -1;
	}
	if (str2[i] == ' ')
	{
		return i;
	}
	else
	{
		return -2;
	}
}

void selectionSortEntries(PhoneBookEntry phoneBook[], PhoneBookEntry newEntry, int indexLastEntry)
{
	int index = indexLastEntry + 1;
	phoneBook[index] = newEntry;
	for (int i = indexLastEntry; i >= 0; --i)
	{
		if (strcmp(phoneBook[i].name, newEntry.name) <= 0)
		{
			break;
		}
		else
		{
			swapEntries(phoneBook, i, index);
			--index;
		}
	}
}

int searchEntry(PhoneBookEntry phoneBook[], char str[], bool key, int indexLastEntry)
{
	int resultComparison = -1;
	for (int i = 0; i <= indexLastEntry; ++i)
	{
		if (key)
		{
			resultComparison = strcmp(phoneBook[i].name, str);
		}
		else
		{
			resultComparison = strcmp(phoneBook[i].phone, str);
		}
		if (resultComparison == 0)
		{
			return i;
		}
	}
	return -1;
}