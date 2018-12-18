#pragma once
#include <fstream>

struct List;

/// считывает из файла данные и записывает их в список.
void makeList(List* list, istream& dataFile, string& data);

/// посылает запрос на считывание данных из файла,
/// посылает запрос на переворот списка, выводит список на экран,
/// если он не пуст, вернув true, иначе выводит false.
bool workingWithData(std::istream& dataFile);
