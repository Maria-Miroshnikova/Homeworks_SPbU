#pragma once
#include "myGraph.h"
#include <vector>

/// ��������������� ���������, ������ �������, ����� ������� ������� � ������� � ������ ����������� �������
struct Country
{
	GraphNode* capital;
	bool done;
	std::vector<GraphNode*> cities;
};

/// ������� ������
void makeCountries(Graph* graph, std::vector<Country*>& countries);

/// ������� ��������������� ������ ��������������� �������� (�����)
void deleteCountries(std::vector<Country*>& countries);

/// �������� ������ �� ��������� ������, ������� ������� � ����� ����� �� �����
void workingWothData();