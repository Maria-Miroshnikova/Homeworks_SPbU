#pragma once
#include <vector>
#include <string>
#include "myHashTable.h"

/// ������� ������, ���������� �������� � ��������� �� ��������� �������
struct ListEntry
{
	string word;

	ListEntry* next;
};

/// ��������� �� ������ ������
struct List
{
	ListEntry* head;
};

/// ���������, �������� �� ������ ������
bool isEmptyList(List* list);

/// ������� ������ ������ � ���������� ��������� �� ����
List* createList();

/// ��������� ������ � ������������� ������, �������� �������
void addEntryList(ListEntry*& previousEntry, int newValue);

/// ���������� � ������ ��� ���������� ������ (� ������������� �������)
void makeOutputList(ListEntry*& previousEntry, std::vector<int>& sequence);

/// ���������� ������ �� ������ ������ � ������, ���� ������ �� ����,
/// � ���������� true, ����� ���������� false.
bool outputList(List* list, std::vector<int>& sequence);

/// ������� ������ �� ������ � ���������� true, ���� ��� ��� ����,
/// ����� ���������� false (� ���������, ���� ������ ��� ����)
bool deleteEntryList(ListEntry*& previousEntry, int deleteValue);

/// ������� ������
void deleteList(List* list);

/// ������� ����� ������ � ������� ���������� ������� ���������� ��� ������ �� �������������.
void sizeList(ListEntry*& previousEntry, int& size);