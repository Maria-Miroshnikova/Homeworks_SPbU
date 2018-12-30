#include "tests.h"
#include "tree.h"
#include "workingWithData.h"
#include <string>
#include <fstream>
#include <cassert>

using namespace std;

bool getLineFromFile(istream& file, string& data)
{
	if (!getline(file, data))
	{
		return false;
	}
	if (data == "\0")
	{
		getline(file, data);
	}
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
		if (!getLineFromFile(testDataFile, data))
		{
			break;
		}

		Tree* testTree = createTree();
		makeExpressionTree(testTree, data);

		testAnswerFile >> answer;

		assert(countExpression(testTree) == atoi(answer.c_str()));

		deleteTree(testTree);
		data = "";
		answer = "";
	}

	testDataFile.close();
	testAnswerFile.close();
}