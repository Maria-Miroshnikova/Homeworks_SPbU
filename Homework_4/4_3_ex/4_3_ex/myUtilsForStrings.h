#pragma once

/// ���������, ����� �� ���������� ���� �����, ���������������� ������ ����� �
/// �������� ����������� '\0' � '\n'
bool isSameStrs(char str1[], char str2[]);

/// ��������� �� ������� ������ �� start`������� �� end`������� (�� ������������)
void readStr(char str[], char buffer[], int startIndex, int endIndex);

/// ���������� ����� ���������� ����������� ������, �������� ����������� '\0' � '\n'
int lengthStr(char str[]);