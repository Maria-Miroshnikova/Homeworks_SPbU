#pragma once
#include <vector>

/// элемент списка, содержащий значение и указатель на следующий элемент.
struct ListEntry
{
	int value;
	ListEntry* next;
};

/// указатель на начало списка.
struct List
{
	ListEntry* head;
};

/// создает список.
List* createList();

/// проверка списка на пустоту.
bool isEmptyList(List* list);

/// добавляет элемент в список.
void addListEntry(List* list, int newValue);

/// если список пуст, возвращает false, иначе
/// записывает в вектор значения списка и возвращает true.
bool outputList(List* list, std::vector<int>& sequence);

/// если элемент есть в списке, удаляет его и возвращает true, иначе возвращает false.
bool deleteListEntry(ListEntry*& previousEntry, int deleteValue);

/// удаляет список.
void deleteList(List* list);

/// считает длину списка.
int sizeOfList(List* list);