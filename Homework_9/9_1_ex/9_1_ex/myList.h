#pragma once
#include <vector>
#include <string>
#include "myHashTable.h"

struct HashTableEntry;

/// ���������, �������������� ������� ������, ���������� ������� ���-�������
/// � ��������� �� ��������� ������� ������.
struct ListEntry
{
	HashTableEntry* element;
	ListEntry* next;
};

/// ���������, ���������� ��������� �� ������ ������.
struct List
{
	ListEntry* head;
};

/// ���������, �������� �� ������ ������.
bool isEmptyList(List* list);

/// ������� ������ ������ � ���������� ��������� �� ����.
List* createList();

/// ���������� ��������� �� ������� ������, � ������� ��������
/// ����� �� �����, ����� ���������� ������� ���������.
ListEntry* findListEntry(List* list, std::string& findWord);

/// ��������� ������ � ������������� ������, �������� �������.
void addListEntry(List* list, HashTableEntry* addEntry);

/// ���������� ������ � ������, ���� ������ �� ����,
/// � ���������� true, ����� ���������� false.
bool makeOutputList(List* list, std::vector<HashTableEntry*>& sequence);

/// ������� ������ �� ������ � ���������� true, ���� ��� ��� ����,
/// ����� ���������� false (� ���������, ���� ������ ��� ����).
bool deleteListEntry(List* list, std::string& deleteWord);

/// ������� ������.
void deleteList(List* list);

/// ���������� ����� ������
int countSizeOfList(List* list);