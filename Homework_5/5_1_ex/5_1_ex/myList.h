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
void addEntryList(ListEntry*& previousEntry, int newValue);

/// записывает в вектор все содержимое списка (в возврастающем порядке)
void makeOutputList(ListEntry*& previousEntry, std::vector<int>& sequence);

/// отправляет запрос на запись списка в вектор, если список не пуст,
/// и возвращает true, иначе возвращает false.
bool outputList(List* list, std::vector<int>& sequence);

/// удаляет запись из списка и возвращает true, если она там была,
/// иначе возвращает false (в частности, если список был пуст)
bool deleteEntryList(ListEntry*& previousEntry, int deleteValue);

/// удаляет список
void deleteList(List* list);