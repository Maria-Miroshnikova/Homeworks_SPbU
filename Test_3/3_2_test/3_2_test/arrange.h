#pragma once
#include <vector>

/// выводит координаты седловых точек
void outputVectors(std::vector<int>& outputX, std::vector<int>& outputY);

/// считывает массив с клавиатуры с заранее заданным размером
void inputArrange(std::vector<std::vector<int>>& numbers, const int sizeI, const int sizeJ);

/// ищет седловые точки и записывает их коориднаты в соответствующие массивы
void findSaddle(std::vector<std::vector<int>>& numbers, const int sizeI, const int sizeJ, std::vector<int>& saddleX, std::vector<int>& saddleY);