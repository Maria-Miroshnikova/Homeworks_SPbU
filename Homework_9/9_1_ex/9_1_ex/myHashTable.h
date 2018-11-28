#pragma once
#include <vector>
#include <string>

/// ���������, ���������� � ���� ����� � ��� ��������� � �����
struct HashTableEntry
{
	std::string word;
	int count;
};

/// ���������, ���������� ��������� �� ������, ���������� � ���� ������ ����
/// � �����, ������ ������� ��������������� ������ �������
struct HashTable
{
	std::vector<std::vector<HashTableEntry>> bucket;
};

/// ������� ������� ��������� ������� � ���������� ��������� �� ���.
HashTable* createHashTable(const int size);

/// ���� ����� � ������� � ���������� ��������� �� ����,
/// ����� ���������� ������� ���������.
HashTableEntry* findEntryHashTable(HashTable* hashTable, std::string& newWord);

/// ��������� ����� � ���-�������, ���� ��� ��� ���, ����� �����������
/// ������� ��������� ����� ����� �� �������.
void addEntryHashTable(HashTable* hashTable, std::string& newWord);

/// ������� ����������� ���������� �������, ������������ � ����������� ����� � �������� ������
/// � ������� ���������� ������� ���������� ��� ������ �� �������������.
void computePropertiesHashTable(HashTable* hashTable, float& loadFactor, int& maxListLength, float& middleListLength);