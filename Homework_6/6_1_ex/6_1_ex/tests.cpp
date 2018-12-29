#include "tests.h"
#include <fstream>
#include <string>
#include <cassert>
#include "myStack.h"

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

void makeStackFromFile(Stack* testStack, int testAmountOfData, string& data, istream& testDataFile)
{
	for (int i = 0; i < testAmountOfData; ++i)
	{
		getDataFromFile(testDataFile, data);

		if (data == "*")
		{
			push(testStack, pop(testStack) * pop(testStack));
		}
		else if (data == "/")
		{
			int firsValue = pop(testStack);
			int secondValue = pop(testStack);
			push(testStack, secondValue / firsValue);
		}
		else if (data == "+")
		{
			push(testStack, pop(testStack) + pop(testStack));
		}
		else if (data == "-")
		{
			int firsValue = pop(testStack);
			int secondValue = pop(testStack);
			push(testStack, secondValue - firsValue);
		}

		else
		{
			push(testStack, strtol(data.c_str(), nullptr, 10));
		}

		data = "";
	}
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

		int testAmountOfData = strtol(data.c_str(), nullptr, 10);
		data = "";

		Stack* testStack = createStack();

		makeStackFromFile(testStack, testAmountOfData, data, testDataFile);

		getDataFromFile(testAnswerFile, answer);
		assert(strtol(answer.c_str(), nullptr, 10) == pop(testStack));

		answer = "";
		deleteStack(testStack);
	}

	testDataFile.close();
	testAnswerFile.close();
}