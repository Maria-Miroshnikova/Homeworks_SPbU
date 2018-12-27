#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
#include "commandsPhoneBook.h"
#include "myUtilsForEntries.h"
#include "interface.h"
#include "myUtilsForStrings.h"
#include <string.h>

void tests()
{
	int indexTestPhoneBook = -1;
	FILE *testphonebookFile = fopen("testPhoneBook.txt", "r");
	assert(testphonebookFile);
	PhoneBookEntry *testPhoneBook = createPhoneBook(&indexTestPhoneBook, testphonebookFile);
	fclose(testphonebookFile);
	FILE *testData = fopen("testData.txt", "r");
	assert(testData);
	FILE *testAnswer = fopen("testAnswer.txt", "r");
	assert(testAnswer);

	while (!feof(testData))
	{
		// считываю строку из "testData.txt", преобразую в запись, добавляю в тестовый массив-справочник
		const int maxLength = 90;
		char *bufferEntry = new char[maxLength] {};
		char *checkReading = fgets(bufferEntry, maxLength, testData);
		if (!checkReading)
		{
			break;
		}
		int checkAddEntry = -1;
		if (!isCorrectEntry(bufferEntry))
		{
			checkAddEntry = 3;
		}
		else
		{
			PhoneBookEntry newEntry = createEntry(bufferEntry, maxLength);
			checkAddEntry = addEntry(testPhoneBook, newEntry, &indexTestPhoneBook);
		}
		delete[] bufferEntry;


		// считываю из "testAnswer.txt" строку в односимвольный буфер, полагая,
		// что строка представляет собой одну цифру - ожидаемый результат addEntry
		// от добавления строки из "testData.txt", и сравниваю ее с checkAddEntry -
		// результатом работы addEntry
		char *bufferAddEntry = new char[maxLength] {};
		checkReading = fgets(bufferAddEntry, maxLength, testAnswer);
		if (!checkReading)
		{
			break;
		}
		assert(((bufferAddEntry[0] - '0') == (checkAddEntry)) && ((bufferAddEntry[1]) == ('\n')));
		delete[] bufferAddEntry;


		// считываю строки из "testAnswer", пока не встречу пустую или конец файла
		// i-ая строка, преобразованная в запись - ожидаемая i-ая запись массива справочника, сравниваю их
		char *bufferAnswer = new char[maxLength] {};
		checkReading = fgets(bufferAnswer, maxLength, testAnswer);
		if (!checkReading)
		{
			break;
		}
		int i = 0;
		while ((bufferAnswer[0] != '\n') && (!feof(testAnswer)))
		{
			PhoneBookEntry answerEntry = createEntry(bufferAnswer, maxLength);
			assert(strcmp(answerEntry.name, testPhoneBook[i].name) == 0);
			assert(strcmp(answerEntry.phone, testPhoneBook[i].phone) == 0);
			++i;
			checkReading = fgets(bufferAnswer, maxLength, testAnswer);
			if (!checkReading)
			{
				break;
			}
			answerEntry = {};
		}
		delete[] bufferAnswer;
	}
	fclose(testData);
	fclose(testAnswer);
	delete[] testPhoneBook;
}
