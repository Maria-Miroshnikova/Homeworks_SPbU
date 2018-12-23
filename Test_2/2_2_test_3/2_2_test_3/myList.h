#pragma once
#include <vector>

/// элемент списка, содержащий значение и указатель на следующий элемент
struct ListEntry
{
	int value;
	ListEntry* next;
};

/// указатель на начало списка с позициями
struct List
{
	ListEntry* head;
};

/// проверяет, является ли список пустым
bool isEmptyList(List* list);

/// создает пустой список и возвращает указатель на него
List* createList();

/// добавляет запись в список на заданную позицию
bool addListEntry(List* list, int newValue, int position);

/// записывает список в вектор, если список не пуст,
/// и возвращает true, иначе возвращает false.
bool makeOutputList(List* list, std::vector<int>& sequence);

/// удаляет запись из списка с заданной позиции и возвращает true, если позиция корректна,
/// иначе возвращает false (список имеет меньшую длину, пуст)
bool deleteListEntry(List* list, int position);

/// удаляет список
void deleteList(List* list);