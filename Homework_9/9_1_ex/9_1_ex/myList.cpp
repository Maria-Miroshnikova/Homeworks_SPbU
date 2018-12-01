#include "myList.h"
#include <vector>
#include <string>

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

ListEntry* findListEntry(List* list, string& findWord)
{
	if (isEmptyList(list))   // если список пуст
	{
		return false;
	}

	ListEntry* findEntry = list->head;

	if (findEntry->element->word == findWord) // если искомый элемент сразу в голове списка
	{
		return findEntry;
	}

	if (findEntry->element->word > findWord)   // если в списке только большие элементы
	{
		return nullptr;
	}

	while (findEntry->element->word < findWord)
	{
		if (findEntry->next == nullptr)   //  если дошли до конца списка
		{
			return nullptr;
		}
		else if (findEntry->next->element->word > findWord)   // если следующий элемент больше, а рассматриваемый - меньше искомого
		{
			return nullptr;
		}
		else if (findEntry->next->element->word < findWord)   // если можно спуститься по списку
		{
			findEntry = findEntry->next;
		}
		else   // следующий элемент - искомый
		{
			return findEntry->next;
		}
	}
}

void addListEntry(List* list, HashTableEntry* addEntry)
{
	ListEntry* newEntry = new ListEntry{ addEntry, nullptr };

	if (isEmptyList(list))   // если список пуст
	{
		list->head = newEntry;
		return;
	}

	ListEntry* entry = list->head;
	if (entry->element->word > addEntry->word)   // если место элемента сразу в голове списка
	{
		list->head = newEntry;
		newEntry->next = entry;
		return;
	}

	while (entry->element->word <= addEntry->word)
	{
		if (entry->next == nullptr)   // если место элемента в конце списка
		{
			entry->next = newEntry;
			break;
		}
		else if (entry->next->element->word > addEntry->word)   //   если место элемента между рассматриваемым и следующим элементами
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

bool makeOutputList(List* list, vector<HashTableEntry*>& sequence)
{
	if (isEmptyList(list))
	{
		return false;
	}

	ListEntry* entry = list->head;
	while (entry != nullptr)
	{
		sequence.push_back(entry->element);
		entry = entry->next;
	}
	return true;
}

bool deleteListEntry(List* list, string& deleteWord)
{
	if (isEmptyList(list))   // если список пуст
	{
		return false;
	}

	ListEntry* deleteEntry = list->head;

	if (deleteEntry->element->word == deleteWord) // если искомый элемент сразу в голове списка
	{
		list->head = deleteEntry->next;
		delete deleteEntry->element;
		delete deleteEntry;
		return true;
	}

	if (deleteEntry->element->word > deleteWord)   // если в списке только большие элементы
	{
		return false;
	}

	while (deleteEntry->element->word < deleteWord)
	{
		if (deleteEntry->next == nullptr)   //  если дошли до конца списка
		{
			return false;
		}
		else if (deleteEntry->next->element->word > deleteWord)   // если следующий элемент больше, а рассматриваемый - меньше искомого
		{
			return false;
		}
		else if (deleteEntry->next->element->word < deleteWord)   // если можно спуститься по списку
		{
			deleteEntry = deleteEntry->next;
		}
		else   // следующий элемент - искомый
		{
			if (deleteEntry->next->next == nullptr)   // если искомый элемент - последний в списке
			{
				delete deleteEntry->next->element;
				delete deleteEntry->next;
				deleteEntry->next = nullptr;
				return true;
			}
			else   // если искомый элемент посреди списка
			{
				ListEntry* nextEntry = deleteEntry->next->next;
				delete deleteEntry->next->element;
				delete deleteEntry->next;
				deleteEntry->next = nextEntry;
				return true;
			}
		}
	}
}

void deleteList(List* list)
{
	while (list->head != nullptr)
	{
		deleteListEntry(list, list->head->element->word);
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