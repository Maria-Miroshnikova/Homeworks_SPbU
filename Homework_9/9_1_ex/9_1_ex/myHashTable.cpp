#include "myHashTable.h"
#include <string>
#include <vector>
#include <list>
#include <cmath>
#include <iostream>
#include <cctype>
#include "myList.h"

using namespace std;

struct HashTableEntry;

struct HashTable;

HashTable* createHashTable(const int size)
{
	HashTable* hashTable = new HashTable{};
	hashTable->bucket.resize(size);
	for (int i = 0; i < size; ++i)
	{
		hashTable->bucket[i] = createList();
	}
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

HashTableEntry* findEntryHashTable(HashTable* hashTable, string& findWord)
{
	const int hash = hashFunction(findWord) % hashTable->bucket.size();
	if (isEmptyList(hashTable->bucket[hash]))
	{
		return nullptr;
	}
	ListEntry* foundListEntry = findListEntry(hashTable->bucket[hash]->head, findWord);
	if (!foundListEntry)
	{
		return nullptr;
	}
	return foundListEntry->element;
}

void addEntryHashTable(HashTable* hashTable, string& newWord)
{
	const int hash = hashFunction(newWord) % hashTable->bucket.size();
	HashTableEntry* foundHashEntry = findEntryHashTable(hashTable, newWord);
	if (!foundHashEntry)
	{
		addListEntry(hashTable->bucket[hash]->head, newWord);
	}
	else
	{
		++(foundHashEntry->count);
	}
}

void computePropertiesHashTable(HashTable* hashTable, float& loadFactor, int& maxListLength, float& middleListLength)
{
	int listLengthSumm = 0;
	int countNotEmptyEntries = 0;
	for (int i = 0; i < hashTable->bucket.size(); ++i)
	{
		if (!isEmptyList(hashTable->bucket[i]))
		{
			++countNotEmptyEntries;
			int sizeTmp = sizeOfList(hashTable->bucket[i]);
			listLengthSumm += sizeTmp;
//			cout << endl << "size of bucket " << i << " is: " << sizeTmp << endl;
			if (sizeTmp > maxListLength)
			{
				maxListLength = sizeTmp;
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

void deleteHashTable(HashTable* hashTable)
{
	for (int i = 0; i < hashTable->bucket.size(); ++i)
	{
		deleteList(hashTable->bucket[i]);
	}
	delete hashTable;
}