#include "workingWithData.h"
#include "set.h"
#include <fstream>
#include <iostream>
#include <string>

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

void addTimeTableEntry(Set* timeTable, int hourStart, int hourEnd)
{
	addSetElement(timeTable, hourStart);
	if (hourStart != hourEnd)
	{
		addSetElement(timeTable, hourEnd);
	}
}

void makeTimeTable(Set* timeTable, istream& dataFile, string& data)
{
	getDataFromFile(dataFile, data);
	if (!getDataFromFile)
	{
		return;
	}
	int hourStart = strtol(data.c_str(), nullptr, 10);
	data = "";

	getDataFromFile(dataFile, data);
	int minuteStart = strtol(data.c_str(), nullptr, 10);
	data = "";

	getDataFromFile(dataFile, data);
	int hourEnd = strtol(data.c_str(), nullptr, 10);
	data = "";

	getDataFromFile(dataFile, data);
	int minuteEnd = strtol(data.c_str(), nullptr, 10);
	data = "";

	addTimeTableEntry(timeTable, hourStart, hourEnd);
}

bool workingWithData()
{
	ifstream dataFile("data.txt", ios::in);
	if (!dataFile)
	{
		return false;
	}

	Set* timeTable = createSet();
	for (int i = 0; i < 24; ++i)
	{
		addSetElement(timeTable, i);
	}

	string data = "";

	while (!dataFile.eof())
	{
		makeTimeTable(timeTable, dataFile, data);
	}

	cout << endl << "The most popular hour is: " << findMaxSetElement(timeTable) << endl;

	deleteSet(timeTable);
	return true;
}