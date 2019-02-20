#pragma once
#include <vector>
#include <string>

/// выводит на экран вектор
void outputVector(std::vector<int>& vectorOut);

/// считывает из файла число в строку
bool readDataFromFile(std::string& data, std::istream& file);

/// считывает массив из файла
void readArrayFromFile(std::istream& dataFile, std::vector<int>& arrayForSort);