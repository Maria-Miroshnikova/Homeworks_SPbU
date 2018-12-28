#pragma once
#include <vector>
#include "myGraph.h"

struct WeightedEdge;

/// элемент списка, содержащий указатель на вершину и указатель на следующий элемент
struct ListEntry
{
	WeightedEdge* edge;
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
void addListEntry(List* list, WeightedEdge* newElement);

/// записывает список в вектор, если список не пуст,
/// и возвращает true, иначе возвращает false.
bool makeOutputList(List* list, std::vector<WeightedEdge*>& sequence);

/// удаляет запись из списка и возвращает true, если она там была,
/// иначе возвращает false (в частности, если список был пуст)
bool deleteListEntry(List* list, int deleteValue);

/// удаляет список
void deleteList(List* list);

/// возвращает длину списка
int countSizeOfList(List* list);