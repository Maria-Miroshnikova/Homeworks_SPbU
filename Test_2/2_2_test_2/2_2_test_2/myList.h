#pragma once
#include <vector>

struct List;

/// ���������, �������� �� ������ ������
bool isEmptyList(List* list);

/// ������� ������ ������ � ���������� ��������� �� ����
List* createList();

/// ��������� ������� �� �������� ������� ������, ���� ������� �� ������ ����� ������, ������ ture,
/// ����� ���������� false
bool addListEntry(List* list, int newValue, int position);

/// ���������� ������ � ������, ���� ������ �� ����,
/// � ���������� true, ����� ���������� false.
bool makeOutputList(List* list, std::vector<int>& sequence);

/// ������� ������� � �������� ������� ������, ���� ������� �� ������ ����� ������ - 1,
/// ������ true, ����� ���������� false.
bool deleteListEntry(List* list, int position);

/// ������� ������
void deleteList(List* list);