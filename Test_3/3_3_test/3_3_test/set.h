#pragma once
#include <vector>

/// структура, представляющая собой узел дерева, содержит в себе целое число и указатели
/// на левый и правый узлы
struct SetElement;

/// структура, содержащая указатель на корень дерева
struct Set;

/// создает множество, возвращает указатель на корень дерева
Set* createSet();

/// ищет элемент в множестве, возвращает указатель на содержащую его структуру,
/// если он содержится в множестве, иначе возвращает nullptr
SetElement* findSetEelement(Set *set, int findValue);

/// принимает вектор, в который, если множество непусто, записывает элементы множества
/// в заданной последовательности: isIncreasingSequence = 1 - в возрастающей, иначе -
/// в убывающей; и возвращает true; иначе возвращает false
bool outputSetElements(Set* set, std::vector<int>& sequence, std::vector<int>& countsOfElements);

/// добавляет элемент в множество, если его там нет, вернув true,
/// иначе возвращает false
void addSetElement(Set *set, int newValue);

/// удаляет элемент из множества, если он таем есть, вернув true,
/// иначе возвращает false
bool removeSetElement(Set* set, int removeValue);

/// удаляет множество
void deleteSet(Set* set);

/// возвращает значение элемента множества с наибольшим количеством вхождений
int findMaxSetElement(Set* set);