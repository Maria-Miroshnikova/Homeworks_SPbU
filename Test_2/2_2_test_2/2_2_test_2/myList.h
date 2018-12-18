#pragma once
#include <vector>

struct List;

/// проверяет, является ли список пустым
bool isEmptyList(List* list);

/// создает пустой список и возвращает указатель на него
List* createList();

/// добавляет элемент на заданную позицию списка, если позиция не больше длины списка, вернув ture,
/// иначе возвращает false
bool addListEntry(List* list, int newValue, int position);

/// записывает список в вектор, если список не пуст,
/// и возвращает true, иначе возвращает false.
bool makeOutputList(List* list, std::vector<int>& sequence);

/// удаляет элемент с заданной позиции списка, если позиция не больше длины списка - 1,
/// вернув true, иначе возвращает false.
bool deleteListEntry(List* list, int position);

/// удаляет список
void deleteList(List* list);