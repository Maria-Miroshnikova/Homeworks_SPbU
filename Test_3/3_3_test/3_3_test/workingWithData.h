#pragma once
#include "set.h"
#include <string>

/// ��������� ������ �� �����
bool getDataFromFile(std::istream& file, std::string& data);

/// ��������� ���� ������ �� ����� � �������� ��������� � �������
void makeTimeTable(Set* timeTable, std::istream& dataFile, std::string& data);

/// ���������� ������ �� �������� ������, ���������� ���� � ���������� ������������� � ������� ��� �� �����.
bool workingWithData();