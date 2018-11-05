#include <stdio.h>
#include "myUtilsForEntries.h"
#include "myStructures.h"
#include "interface.h"
#include "commandsPhoneBook.h"
#include "myUtilsForStrings.h"

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
	int length = lengthStr(str);
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
				if (((str[i - 1] > 64) && (str[i - 1] < 91)) || ((str[i - 1] > 96) && (str[i - 1] < 123)))
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
	char *name = new char[50]{};
	readStr(name, buffer, 0, indexSeparator);
	char *phone = new char[30]{};
	readStr(phone, buffer, indexSeparator + 2, maxLength);
	PhoneBookEntry newEntry{};
	for (int i = 0; i < lengthStr(name); ++i)
	{
		(newEntry.name)[i] = name[i];
	}
	for (int i = 0; i < lengthStr(phone); ++i)
	{
		(newEntry.phone)[i] = phone[i];
	}
	delete[] name;
	delete[] phone;
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

int compareStr(char str1[], char str2[])
{
	int resultComparison = comparePartsOfNames(str1, str2, 0);
	while (resultComparison >= 0)
	{
		resultComparison = comparePartsOfNames(str1, str2, resultComparison + 1);
	}
	return -resultComparison;
}

void selectionSortEntries(PhoneBookEntry phoneBook[], PhoneBookEntry newEntry, int indexLastEntry)
{
	int index = indexLastEntry + 1;
	phoneBook[index] = newEntry;
	for (int i = indexLastEntry; i >= 0; --i)
	{
		const int minEntryName = compareStr(phoneBook[i].name, newEntry.name);
		if (minEntryName < 3)
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
			resultComparison = compareStr(phoneBook[i].name, str);
		}
		else
		{
			resultComparison = compareStr(phoneBook[i].phone, str);
		}
		if (resultComparison == 1)
		{
			return i;
		}
	}
	return -1;
}
