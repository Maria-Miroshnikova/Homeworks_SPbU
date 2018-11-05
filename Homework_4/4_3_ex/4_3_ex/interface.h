#pragma once
#include "myStructures.h"

/// ������� ��� �� �������-�����������
void outputName(PhoneBookEntry entry);

/// ������� ������� �� �������-�����������
void outputPhone(PhoneBookEntry entry);

/// ������� ������ �� �������-�����������
void outputEntry(PhoneBookEntry entry);

/// ��������� ������ ��� �������������� � ������,
/// ���� ������ ����������� - ������� ��������� �� ������ � ���������� ������ ������ �����.
PhoneBookEntry getEntry(int maxLength);

/// ��������� ������� �� ��� ���, ���� ������� �� �������, � ���������� ��
void getCommand(PhoneBookEntry phoneBook[], int *indexLastEntry);