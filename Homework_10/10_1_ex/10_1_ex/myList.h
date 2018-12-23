#pragma once
#include <vector>
#include "myGraph.h"

struct GraphNode;

struct WeightedEdge;

/// ������� ������, ���������� ��������� �� ������� � ��������� �� ��������� �������
struct ListEntry
{
	WeightedEdge* edge;
	ListEntry* next;
};

/// ��������� �� ������ ������, �������������� �� �������� ���� distance ���� edge ������ ��������
struct List
{
	ListEntry* head;
};

/// ���������, �������� �� ������ ������
bool isEmptyList(List* list);

/// ������� ������ ������ � ���������� ��������� �� ����
List* createList();

/// ��������� ������ � ������������� ������, �������� �������
void addListEntry(List* list, WeightedEdge* newElement);

/// ���������� ������ � ������, ���� ������ �� ����,
/// � ���������� true, ����� ���������� false.
bool makeOutputList(List* list, std::vector<WeightedEdge*>& sequence);

/// ������� ������ �� ������ � ���������� true, ���� ��� ��� ����,
/// ����� ���������� false (� ���������, ���� ������ ��� ����)
bool deleteListEntry(List* list, int deleteValue);

/// ������� ������
void deleteList(List* list);

/// ���������� ����� ������
int countSizeOfList(List* list);

/// ���� ��������� ������������� �������
int findMinNotConqueredNode(List* list, GraphNode** findNode);