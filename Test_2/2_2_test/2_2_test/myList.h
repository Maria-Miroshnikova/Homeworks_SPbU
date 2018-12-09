#pragma once
#include <vector>

/// ������� ������, ���������� �������� � ��������� �� ��������� �������.
struct ListEntry
{
	int value;
	ListEntry* next;
};

/// ��������� �� ������ ������.
struct List
{
	ListEntry* head;
};

/// ������� ������.
List* createList();

/// �������� ������ �� �������.
bool isEmptyList(List* list);

/// ��������� ������� � ������.
void addListEntry(List* list, int newValue);

/// ���� ������ ����, ���������� false, �����
/// ���������� � ������ �������� ������ � ���������� true.
bool outputList(List* list, std::vector<int>& sequence);

/// ���� ������� ���� � ������, ������� ��� � ���������� true, ����� ���������� false.
bool deleteListEntry(ListEntry*& previousEntry, int deleteValue);

/// ������� ������.
void deleteList(List* list);

/// ������� ����� ������.
int sizeOfList(List* list);