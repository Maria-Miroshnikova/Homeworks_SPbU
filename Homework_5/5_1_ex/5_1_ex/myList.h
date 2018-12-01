#pragma once
#include <vector>

/// ������� ������, ���������� �������� � ��������� �� ��������� �������
struct ListEntry
{
	int value;
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
void addListEntry(List* list, int newValue);

/// ���������� ������ � ������, ���� ������ �� ����,
/// � ���������� true, ����� ���������� false.
bool makeOutputList(List* list, std::vector<int>& sequence);

/// ������� ������ �� ������ � ���������� true, ���� ��� ��� ����,
/// ����� ���������� false (� ���������, ���� ������ ��� ����)
bool deleteListEntry(List* list, int deleteValue);

/// ������� ������
void deleteList(List* list);