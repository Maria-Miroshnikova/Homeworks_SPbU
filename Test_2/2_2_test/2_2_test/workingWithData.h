#pragma once
#include <fstream>

struct List;

/// проверяет симметричность списка.
bool isSymmetricList(List* list);

/// посылает запрос на считывание данных из файла,
/// посылает запрос на проверку симметричности списка и возвращает результат проверки.
bool workingWithData(std::istream& dataFile);