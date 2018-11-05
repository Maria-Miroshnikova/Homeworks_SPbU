#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "commandsPhoneBook.h"
#include "myStructures.h"
#include "myUtilsForEntries.h"
#include "myUtilsForFIles.h"
#include "interface.h"

void deletePhoneBook(PhoneBookEntry phoneBook[])
{
	delete[] phoneBook;
}

void help()
{
	FILE *help = fopen("HELP.txt", "r");
	printf("\n");
	outputFile(help);
	printf("\n");
	fclose(help);
}

void outputAllEntries(PhoneBookEntry phoneBook[])
{
	int i = 0;
	while (!isEmptyEntry(phoneBook[i]))
	{
		outputEntry(phoneBook[i]);
		printf("\n");
		++i;
	}
	printf("\n");
}

int addEntry(PhoneBookEntry phoneBook[], PhoneBookEntry newEntry, int *indexLastEntry)
{
	if (searchEntry(phoneBook, newEntry.name, true, *indexLastEntry) != -1)
	{
		return 1;
	}
	else
	{
		if (searchEntry(phoneBook, newEntry.phone, false, *indexLastEntry) != -1)
		{
			return 2;
		}
		else
		{
			if (*indexLastEntry == 100)
			{
				return 3;
			}
			else
			{
				selectionSortEntries(phoneBook, newEntry, *indexLastEntry);
				++(*indexLastEntry);
				return 0;
			}
		}
	}
}

int findPhone(PhoneBookEntry phoneBook[], char name[], int indexLasrEntry)
{
	return searchEntry(phoneBook, name, true, indexLasrEntry);
}

int findName(PhoneBookEntry phoneBook[], char phone[], int indexLasrEntry)
{
	return searchEntry(phoneBook, phone, false, indexLasrEntry);
}

void savePhoneBook(PhoneBookEntry phoneBook[], int indexLastEntry)
{
	FILE *phonebook = fopen("phonebook.txt", "w");
	for (int i = 0; i <= indexLastEntry; ++i)
	{
		saveEntry(phoneBook[i], phonebook);
	}
	fclose(phonebook);
}

PhoneBookEntry *createPhoneBook(int *indexLastEntry, FILE *phonebook)
{
	int maxLength = 100;
	PhoneBookEntry *phoneBook = new PhoneBookEntry[maxLength]{};
	readStartPhoneBook(phoneBook, indexLastEntry, phonebook);
	return phoneBook;
}