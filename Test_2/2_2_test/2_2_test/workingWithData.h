#pragma once
#include <fstream>

struct List;

/// ��������� �������������� ������.
bool isSymmetricList(List* list);

/// �������� ������ �� ���������� ������ �� �����,
/// �������� ������ �� �������� �������������� ������ � ���������� ��������� ��������.
bool workingWithData(std::istream& dataFile);