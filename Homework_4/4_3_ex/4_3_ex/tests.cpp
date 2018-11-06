#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
#include "commandsPhoneBook.h"
#include "myUtilsForEntries.h"
#include "interface.h"
#include "myUtilsForStrings.h"

void tests()
{
	int indexTestPhoneBook = -1;
	FILE *testphonebook = fopen("testPhoneBook.txt", "r");
	assert(testphonebook);
	PhoneBookEntry *testPhoneBook = createPhoneBook(&indexTestPhoneBook, testphonebook);
	fclose(testphonebook);
	FILE *testData = fopen("testData.txt", "r");
	assert(testData);
	FILE *testAnswer = fopen("testAnswer.txt", "r");
	assert(testAnswer);

	while (!feof(testData))
	{
		// �������� ������ �� "testData.txt", ���������� � ������, �������� � �������� ������-����������
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
		

		// �������� �� "testAnswer.txt" ������ � �������������� �����, �������,
		// ��� ������ ������������ ����� ���� ����� - ��������� ��������� addEntry
		// �� ���������� ������ �� "testData.txt", � ��������� �� � checkAddEntry -
		// ����������� ������ addEntry
		char *bufferAddEntry = new char[maxLength] {};
		checkReading = fgets(bufferAddEntry, maxLength, testAnswer);
		if (!checkReading)
		{
			break;
		}
		assert(((bufferAddEntry[0] - '0') == (checkAddEntry)) && ((bufferAddEntry[1]) == ('\n')));
		delete[] bufferAddEntry;


		// �������� ������ �� "testAnswer", ���� �� ������� ������ ��� ����� �����
		// i-�� ������, ��������������� � ������ - ��������� i-�� ������ ������� �����������, ��������� ��
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
			assert(isSameStrs(answerEntry.name, testPhoneBook[i].name));
			assert(isSameStrs(answerEntry.phone, testPhoneBook[i].phone));
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