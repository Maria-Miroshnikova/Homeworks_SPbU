#pragma once
#include"myHashTable.h"
#include <fstream>
#include <vector>

/// ������� �� ����� ����� �� ���-������� � �� ����������, ���� ������� �������,
/// ����� ������� ��������� � ������� �������
void outputWordsFromHash(HashTable* hashTable, float loadFactor, std::vector<HashTableEntry*>& listForOutput);

/// ��������� ����� �� �����, ������� ��� �� ��������, ������ ���������
/// ����� �� �������� � ���������� ����� ����������� ����� (���� � �����
/// �� ���� ����, ���������� 0)
int readDataFromFile(std::string& data, std::istream& file);

/// ��������� ����� �� �����, ���������� �� �� ������� �� ��������
/// � ���������� � �������.
void makeHashTable(std::istream& dataFile, HashTable* hashTable, std::string& data);

/// ��������� ����� �� �����, �������� �� � �������, ���������� ������ �� ����� �������
void workingWithData(std::istream& dataFile);