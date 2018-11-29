#pragma once
#include <vector>
#include <string>
#include "myHashTable.h"

struct HashTableEntry;

/// структура, представляющая элемент списка, содержащий элемент хэш-таблицы
/// и указатель на следующий элемент списка.
struct ListEntry
{
	HashTableEntry* element;
	ListEntry* next;
};

/// структура, содержащая указатель на начало списка.
struct List
{
	ListEntry* head;
};

/// проверяет, является ли список пустым.
bool isEmptyList(List* list);

/// создает пустой список и возвращает указатель на него.
List* createList();

/// возвращает указатель на элемент списка, в котором записано
/// такое же слово, иначе возвращает нулевой указатель.
ListEntry* findListEntry(ListEntry*& previousEntry, std::string& findWord);

/// добавляет запись в сортированный список, сохраняя порядок.
void addListEntry(ListEntry*& previousEntry, std::string& newWord);

/// записывает в вектор все содержимое списка (в возврастающем порядке).
void makeOutputList(ListEntry*& previousEntry, std::vector<HashTableEntry*>& sequence);

/// отправляет запрос на запись списка в вектор, если список не пуст,
/// и возвращает true, иначе возвращает false.
bool outputList(List* list, std::vector<HashTableEntry*>& sequence);

/// удаляет запись из списка и возвращает true, если она там была,
/// иначе возвращает false (в частности, если список был пуст).
bool deleteListEntry(ListEntry*& previousEntry, std::string& deleteWord);

/// удаляет список.
void deleteList(List* list);

/// возвращает длину списка
int sizeOfList(List* list);