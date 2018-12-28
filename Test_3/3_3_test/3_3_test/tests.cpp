#include "tests.h"
#include "workingWithData.h"
#include "set.h"
#include <fstream>
#include <cassert>
#include <string>

using namespace std;

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
		getDataFromFile(testDataFile, data);
		if (!getDataFromFile)
		{
			break;
		}
		int countEntries = strtol(data.c_str(), nullptr, 10);

		Set* testTimeTable = createSet();
		for (int i = 0; i < 24; ++i)
		{
			addSetElement(testTimeTable, i);
		}

		for (int i = 0; i < countEntries; ++i)
		{
			makeTimeTable(testTimeTable, testDataFile, data);
		}

		getDataFromFile(testAnswerFile, answer);
		assert(findMaxSetElement(testTimeTable) == strtol(answer.c_str(), nullptr, 10));
		answer = "";

		deleteSet(testTimeTable);
	}

	testDataFile.close();
	testAnswerFile.close();
}