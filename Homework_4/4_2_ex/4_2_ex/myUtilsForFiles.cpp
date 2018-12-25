#include "myUtilsForFiles.h"
#include <fstream>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

void outputVector(vector<int>& vectorOut)
{
	for (int i = 0; i < vectorOut.size(); ++i)
	{
		cout << vectorOut[i] << " ";
	}
}

bool readDataFromFile(string& data, istream& file)
{
	if (file.eof())
	{
		return false;
	}
	file >> data;
	return true;
}

void readArrayFromFile(istream& dataFile, vector<int>& arrayForSort)
{
	string data = "";
	while (!dataFile.eof())
	{
		if (!readDataFromFile(data, dataFile))
		{
			break;
		}

		arrayForSort.push_back(strtol(data.c_str(), nullptr, 10));
		data = "";
	}
}