#pragma once
#include <vector>
#include <string>
#include "myList.h"

struct List;

/// структура, содержаща€ слово и количество его вхождений
struct HashTableEntry
{
	std::string word;
	int count;
};

/// структура, содержаща€ указатель на вектор, содержащий в себе списки слов
/// с хэшем, равным индексу соответствующей €чейки вектора
struct HashTable
{
	std::vector<List*> bucket;
};

/// создает таблицу заданного размера и возвращает указатель на нее.
HashTable* createHashTable(const int size);

/// ищет слово в таблице и возвращает указатель на него,
/// иначе возвращает нулевой указатель.
HashTableEntry* findEntryHashTable(HashTable* hashTable, std::string& newWord);

/// добавл€ет слово в хэш-таблицу, если его там нет, иначе увеличивает
/// счетчик вхождени€ этого слова на единицу.
void addEntryHashTable(HashTable* hashTable, std::string& newWord);

/// считает коэффициент заполнени€ таблицы, максимальную и минимальную длины в сегменте списка
/// в заранее заведенные нулевые переменные под каждую из характеристик.
void computePropertiesHashTable(HashTable* hashTable, float& loadFactor, int& maxListLength, float& middleListLength);

/// удал€ет хэш-таблицу (удал€ет списки из каждой €чейки хэш-вектора и указатель на вектор).
void deleteHashTable(HashTable* hashTable);