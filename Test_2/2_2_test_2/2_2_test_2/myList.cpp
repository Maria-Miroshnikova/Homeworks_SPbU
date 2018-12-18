#include "myList.h"
#include <vector>

using namespace std;

/// элемент списка, содержащий значение и указатели на предыдущий и следующий элементы
struct ListEntry
{
	int value;
	ListEntry* past;
	ListEntry* next;
};

/// указатель на начало списка
struct List
{
	ListEntry* head;
};

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
	int size = countSizeOfList(list);
	if (((position > 0) && (position > size)))
	{
		return false;
	}

	ListEntry* newEntry = new ListEntry{ newValue, nullptr, nullptr };

	if (position == 0)
	{
		if (isEmptyList(list))
		{
			list->head = newEntry;
			return true;
		}
		else
		{
			list->head->past = newEntry;
			newEntry->next = list->head;
			list->head = newEntry;
			return true;
		}

	}

	ListEntry* entry = list->head;
	int positionInList = 0;
	while (positionInList != position)
	{
		if (entry->next != nullptr)
		{
			entry = entry->next;
			++positionInList;
		}
		else  // прицепление в конец списка
		{
			entry->next = newEntry;
			newEntry->past = entry;
			return true;
		}
	}
	newEntry->next = entry;
	newEntry->past = entry->past;
	entry->past->next = newEntry;
	entry->past = newEntry;
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

	ListEntry* deleteEntry = list->head;

	if (position == 0)
	{
		list->head = list->head->next;
		if ((list->head != 0) && (list->head->next != nullptr))
		{
			list->head->next->past = nullptr;
		}
		delete deleteEntry;
		return true;
	}

	int positionInList = 0;
	while (positionInList != position)
	{
		deleteEntry = deleteEntry->next;
		++positionInList;
	}

	deleteEntry->past->next = deleteEntry->next;
	if (deleteEntry->next != nullptr)
	{
		deleteEntry->next->past = deleteEntry->past;
	}
	delete deleteEntry;
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