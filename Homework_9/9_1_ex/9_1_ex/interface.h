#pragma once
#include"myHashTable.h"
#include <fstream>

/// ������� �� ����� ����� �� ���-������� � �� ����������, ���� ������� �������,
/// ����� ������� ��������� � ������� �������
void outputWordsFromHash(HashTable* hashTable, float loadFactor);

/// ��������� ����� �� �����, ������� ��� �� ��������, ������ ���������
/// ����� �� �������� � ���������� ����� ����������� ����� (���� � �����
/// �� ���� ����, ���������� 0)
int readDataFromFile(std::string& data, std::istream& file);

/// ��������� ����� �� �����, �������� �� � �������, ���������� ������ �� ����� �������
void workingWithData(std::ifstream& dataFile);