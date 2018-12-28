#include "myList.h"
#include <vector>
#include "myGraph.h"

using namespace std;

struct ListEntry;

struct List;

List* createList()
{
	List *list = new List{ nullptr };
	return list;
}

bool isEmptyList(List* list)
{
	return (list->head == nullptr);
}

void addListEntry(List* list, WeightedEdge* newElement)
{
	ListEntry* newEntry = new ListEntry{ newElement, nullptr };

	if (isEmptyList(list))   // ���� ������ ����
	{
		list->head = newEntry;
		return;
	}

	ListEntry* entry = list->head;
	if (entry->edge->endNode->label > newElement->endNode->label)   // ���� ����� �������� ����� � ������ ������
	{
		list->head = newEntry;
		newEntry->next = entry;
		return;
	}

	while (entry->edge->endNode->label <= newElement->endNode->label)
	{
		if (entry->next == nullptr)   // ���� ����� �������� � ����� ������
		{
			entry->next = newEntry;
			break;
		}
		else if (entry->next->edge->endNode->label > newElement->endNode->label)   //   ���� ����� �������� ����� ��������������� � ��������� ����������
		{
			ListEntry* nextEntry = entry->next;
			entry->next = newEntry;
			newEntry->next = nextEntry;
			break;
		}
		else   // ���� ����� ���������� ���� �� ������
		{
			entry = entry->next;
		}
	}
}

bool makeOutputList(List* list, vector<WeightedEdge*>& sequence)
{
	if (isEmptyList(list))
	{
		return false;
	}

	ListEntry* entry = list->head;
	while (entry != nullptr)
	{
		sequence.push_back(entry->edge);
		entry = entry->next;
	}
	return true;
}

bool deleteListEntry(List* list, int deleteValue)
{
	if (isEmptyList(list))   // ���� ������ ����
	{
		return false;
	}

	ListEntry* deleteEntry = list->head;

	if (deleteEntry->edge->endNode->label == deleteValue) // ���� ������� ������� ����� � ������ ������
	{
		list->head = deleteEntry->next;
		delete deleteEntry->edge;
		delete deleteEntry;
		return true;
	}

	if (deleteEntry->edge->endNode->label > deleteValue)   // ���� � ������ ������ ������� ��������
	{
		return false;
	}

	while (deleteEntry->edge->endNode->label < deleteValue)
	{
		if (deleteEntry->next == nullptr)   //  ���� ����� �� ����� ������
		{
			return false;
		}
		else if (deleteEntry->next->edge->endNode->label > deleteValue)   // ���� ��������� ������� ������, � ��������������� - ������ ��������
		{
			return false;
		}
		else if (deleteEntry->next->edge->endNode->label < deleteValue)   // ���� ����� ���������� �� ������
		{
			deleteEntry = deleteEntry->next;
		}
		else   // ��������� ������� - �������
		{
			if (deleteEntry->next->next == nullptr)   // ���� ������� ������� - ��������� � ������
			{
				delete deleteEntry->next->edge;
				delete deleteEntry->next;
				deleteEntry->next = nullptr;
				return true;
			}
			else   // ���� ������� ������� ������� ������
			{
				ListEntry* nextEntry = deleteEntry->next->next;
				delete deleteEntry->next->edge;
				delete deleteEntry->next;
				deleteEntry->next = nextEntry;
				return true;
			}
		}
	}
}

void deleteList(List* list)
{
	while (!isEmptyList(list))
	{
		deleteListEntry(list, list->head->edge->endNode->label);
	}
	delete list;
}

int countSizeOfList(List* list)
{
	int size = 0;
	ListEntry* entry = list->head;
	while (entry != nullptr)
	{
		++size;
		entry = entry->next;
	}
	return size;
}

bool findEdgeInList(GraphNode* node, int findEndNode)
{
	if (isEmptyList(node->connectedNodes))
	{
		return false;
	}

	ListEntry* entry = node->connectedNodes->head;
	while (entry != nullptr)
	{
		if (entry->edge->endNode->label == findEndNode)
		{
			return true;
		}
		entry = entry->next;
	}
	return false;
}