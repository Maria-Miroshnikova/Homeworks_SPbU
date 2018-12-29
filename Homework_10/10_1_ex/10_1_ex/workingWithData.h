#pragma once
#include "myGraph.h"
#include <vector>

/// вспомогательная структура, хранит столицу, метку участия столицы в раздаче и вектор захваченных городов
struct Country
{
	GraphNode* capital;
	bool done;
	std::vector<GraphNode*> cities;
};

/// раздает города
void makeCountries(Graph* graph, std::vector<Country*>& countries);

/// удаляет вспомогательную вектор вспомогательных структур (стран)
void deleteCountries(std::vector<Country*>& countries);

/// посылает запрос на получение данных, раздачу городов и вывод стран на экран
void workingWothData();