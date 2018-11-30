#include "myList.h"
#include <vector>

using namespace std;

List* createList()
{
	List *list = new List{ nullptr };
	return list;
}

bool isEmptyList(List* list)
{
	return (list->head == nullptr);
}

void addListEntry(List* list, int newValue) // добавляет в начало, как стэк
{
	if (isEmptyList(list))
	{
		ListEntry* newEntry = new ListEntry{ newValue, nullptr };
		list->head = newEntry;
		return;
	}
	ListEntry* nexEntry = list->head;
	ListEntry* newEntry = new ListEntry{ newValue, nexEntry };
	list->head = newEntry;
}

bool outputList(List* list, vector<int>& sequence)
{
	if (isEmptyList(list))
	{
		return false;
	}
	ListEntry* entry = list->head;
	while (entry != nullptr)
	{
		sequence.push_back(entry->value);
		entry = entry->next;
	}
}

bool deleteListEntry(ListEntry*& previousEntry, int deleteValue)
{
	if (previousEntry == nullptr)
	{
		return false;
	}
	if (previousEntry->value == deleteValue)
	{
		ListEntry* deleteEntry = previousEntry;
		previousEntry = previousEntry->next;
		delete deleteEntry;
		return true;
	}
	else
	{
		deleteListEntry(previousEntry->next, deleteValue);
	}
}

void deleteList(List* list)
{
	while (list->head != nullptr)
	{
		deleteListEntry(list->head, list->head->value);
	}
	delete list;
}

int sizeOfList(List* list)
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