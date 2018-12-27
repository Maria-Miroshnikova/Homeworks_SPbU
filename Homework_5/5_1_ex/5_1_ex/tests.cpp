#define _CRT_SECURE_NO_WARNINGS
#include "tests.h"
#include <fstream>
#include <vector>
#include <string>
#include <cassert>
#include "myList.h"

using namespace std;

void readDataFromFile(string& data, istream& file)
{
	getline(file, data);
	if (data == "\0")
	{
		data = "";
		getline(file, data);
	}
}

void tests()
{
	ifstream testDataFile("testData.txt", ios::in);
	assert(testDataFile);
	ifstream testCommandFile("testCommand.txt", ios::in);
	assert(testCommandFile);
	ifstream testAnswerFile("testAnswer.txt", ios::in);
	assert(testAnswerFile);

	List* testList = createList();
	string command = "";
	string data = "";
	string answer = "";
	vector<int> sequence;
	vector<int> sequenceFromFile;

	while (!testCommandFile.eof())
	{
		readDataFromFile(command, testCommandFile);

		if (command == "1")
		{
			readDataFromFile(data, testDataFile);
			while ((data != "\0") && (data != "\n"))
			{
				addListEntry(testList, strtol(data.c_str(), nullptr, 10));
				data = "";
				getline(testDataFile, data);
			}
			data = "";
		}
		else if (command == "2")
		{
			readDataFromFile(data, testDataFile);
			readDataFromFile(answer, testAnswerFile);
			while ((data != "\0") && (data != "\n"))
			{
				assert(deleteListEntry(testList, strtol(data.c_str(), nullptr, 10)) == strtol(answer.c_str(), nullptr, 10));

				data = "";
				answer = "";
				getline(testDataFile, data);
				getline(testAnswerFile, answer);
			}
			data = "";
			answer = "";
		}
		else if (command == "3")
		{
			readDataFromFile(answer, testAnswerFile);
			assert(makeOutputList(testList, sequence) == strtol(answer.c_str(), nullptr, 10));

			if (strtol(answer.c_str(), nullptr, 10))
			{
				answer = "";
				readDataFromFile(answer, testAnswerFile);
				char *answerChar = new char[strlen(answer.c_str()) + 1]{};
				strcpy(answerChar, answer.c_str());
				char *space = strtok(answerChar, " ");
				while (space != NULL)
				{
					sequenceFromFile.push_back(strtol(space, nullptr, 10));
					space = strtok(NULL, " ");
				}
				assert(sequence == sequenceFromFile);
				delete[] answerChar;
			}
			sequence.resize(0);
			sequenceFromFile.resize(0);
			answer = "";
		}
		command = "";
	}
	deleteList(testList);
	testDataFile.close();
	testCommandFile.close();
	testAnswerFile.close();
}