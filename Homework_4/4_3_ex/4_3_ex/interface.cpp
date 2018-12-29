#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "interface.h"
#include "commandsPhoneBook.h"
#include "myStructures.h"
#include "myUtilsForEntries.h"
#include "myUtilsForStrings.h"
#include <string.h>

void outputName(PhoneBookEntry entry)
{
	printf("%s: ", entry.name);
}

void outputPhone(PhoneBookEntry entry)
{
	printf("%s", entry.phone);
}

void outputEntry(PhoneBookEntry entry)
{
	outputName(entry);
	outputPhone(entry);
}

void cleanTheArray(char arrayToClean[], const int maxLength)
{
	for (int i = 0; i < maxLength; ++i)
	{
		arrayToClean[i] = '\0';
	}
}

PhoneBookEntry getEntry(const int maxLength)
{
	printf("\nThe correct form for entry is: <name>: <phone>\n");
	printf("Please, enter the entry:\n");

	char *buffer = new char[maxLength] {};
	scanf("%[^\n]", buffer);

	while (!isCorrectEntry(buffer))
	{
		printf("\nSorry, your entry is incorrect!");
		cleanTheArray(buffer, maxLength);

		printf("\nThe correct form for entry is: <name>: <phone>\n");
		printf("Please, enter the entry:\n");
		
		scanf("%[^\n]", buffer);
		getc(stdin);
	}
	
	PhoneBookEntry newEntry = createEntry(buffer, maxLength);
	delete[] buffer;
	return newEntry;
}

void getCommand(PhoneBookEntry phoneBook[], int *indexLastEntry)
{
	char command0[2] = "0";
	char command1[2] = "1";
	char command2[2] = "2";
	char command3[2] = "3";
	char command4[2] = "4";
	char command5[2] = "5";
	char commandHELP[5] = "HELP";
	
	printf("\nPlease, enter the command: ");
	const int maxLength = 90;
	char command [maxLength] {};
	
	scanf("%s", command);

	while (strcmp(command, command0) != 0)
	{
		getc(stdin);
		if (strcmp(command, command1) == 0)
		{
			PhoneBookEntry newEntry = getEntry(maxLength);
			int checkAddEntry = addEntry(phoneBook, newEntry, indexLastEntry);
			if (checkAddEntry == 1)
			{
				printf("\nSorry, you can`t add new entry: (%s) is already in the Phone Book!\n", newEntry.name);
			}
			else if (checkAddEntry == 2)
			{
				printf("\nSorry, you can`t add new entry: (%s) is already in the Phone Book!\n", newEntry.phone);
			}
			else if (checkAddEntry == 3)
			{
				printf("\nSorry, you can`t add new entry: Phone Book is full!\n");
			}
		}
		else if (strcmp(command, command2) == 0)
		{
			printf("\nNow Phone Book is:\n\n");
			outputAllEntries(phoneBook);
		}
		else if (strcmp(command, command3) == 0)
		{
			printf("Please, enter the name: ");
			char buffer[maxLength] {};
			scanf("%[^\n]", buffer);
			int findResult = findPhone(phoneBook, buffer, *indexLastEntry);
			if (findResult == -1)
			{
				printf("\nSorry, there is no person with name (%s)!\n", buffer);
			}
			else
			{
				printf("%s has phone: %s\n", buffer, phoneBook[findResult].phone);
			}
		}
		else if (strcmp(command, command4) == 0)
		{
			printf("Please, enter the phone: ");
			char buffer[maxLength] {};
			scanf("%[^\n]", buffer);
			int findResult = findName(phoneBook, buffer, *indexLastEntry);
			if (findResult == -1)
			{
				printf("\nSorry, there is no person with phone (%s)!\n", buffer);
			}
			else
			{
				printf("%s is phone of: %s\n", buffer, phoneBook[findResult].name);
			}
		}
		else if (strcmp(command, command5) == 0)
		{
			savePhoneBook(phoneBook, *indexLastEntry);
			printf("\nPhone Book is saved to 'phonebook.txt'\n\n");
		}
		else if (strcmp(command, commandHELP) == 0)
		{
			help();
		}
		else
		{
			printf("\nSorry, your command is wrong!\n");
			printf("Enter HELP to see the list of commands.\n\n");
		}

		cleanTheArray(command, maxLength);
		printf("\nPlease, enter the command: ");
		scanf("%s", command);
	}

	deletePhoneBook(phoneBook);
}