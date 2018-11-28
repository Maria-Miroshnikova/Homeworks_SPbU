#include "myHashTable.h"
#include <string>
#include <vector>
#include <list>
#include <cmath>
#include <iostream>
#include <cctype>

using namespace std;

struct HashTableEntry;

struct HashTable;

HashTable* createHashTable(const int size)
{
	HashTable* hashTable = new HashTable{};
	hashTable->bucket.resize(size);
	return hashTable;
}

int hashFunction(string& str)
{
	const int prime = 7;
	int hash = 0;
	for (int i = 0; i < str.length(); ++i)
	{
		hash = hash * prime + (str[i] - '0');
	}
	return abs(hash);
}

HashTableEntry* findEntryHashTable(HashTable* hashTable, string& newWord)
{
	const int hash = hashFunction(newWord) % hashTable->bucket.size();
	if (hashTable->bucket[hash].empty())
	{
		return nullptr;
	}
	for (int i = 0; i < hashTable->bucket[hash].size(); ++i)
	{
		if (hashTable->bucket[hash][i].word == newWord)
		{
			return &hashTable->bucket[hash][i];
		}
	}
	return nullptr;
}

void addEntryHashTable(HashTable* hashTable, string& newWord)
{
	const int hash = hashFunction(newWord) % hashTable->bucket.size();
	if (!findEntryHashTable(hashTable, newWord))
	{
		hashTable->bucket[hash].push_back({ newWord, 1 });
	}
	else
	{
		++(findEntryHashTable(hashTable, newWord)->count);
	}
}

void computePropertiesHashTable(HashTable* hashTable, float& loadFactor, int& maxListLength, float& middleListLength)
{
	int listLengthSumm = 0;
	int countNotEmptyEntries = 0;
	for (int i = 0; i < hashTable->bucket.size(); ++i)
	{
		if (!hashTable->bucket[i].empty())
		{
			++countNotEmptyEntries;
			listLengthSumm += hashTable->bucket[i].size();
			if (hashTable->bucket[i].size() > maxListLength)
			{
				maxListLength = hashTable->bucket[i].size();
			}
		}
	}
	loadFactor = (countNotEmptyEntries * 1.0) / hashTable->bucket.size();
	if (!countNotEmptyEntries)
	{
		return;
	}
	middleListLength = (listLengthSumm * 1.0) / countNotEmptyEntries;
}