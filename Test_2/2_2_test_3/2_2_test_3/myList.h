#pragma once
#include <vector>

/// ������� ������, ���������� �������� � ��������� �� ��������� �������
struct ListEntry
{
	int value;
	ListEntry* next;
};

/// ��������� �� ������ ������ � ���������
struct List
{
	ListEntry* head;
};

/// ���������, �������� �� ������ ������
bool isEmptyList(List* list);

/// ������� ������ ������ � ���������� ��������� �� ����
List* createList();

/// ��������� ������ � ������ �� �������� �������
bool addListEntry(List* list, int newValue, int position);

/// ���������� ������ � ������, ���� ������ �� ����,
/// � ���������� true, ����� ���������� false.
bool makeOutputList(List* list, std::vector<int>& sequence);

/// ������� ������ �� ������ � �������� ������� � ���������� true, ���� ������� ���������,
/// ����� ���������� false (������ ����� ������� �����, ����)
bool deleteListEntry(List* list, int position);

/// ������� ������
void deleteList(List* list);