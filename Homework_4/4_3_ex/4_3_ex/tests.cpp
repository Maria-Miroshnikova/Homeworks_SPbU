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
		// ń÷čňűâŕţ ńňđîęó čç "testData.txt", ďđĺîáđŕçóţ â çŕďčńü, äîáŕâë˙ţ â ňĺńňîâűé ěŕńńčâ-ńďđŕâî÷íčę
		const int maxLength = 90;
		char *bufferEntry = new char[maxLength] {};
		char *checkReading = fgets(bufferEntry, maxLength, testData);
		if (!checkReading)
		{
			delete[] bufferEntry;
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


		// ń÷čňűâŕţ čç "testAnswer.txt" ńňđîęó â îäíîńčěâîëüíűé áóôĺđ, ďîëŕăŕ˙,
		// ÷ňî ńňđîęŕ ďđĺäńňŕâë˙ĺň ńîáîé îäíó öčôđó - îćčäŕĺěűé đĺçóëüňŕň addEntry
		// îň äîáŕâëĺíč˙ ńňđîęč čç "testData.txt", č ńđŕâíčâŕţ ĺĺ ń checkAddEntry -
		// đĺçóëüňŕňîě đŕáîňű addEntry
		char *bufferAddEntry = new char[maxLength] {};
		checkReading = fgets(bufferAddEntry, maxLength, testAnswer);
		if (!checkReading)
		{
			delete[] bufferAddEntry;
			break;
		}
		assert(((bufferAddEntry[0] - '0') == (checkAddEntry)) && ((bufferAddEntry[1]) == ('\n')));
		delete[] bufferAddEntry;


		// ń÷čňűâŕţ ńňđîęč čç "testAnswer", ďîęŕ íĺ âńňđĺ÷ó ďóńňóţ čëč ęîíĺö ôŕéëŕ
		// i-ŕ˙ ńňđîęŕ, ďđĺîáđŕçîâŕííŕ˙ â çŕďčńü - îćčäŕĺěŕ˙ i-ŕ˙ çŕďčńü ěŕńńčâŕ ńďđŕâî÷íčęŕ, ńđŕâíčâŕţ čő
		char *bufferAnswer = new char[maxLength] {};
		checkReading = fgets(bufferAnswer, maxLength, testAnswer);
		if (!checkReading)
		{
			delete[] bufferAnswer;
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
