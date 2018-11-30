#define _CRT_SECURE_NO_WARNINGS
#include "tests.h"
#include "myList.h"
#include "workingWithData.h"
#include <fstream>
#include <iostream>
#include <cassert>
#include <string>

using namespace std;

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

void tests()
{
	ifstream testDataFile("testData.txt", ios::in);
	assert(testDataFile);

	ifstream testAnswerFile("testAnswer.txt", ios::in);
	assert(testAnswerFile);

	string data = "";
	string answer = "";

	while (!testDataFile.eof())
	{
		List* testList = createList();

		readTestDataFromFile(data, testDataFile);

		char *dataChar = new char[strlen(data.c_str()) + 1]{};
		strcpy(dataChar, data.c_str());
		char *space = strtok(dataChar, " ");
		while (space != NULL)
		{
			addListEntry(testList, strtol(space, nullptr, 10));
			space = strtok(NULL, " ");
		}

		readTestDataFromFile(answer, testAnswerFile);

		assert(isSymmetricList(testList) == strtol(answer.c_str(), nullptr, 10));

		data = "";
		answer = "";
		deleteList(testList);
	}

	testDataFile.close();
	testAnswerFile.close();
}