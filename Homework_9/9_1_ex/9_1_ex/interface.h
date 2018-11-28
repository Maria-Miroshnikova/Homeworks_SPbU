#pragma once
#include"myHashTable.h"
#include <fstream>

/// выводит на экран слова из хэш-таблицы и их количество, если таблица непуста,
/// иначе выводит сообщение о пустоте таблицы
void outputWordsFromHash(HashTable* hashTable, float loadFactor);

/// считывает слово из файла, очищает его от символов, мен€ет заглавные
/// буквы на строчные и возвращает длину полученного слова (если в слове
/// не было букв, возвращает 0)
int readDataFromFile(std::string& data, std::istream& file);

/// считывает слова из файла, добавл€€ их в таблицу, отправл€ет запрос на вывод таблицы
void workingWithData(std::ifstream& dataFile);