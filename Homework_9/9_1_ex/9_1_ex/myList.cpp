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

ListEntry* findListEntry(ListEntry*& previousEntry, string& findWord)
{
	if ((previousEntry == nullptr) || (previousEntry->element->word > findWord))
	{
		return nullptr;
	}
	else if (previousEntry->element->word < findWord)
	{
		return findListEntry(previousEntry->next, findWord);
	}
	else
	{
		return previousEntry;
	}
}

void addListEntry(ListEntry*& previousEntry, string& newWord)
{
	if ((previousEntry == nullptr) || ( previousEntry->element->word > newWord))
	{
		HashTableEntry* newElement = new HashTableEntry { newWord, 1 };
		ListEntry* newEntry = new ListEntry { newElement, nullptr };
		ListEntry* nextEntry = previousEntry;
		previousEntry = newEntry;
		newEntry->next = nextEntry;
	}
	else
	{
		addListEntry(previousEntry->next, newWord);
	}
}

void makeOutputList(ListEntry*& previousEntry, vector<HashTableEntry*>& sequence)
{
	if (previousEntry == nullptr)
	{
		return;
	}
	else
	{
		sequence.push_back(previousEntry->element);
		makeOutputList(previousEntry->next, sequence);
	}
}

bool outputList(List* list, vector<HashTableEntry*>& sequence)
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

bool deleteListEntry(ListEntry*& previousEntry, string& deleteWord)
{
	if ((previousEntry == nullptr) || (previousEntry->element->word > deleteWord))
	{
		return false;
	}
	else if (previousEntry->element->word < deleteWord)
	{
		return deleteListEntry(previousEntry->next, deleteWord);
	}
	else
	{
		ListEntry* deleteEntry = previousEntry;
		HashTableEntry* deleteElement = deleteEntry->element;
		previousEntry = previousEntry->next;
		delete deleteElement;
		delete deleteEntry;
		return true;
	}
}

void deleteList(List* list)
{
	while (list->head != nullptr)
	{
		deleteListEntry(list->head, list->head->element->word);
	}
	delete list;
}

void countSizeOfList(ListEntry*& previousEntry, int& size)
{
	if (previousEntry == nullptr)
	{
		return;
	}
	else
	{
		++size;
		countSizeOfList(previousEntry->next, size);
	}
}

int sizeOfList(List* list)
{
	int size = 0;
	countSizeOfList(list->head, size);
	return size;
}