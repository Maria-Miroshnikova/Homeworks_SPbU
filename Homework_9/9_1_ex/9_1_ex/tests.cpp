#include "tests.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cassert>

using namespace std;

/*bool readDataFromFile(string& data, istream& file)
{
	getline(file, data);
	while (data == "\0")
	{
		if (file.eof())
		{
			return false;
		}
		data = "";
		getline(file, data);
	}
	return true;
}*/

/*void tests()
{
	ifstream testDataFile("testData.txt", ios::in);
	assert(testDataFile);
	
	string testData = "";

	while (!testDataFile.eof())
	{
		if (!readDataFromFile(testData, testDataFile))
		{
			break;
		}
		
		// parse;
		// addHashTable;
	}

	testDataFile.close();

	ifstream testAnswerFile("testAnswer.txt", ios::in);
	assert(testAnswerFile);

	string testCount = "";

	while (!testAnswerFile.eof())
	{
		if (!readDataFromFile(testData, testAnswerFile))
		{
			break;
		}
		readDataFromFile(testCount, testAnswerFile);

		/*if ((!findHashTable(testData, 0)) || (findHashTable(testData, 1) != testCount))
		{
			cout << "now: " << testData << " " << testCount << endl;
			cout << "original: " << findHashTable(testData, 1) << endl;
		}*/
/*	}

	testAnswerFile.close();
}*/