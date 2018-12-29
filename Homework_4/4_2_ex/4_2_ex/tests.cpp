#define _CRT_SECURE_NO_WARNINGS
#include "tests.h"
#include <vector>
#include <fstream>
#include <string>
#include <cassert>
#include "myQuickSort.h"
#include "myUtils.h"
#include "myUtilsForFiles.h"

using namespace std;

void compareFind(vector<int>& sortArray, int answer)
{
	assert(findOftenElement(sortArray) == answer);
}

void compareSort(vector<int>& sortArray)
{
	quickSort(sortArray, 0, sortArray.size() - 1);
	for (int i = 0; i < sortArray.size() - 1; ++i)
	{
		assert(sortArray[i] <= sortArray[i + 1]);
	}
}

void tests()
{
	ifstream testDataFile("tests.txt", ios::in);
	assert(testDataFile);

	vector<int> testArray;
	string answer = "";

	while (!testDataFile.eof())
	{
		readArrayFromFile(testDataFile, testArray);

		readDataFromFile(answer, testDataFile);

		compareSort(testArray);
		compareFind(testArray, strtol(answer.c_str(), nullptr, 10));
		
		testArray.resize(0);
	}

	testDataFile.close();
}