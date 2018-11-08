#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "myUtilsForFIles.h"
#include "myStructures.h"
#include "myUtilsForEntries.h"
#include "commandsPhoneBook.h"
#include "myUtilsForStrings.h"

void outputFile(FILE *file)
{
	while (!feof(file))
	{
		const int maxLength = 1000;
		char *buffer = new char[maxLength] {};
		if (fgets(buffer, maxLength, file))
		{
			printf("%s", buffer);
		}
		else
		{
			delete[] buffer;
			break;
		}
		delete[] buffer;
	}
	printf("\n");
}

void saveEntry(PhoneBookEntry entry, FILE *phonebook)
{
	fwrite(entry.name, sizeof(char), lengthStr(entry.name), phonebook);
	fwrite(": ", sizeof(char), 2, phonebook);
	fwrite(entry.phone, sizeof(char), lengthStr(entry.phone), phonebook);
	fwrite("\n", sizeof(char), 1, phonebook);
}

void readStartPhoneBook(PhoneBookEntry phoneBook[], int *indexLastEntry, FILE *phonebook)
{
	if (!phonebook)
	{
		return;
	}
	while (!feof(phonebook))
	{
		const int maxLength = 90;
		char *buffer = new char[maxLength] {};
		char *checkReading = fgets(buffer, maxLength, phonebook);
		if (!checkReading)
		{
			delete[] buffer;
			break;
		}
		addEntry(phoneBook, createEntry(buffer, maxLength), indexLastEntry);
		delete[] buffer;
	}
}