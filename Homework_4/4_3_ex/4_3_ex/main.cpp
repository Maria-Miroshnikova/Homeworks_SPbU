#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "myUtilsForEntries.h"
#include "myStructures.h"
#include "commandsPhoneBook.h"
#include "interface.h"
#include "myUtilsForFIles.h"
#include "tests.h"

int main()
{
	printf("Now program it testing...\n");
	tests();
	printf("Tests are OK!\n\n");
	int indexLastEntry = -1;
	FILE *phonebookFile = fopen("phonebook.txt", "r");
	PhoneBookEntry *phoneBook = createPhoneBook(&indexLastEntry, phonebookFile);
	fclose(phonebookFile);
	help();
	getCommand(phoneBook, &indexLastEntry);
	return 0;
}