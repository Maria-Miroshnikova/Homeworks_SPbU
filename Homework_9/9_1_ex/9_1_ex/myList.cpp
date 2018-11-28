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

void addEntryList(ListEntry*& previousEntry, int newValue)
{
	if ((previousEntry == nullptr) || (previousEntry->value > newValue))
	{
		ListEntry* newEntry = new ListEntry{ newValue, nullptr };
		ListEntry* nextEntry = previousEntry;
		previousEntry = newEntry;
		newEntry->next = nextEntry;
	}
	else
	{
		addEntryList(previousEntry->next, newValue);
	}
}

void makeOutputList(ListEntry*& previousEntry, vector<int>& sequence)
{
	if (previousEntry == nullptr)
	{
		return;
	}
	else
	{
		sequence.push_back(previousEntry->value);
		makeOutputList(previousEntry->next, sequence);
	}
}

bool outputList(List* list, vector<int>& sequence)
{
	if (isEmptyList(list))
	{
		return false;
	}
	else
	{
		makeOutputList(list->head, sequence);
		return true;
	}
}

bool deleteEntryList(ListEntry*& previousEntry, int deleteValue)
{
	if ((previousEntry == nullptr) || (previousEntry->value > deleteValue))
	{
		return false;
	}
	else if (previousEntry->value < deleteValue)
	{
		deleteEntryList(previousEntry->next, deleteValue);
	}
	else
	{
		ListEntry* deleteEntry = previousEntry;
		previousEntry = previousEntry->next;
		delete deleteEntry;
		return true;
	}
}

void deleteList(List* list)
{
	while (list->head != nullptr)
	{
		deleteEntryList(list->head, list->head->value);
	}
	delete list;
}

void sizeList(ListEntry*& previousEntry, int& size)
{
	if (previousEntry == nullptr)
	{
		return;
	}
	else
	{
		++size;
		sizeList(previousEntry->next, size);
	}
}