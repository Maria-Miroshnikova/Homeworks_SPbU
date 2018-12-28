#pragma once
#include "set.h"
#include <string>

/// считывает данные из файла
bool getDataFromFile(std::istream& file, std::string& data);

/// принимает одну запись из файла и отмечает посещение в таблице
void makeTimeTable(Set* timeTable, std::istream& dataFile, std::string& data);

/// отправляет запрос на принятие данные, вычисление часа с наибольшей посещаемостью и воводит его на экран.
bool workingWithData();