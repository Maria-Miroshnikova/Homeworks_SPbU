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


bool addListEntry(List* list, int newValue, int position)
{
	if ((position < 0) || (position > countSizeOfList(list)))
	{
		return false;
	}

	ListEntry* newEntry = new ListEntry{ newValue, nullptr };

	if (position == 0)
	{
		if (isEmptyList(list))
		{
			list->head = newEntry;
			return true;
		}
		else
		{
			ListEntry* nextEntry = list->head;
			list->head = newEntry;
			newEntry->next = nextEntry;
			return true;
		}

	}

	ListEntry* entry = list->head;
	int positionInList = 0;
	while (positionInList != position - 1)   // спуск по списку
	{
		entry = entry->next;
		++positionInList;
	}
	if (entry->next == nullptr)   // прицепление в конец
	{
		entry->next = newEntry;
	}
	else   // прицепление внутри списка
	{
		ListEntry* nextEntry = entry->next;
		entry->next = newEntry;
		newEntry->next = nextEntry;
	}
	return true;
}

bool makeOutputList(List* list, vector<int>& sequence)
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
	return true;
}

bool deleteListEntry(List* list, int position)
{
	if ((isEmptyList(list)) || (position > countSizeOfList(list) - 1))
	{
		return false;
	}

	if (position == 0)
	{
		ListEntry* nextEntry = list->head->next;
		delete list->head;
		list->head = nextEntry;
		return true;
	}

	ListEntry* deleteEntry = list->head;
	int positionInList = 0;
	while (positionInList != position - 1)
	{
		deleteEntry = deleteEntry->next;
		++positionInList;
	}

	ListEntry* nextEntry = deleteEntry->next->next;
	delete deleteEntry->next;
	deleteEntry->next = nextEntry;
	return true;
}

void deleteList(List* list)
{
	while (!isEmptyList(list))
	{
		deleteListEntry(list, 0);
	}
	delete list;
}