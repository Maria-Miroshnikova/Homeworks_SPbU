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
	if (isEmptyList(list))   // ���� ������ ����
	{
		return false;
	}

	ListEntry* findEntry = list->head;

	if (findEntry->element->word == findWord) // ���� ������� ������� ����� � ������ ������
	{
		return findEntry;
	}

	if (findEntry->element->word > findWord)   // ���� � ������ ������ ������� ��������
	{
		return nullptr;
	}

	while (findEntry->element->word < findWord)
	{
		if (findEntry->next == nullptr)   //  ���� ����� �� ����� ������
		{
			return nullptr;
		}
		else if (findEntry->next->element->word > findWord)   // ���� ��������� ������� ������, � ��������������� - ������ ��������
		{
			return nullptr;
		}
		else if (findEntry->next->element->word < findWord)   // ���� ����� ���������� �� ������
		{
			findEntry = findEntry->next;
		}
		else   // ��������� ������� - �������
		{
			return findEntry->next;
		}
	}
}

void addListEntry(List* list, HashTableEntry* addEntry)
{
	ListEntry* newEntry = new ListEntry{ addEntry, nullptr };

	if (isEmptyList(list))   // ���� ������ ����
	{
		list->head = newEntry;
		return;
	}

	ListEntry* entry = list->head;
	if (entry->element->word > addEntry->word)   // ���� ����� �������� ����� � ������ ������
	{
		list->head = newEntry;
		newEntry->next = entry;
		return;
	}

	while (entry->element->word <= addEntry->word)
	{
		if (entry->next == nullptr)   // ���� ����� �������� � ����� ������
		{
			entry->next = newEntry;
			break;
		}
		else if (entry->next->element->word > addEntry->word)   //   ���� ����� �������� ����� ��������������� � ��������� ����������
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
	if (isEmptyList(list))   // ���� ������ ����
	{
		return false;
	}

	ListEntry* deleteEntry = list->head;

	if (deleteEntry->element->word == deleteWord) // ���� ������� ������� ����� � ������ ������
	{
		list->head = deleteEntry->next;
		delete deleteEntry->element;
		delete deleteEntry;
		return true;
	}

	if (deleteEntry->element->word > deleteWord)   // ���� � ������ ������ ������� ��������
	{
		return false;
	}

	while (deleteEntry->element->word < deleteWord)
	{
		if (deleteEntry->next == nullptr)   //  ���� ����� �� ����� ������
		{
			return false;
		}
		else if (deleteEntry->next->element->word > deleteWord)   // ���� ��������� ������� ������, � ��������������� - ������ ��������
		{
			return false;
		}
		else if (deleteEntry->next->element->word < deleteWord)   // ���� ����� ���������� �� ������
		{
			deleteEntry = deleteEntry->next;
		}
		else   // ��������� ������� - �������
		{
			if (deleteEntry->next->next == nullptr)   // ���� ������� ������� - ��������� � ������
			{
				delete deleteEntry->next->element;
				delete deleteEntry->next;
				deleteEntry->next = nullptr;
				return true;
			}
			else   // ���� ������� ������� ������� ������
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