#pragma once

/// ��������� ������ ����� �� �����, ����� �� �����, ���������� �� � ����������� ������
/// � ���������� � �������� ����, ���� ����� �� ����� ����������� ������ ������������
void workingWithData(FILE *inputData, FILE *outputData, int compareNumber);

/// ��������� ����������� ����� �� �����, �����������, ��� � ��� ���������� ���� �����
int readNumberFromFile(FILE *inputData, int maxLength);