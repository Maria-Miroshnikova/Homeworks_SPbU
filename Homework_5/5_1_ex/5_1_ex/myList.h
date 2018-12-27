#pragma once
#include <vector>

/// элемент списка, содержащий значение и указатель на следующий элемент
struct ListEntry
{
	int value;
	ListEntry* next;
};

/// указатель на начало списка
struct List
{
	ListEntry* head;
};

/// проверяет, является ли список пустым
bool isEmptyList(List* list);

/// создает пустой список и возвращает указатель на него
List* createList();

/// добавляет запись в сортированный список, сохраняя порядок
void addListEntry(List* list, int newValue);

/// записывает список в вектор, если список не пуст,
/// и возвращает true, иначе возвращает false.
bool makeOutputList(List* list, std::vector<int>& sequence);

/// удаляет запись из списка и возвращает true, если она там была,
/// иначе возвращает false (в частности, если список был пуст)
bool deleteListEntry(List* list, int deleteValue);

/// удаляет список
void deleteList(List* list);