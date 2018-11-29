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
ListEntry* findListEntry(ListEntry*& previousEntry, std::string& findWord);

/// ��������� ������ � ������������� ������, �������� �������.
void addListEntry(ListEntry*& previousEntry, std::string& newWord);

/// ���������� � ������ ��� ���������� ������ (� ������������� �������).
void makeOutputList(ListEntry*& previousEntry, std::vector<HashTableEntry*>& sequence);

/// ���������� ������ �� ������ ������ � ������, ���� ������ �� ����,
/// � ���������� true, ����� ���������� false.
bool outputList(List* list, std::vector<HashTableEntry*>& sequence);

/// ������� ������ �� ������ � ���������� true, ���� ��� ��� ����,
/// ����� ���������� false (� ���������, ���� ������ ��� ����).
bool deleteListEntry(ListEntry*& previousEntry, std::string& deleteWord);

/// ������� ������.
void deleteList(List* list);

/// ���������� ����� ������
int sizeOfList(List* list);