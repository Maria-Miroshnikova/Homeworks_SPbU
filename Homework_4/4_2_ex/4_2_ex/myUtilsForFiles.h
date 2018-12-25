#pragma once
#include <vector>
#include <string>

/// ������� �� ����� ������
void outputVector(std::vector<int>& vectorOut);

/// ��������� �� ����� ����� � ������
bool readDataFromFile(std::string& data, std::istream& file);

/// ��������� ������ �� �����
void readArrayFromFile(std::istream& dataFile, std::vector<int>& arrayForSort);