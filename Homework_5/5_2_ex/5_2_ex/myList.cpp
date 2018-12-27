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

void addListEntry(List* list, int newValue)
{
	ListEntry* newEntry = new ListEntry{ newValue, nullptr };

	if (isEmptyList(list))   // пустой список
	{
		list->head = newEntry;
		newEntry->next = newEntry;
		return;
	}

	ListEntry* entry = list->head;
	if (entry->value > newValue)   // если место элемента сразу в голове списка
	{
		newEntry->next = list->head;
		ListEntry* entry = list->head;
		while (entry->next != list->head)
		{
			entry = entry->next;
		}
		entry->next = newEntry;
		list->head = newEntry;
		return;
	}

	while (entry->value <= newValue)
	{
		if (entry->next == list->head)   // если место элемента в конце списка
		{
			entry->next = newEntry;
			newEntry->next = list->head;
			break;
		}
		else if (entry->next->value > newValue)   //   если место элемента между рассматриваемым и следующим элементами
		{
			ListEntry* nextEntry = entry->next;
			entry->next = newEntry;
			newEntry->next = nextEntry;
			break;
		}
		else   // если можно опуститься вниз по списку
		{
			entry = entry->next;
		}
	}
}

bool makeOutputList(List* list, vector<int>& sequence)
{
	if (isEmptyList(list))
	{
		return false;
	}

	ListEntry* entry = list->head;
	while (entry->next != list->head)
	{
		sequence.push_back(entry->value);
		entry = entry->next;
	}
	sequence.push_back(entry->value);
	return true;
}

bool deleteListEntry(List* list, int deleteValue)
{
	if (isEmptyList(list))   // если список пуст
	{
		return false;
	}

	ListEntry* deleteEntry = list->head;

	if (deleteEntry->value == deleteValue)   // если искомый элемент сразу в голове списка
	{
		if (list->head == list->head->next)
		{
			delete deleteEntry;
			list->head = nullptr;
			return true;
		}

		list->head = deleteEntry->next;
		ListEntry* entry = list->head;
		while (entry->next != deleteEntry)
		{
			entry = entry->next;
		}
		entry->next = list->head;
		delete deleteEntry;
		return true;
	}

	if (deleteEntry->value > deleteValue)   // если в списке только большие элементы
	{
		return false;
	}

	while (deleteEntry->value < deleteValue)
	{
		if (deleteEntry->next == list->head)   //  если дошли до конца списка
		{
			return false;
		}
		else if (deleteEntry->next->value > deleteValue)   // если следующий элемент больше, а рассматриваемый - меньше искомого
		{
			return false;
		}
		else if (deleteEntry->next->value < deleteValue)   // если можно спуститься по списку
		{
			deleteEntry = deleteEntry->next;
		}
		else   // следующий элемент - искомый
		{
			if (deleteEntry->next->next == list->head)   // если искомый элемент - последний в списке
			{
				delete deleteEntry->next;
				deleteEntry->next = list->head;
				return true;
			}
			else   // если искомый элемент посреди списка
			{
				ListEntry* nextEntry = deleteEntry->next->next;
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
		deleteListEntry(list, list->head->value);
	}
	delete list;
}
