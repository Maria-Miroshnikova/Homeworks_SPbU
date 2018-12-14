#pragma once
#include <vector>

/// ������� ���������� �������� �����
void outputVectors(std::vector<int>& outputX, std::vector<int>& outputY);

/// ��������� ������ � ���������� � ������� �������� ��������
void inputArrange(std::vector<std::vector<int>>& numbers, const int sizeI, const int sizeJ);

/// ���� �������� ����� � ���������� �� ���������� � ��������������� �������
void findSaddle(std::vector<std::vector<int>>& numbers, const int sizeI, const int sizeJ, std::vector<int>& saddleX, std::vector<int>& saddleY);