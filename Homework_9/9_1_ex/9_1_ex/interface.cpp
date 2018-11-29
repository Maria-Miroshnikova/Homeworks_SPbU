#include <iostream>
#include <fstream>
#include <string>
#include "myHashTable.h"
#include "myList.h"

using namespace std;

void outputVector(vector<HashTableEntry*>& vectorOut)
{
	for (int i = 0; i < vectorOut.size(); ++i)
	{
		cout << vectorOut[i]->word << " ( " << vectorOut[i]->count << " )" << endl;
	}
}

void outputWordsFromHash(HashTable* hashTable, float loadFactor, vector<HashTableEntry*>& listForOutput)
{
	if (!loadFactor)
	{
		cout << "The hash table is empty!" << endl;
		return;
	}
	for (int i = 0; i < hashTable->bucket.size(); ++i)
	{
		// cout << endl << "bucket number - " << i << " :" << endl;
		if (outputList(hashTable->bucket[i], listForOutput))
		{
			outputVector(listForOutput);
		}
		listForOutput.resize(0);
	}
}

int readDataFromFile(string& data, istream& file)
{
	if (file.eof())
	{
		return -1;
	}
	
	file >> data;

	for (int i = 0; i < data.length(); ++i)
	{
		bool symbol = false;

		if (i == data.length())
		{
			break;
		}
		if ((!((data[i] >= '0') && (data[i] <= '9'))) && (!((data[i] >= 'A') && (data[i] <= 'Z'))) && (!((data[i] >= 'a') && (data[i] <= 'z'))))
		{
			data.erase(data.begin() + i);
			symbol = true;			
			--i;
		}
		
		if (!symbol) // замена заглавной буквы на строчную
		{
			data[i] = tolower(data[i]);
		}
	}
	return data.length();
}

void makeHashTable(istream& dataFile, HashTable* hashTable, string& data)
{
	while (!dataFile.eof())
	{
		int checkReading = readDataFromFile(data, dataFile);
		if (checkReading == -1) // не получилось считать слово
		{
			data = "";
			break;
		}
		if (checkReading == 0) // слово состоит только из символов
		{
			data = "";
		}
		else
		{
			addEntryHashTable(hashTable, data);
			data = "";
		}
	}
}

void workingWithData(istream& dataFile)
{	
	const int size = 10;
	HashTable* hashTable = createHashTable(size);
	string data = "";

	makeHashTable(dataFile, hashTable, data);

	float loadFactor = 0;
	int maxListLength = 0;
	float middleListLength = 0;
	computePropertiesHashTable(hashTable, loadFactor, maxListLength, middleListLength);

	vector<HashTableEntry*> listForOutput;
	outputWordsFromHash(hashTable, loadFactor, listForOutput);
	
	cout << endl << endl <<"---------------------------------------" << endl;
	cout << "Properties:" << endl;
	cout << endl << "Load factor is: " << loadFactor << "." << endl;
	cout << endl << "Max length of list in bucket is: " << maxListLength << "." << endl;
	cout << endl << "Middle length of list in bucket is: " << middleListLength << "." << endl;
	cout << "---------------------------------------" << endl;

	deleteHashTable(hashTable);
}