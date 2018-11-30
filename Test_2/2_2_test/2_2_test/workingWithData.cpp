#include "workingWithData.h"
#include "myList.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool isSymmetricList(List* list)
{
	while (!isEmptyList(list))
	{
		if (sizeOfList(list) <= 1)
		{
			return true;
		}
		int deleteNumber = list->head->value;
		deleteListEntry(list->head, deleteNumber);
		if (!deleteListEntry(list->head, deleteNumber))
		{
			return false;
		}
	}
	return true; // пустой список
}

int readDataFromFile(istream& dataFile, string& data)
{
	dataFile >> data;
	return strtol(data.c_str(), nullptr, 10);
}

bool workingWithData(istream& dataFile)
{
	int number = 0;
	string data = "";
	List* list = createList();

	while (!dataFile.eof())
	{
		number = readDataFromFile(dataFile, data);
		addListEntry(list, number);

		string data = "";
	}

	int isSymmetic = isSymmetricList(list);
	
	deleteList(list);

	return isSymmetic;
}