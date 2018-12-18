#include "workingWithData.h"
#include "myList.h"
#include <iostream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

void outputVector(vector<int>& vectorOut)
{
	for (int i = 0; i < vectorOut.size(); ++i)
	{
		cout << vectorOut[i] << " ";
	}
}

int readDataFromFile(istream& dataFile, string& data)
{
	dataFile >> data;
	if ((data != "\0") && (data != ""))
	{
		return strtol(data.c_str(), nullptr, 10);
	}
	return INT_MIN;
}

void makeList(List* list, istream& dataFile, string& data)
{
	int number = INT_MIN;
	while (!dataFile.eof())
	{
		number = readDataFromFile(dataFile, data);
		if (number == INT_MIN)
		{
			break;
		}
		addListEntry(list, number);

		string data = "";
	}
}

bool workingWithData(istream& dataFile)
{
	string data = "";
	List* list = createList();

	if (swapList(list))
	{
		vector<int> newList;
		makeOutputList(list, newList);
		cout << "The new list is:" << endl << endl;
		outputVector(newList);
		cout << endl;
		deleteList(list);
		return true;
	}

	else
	{
		deleteList(list);
		return false;
	}

}