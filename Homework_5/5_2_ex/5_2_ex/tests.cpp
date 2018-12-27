#include "tests.h"
#include "workingWithData.h"
#include <fstream>
#include <string>
#include <cassert>

using namespace std;

bool getDataFromFile(istream& file, string& data)
{
	if (file.eof())
	{
		return false;
	}

	file >> data;
	return true;
}

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
		if (!getDataFromFile(testDataFile, data))
		{
			break;
		}

		int testCountMen = strtol(data.c_str(), nullptr, 10);
		data = "";

		getDataFromFile(testDataFile, data);
		int testNumberToKill = strtol(data.c_str(), nullptr, 10);
		data = "";

		getDataFromFile(testAnswerFile, answer);
		assert(findTheSurvivor(testCountMen, testNumberToKill) == strtol(answer.c_str(), nullptr, 10));
		answer = "";
	}

	testDataFile.close();
	testAnswerFile.close();
}