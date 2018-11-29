#include "tests.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cassert>
#include "myHashTable.h"
#include "interface.h"

using namespace std;

bool readTestDataFromFileWithSpace(string& data, istream& file)
{
	if (file.eof())
	{
		data = "";
		return false;
	}
	getline(file, data);
	if (data == "\0")
	{
		data = "";
		getline(file, data);
	}
	return true;
}

bool readTestDataFromFile(string& data, istream& file)
{
	if (file.eof())
	{
		data = "";
		return false;
	}
	getline(file, data);
	return true;
};

void testingFile(string& testFileName, istream& testSizeFile, istream& testPropertiesFile, istream& testAnswerFile,
								string& size, string& data, string& answer, vector<HashTableEntry*>& listFromHashTable)
{
	bool firstMakingHash = true;
	int checkReading = readTestDataFromFile(size, testSizeFile);

	while (checkReading && (size != "\0"))
	{
		ifstream testDataFile(testFileName, ios::in);
		assert(testDataFile);

		HashTable* testHashTable = createHashTable(strtol(size.c_str(), nullptr, 10));
		makeHashTable(testDataFile, testHashTable, data);

		float testLoadFactor = 0;
		int testMaxListLength = 0;
		float testMiddleListLength = 0;
		computePropertiesHashTable(testHashTable, testLoadFactor, testMaxListLength, testMiddleListLength);

		// сравнение свойств таблицы с ожидаемыми
		readTestDataFromFileWithSpace(data, testPropertiesFile);
		assert(strtof(data.c_str(), nullptr) - testLoadFactor < (1e-6));
		data = "";

		readTestDataFromFile(data, testPropertiesFile);
		assert(strtol(data.c_str(), nullptr, 10) == testMaxListLength);
		data = "";

		readTestDataFromFile(data, testPropertiesFile);
		assert(strtof(data.c_str(), nullptr) - testMiddleListLength < (1e-6));
		data = "";

		// сравнение непустоты таблицы
		if (firstMakingHash)
		{
			readTestDataFromFileWithSpace(data, testAnswerFile);
			assert(testLoadFactor == strtol(data.c_str(), nullptr, 10));

			// сравнение содержимого непустой таблицы с ожидаемым, если сравнение производится впервые
			if (testLoadFactor)
			{
				for (int i = 0; i < strtol(size.c_str(), nullptr, 10); ++i)
				{
					if (!isEmptyList(testHashTable->bucket[i]))
					{
						makeOutputList(testHashTable->bucket[i]->head, listFromHashTable);
						int sizeList = sizeOfList(testHashTable->bucket[i]);
						for (int j = 0; j < sizeList; ++j)
						{
							readTestDataFromFileWithSpace(answer, testAnswerFile);
							assert(listFromHashTable[j]->word == answer);
							answer = "";
							readTestDataFromFile(answer, testAnswerFile);
							assert(listFromHashTable[j]->count == strtol(answer.c_str(), nullptr, 10));
							answer = "";
						}
						listFromHashTable.resize(0);
					}
				}
			}
			firstMakingHash = false;
		}
		data = "";
		size = "";
		deleteHashTable(testHashTable);
		testDataFile.close();
		checkReading = readTestDataFromFile(size, testSizeFile);
	}
}

void tests()
{
	ifstream testSizeFile("testSize.txt", ios::in);
	assert(testSizeFile);
	ifstream testAnswerFile("testAnswer.txt", ios::in);
	assert(testAnswerFile);
	ifstream testPropertiesFile("testProperties.txt", ios::in);
	assert(testPropertiesFile);

	string testFileName1 = "testData1.txt";
	string testFileName2 = "testData2.txt";
	string testFileName3 = "testData3.txt";

	string size = "";
	string data = "";
	string answer = "";
	vector<HashTableEntry*> listFromHashTable;

	testingFile(testFileName1, testSizeFile, testPropertiesFile, testAnswerFile, size, data, answer, listFromHashTable);
	testingFile(testFileName2, testSizeFile, testPropertiesFile, testAnswerFile, size, data, answer, listFromHashTable);
	testingFile(testFileName3, testSizeFile, testPropertiesFile, testAnswerFile, size, data, answer, listFromHashTable);

	testSizeFile.close();
	testAnswerFile.close();
	testPropertiesFile.close();
}