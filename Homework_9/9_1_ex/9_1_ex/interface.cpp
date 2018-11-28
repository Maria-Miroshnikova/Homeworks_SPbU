#include <iostream>
#include <fstream>
#include <string>
#include "myHashTable.h"

using namespace std;

void outputWordsFromHash(HashTable* hashTable, float loadFactor)
{
	if (!loadFactor)
	{
		cout << "The hash table is empty!" << endl;
		return;
	}
	for (int i = 0; i < hashTable->bucket.size(); ++i)
	{
		cout << endl << "bucket number - " << i << " :" << endl;
		if (!hashTable->bucket[i].empty())
		{
			for (int j = 0; j < hashTable->bucket[i].size(); ++j)
			{
				cout << hashTable->bucket[i][j].word << " ( " << hashTable->bucket[i][j].count << " )" << endl;
			}
		}
	}
}

int readDataFromFile(string& data, istream& file)
{
	if (file.eof())
	{
		return -1;
	}
	
	string simbols = " .,?!-/|\:;@#$%^&*()+=№<>`~{}[]";
	file >> data;

	for (int i = 0; i < data.length(); ++i)
	{
		bool symbol = false;

		if (i == data.length())
		{
			break;
		}
		for (int indexSimbol = 0; indexSimbol < simbols.length(); ++indexSimbol)
		{
			if (data[i] == simbols[indexSimbol])
			{
				data.erase(data.begin() + i);
				symbol = true;			
				--i;
				break;
			}
		}
		
		if (!symbol) // замена заглавной буквы на строчную
		{
			data[i] = tolower(data[i]);
		}
	}
	return data.length();
}

void workingWithData(ifstream& dataFile)
{	
	const int size = 10;
	HashTable* hashTable = createHashTable(size);
	string data = "";
	int count = 0;

	while (!dataFile.eof())
	{
		int checkReading = readDataFromFile(data, dataFile);
		if (checkReading == -1) // не получилось считать слово
		{
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
		++count;
	}
	float loadFactor = 0;
	int maxListLength = 0;
	float middleListLength = 0;
	computePropertiesHashTable(hashTable, loadFactor, maxListLength, middleListLength);
	outputWordsFromHash(hashTable, loadFactor);
	cout << endl << endl << "Properties:" << endl;
	cout << endl << "Load factor is: " << loadFactor << "." << endl;
	cout << endl << "Max length of list in bucket is: " << maxListLength << "." << endl;
	cout << endl << "Middle length of list in bucket is: " << middleListLength << "." << endl;

}