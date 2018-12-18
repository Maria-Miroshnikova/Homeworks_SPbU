#pragma once
#include <fstream>

struct List;

/// ��������� �� ����� ������ � ���������� �� � ������.
void makeList(List* list, istream& dataFile, string& data);

/// �������� ������ �� ���������� ������ �� �����,
/// �������� ������ �� ��������� ������, ������� ������ �� �����,
/// ���� �� �� ����, ������ true, ����� ������� false.
bool workingWithData(std::istream& dataFile);
