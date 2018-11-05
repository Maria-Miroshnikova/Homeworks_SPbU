#pragma once
#include "myStructures.h"

/// ��� ������ ���� "<name>: <phone>" ���������� ������ ��������� � ���
int parseStrToPartOfEntry(char str[]);

/// ��������� ������� � ������, ������� ����� ������������� � ������,
/// ������� ������������������ "<�����>: <�� ������>"
bool isCorrectEntry(char str[]);

/// ��������� ������ �� ��� � �������, ��������� �� ��� ������ � ���������� ��
PhoneBookEntry createEntry(char buffer[], int maxLength);

/// ��������� ������ �� �������
bool isEmptyEntry(PhoneBookEntry entry);

/// ������ ������� ��� ������ � �������-�����������
void swapEntries(PhoneBookEntry phonebook[], int index1, int index2);

/// ���������� ����� ���� �� ��������, ���� ����� �� �������� �������, ���������� ������ �������
int comparePartsOfNames(char str1[], char str2[], int indexStart);

/// ���������� ����� + 1 ��� ������, ������� ������ ���� ������  ���������� �������,
/// � 1, ���� ����� �����
int compareStr(char str1[], char str2[]);

/// ������� ��� ����� ������ ����� � ���������� ����� � ���������� �������, ��������� �� �� ������ �����
void selectionSortEntries(PhoneBookEntry phoneBook[], PhoneBookEntry newEntry, int indexLastEntry);

/// ���� � �������-������ �������, ����������� � ������, � ���������� ��� ������ � �������, ���� ����� �������,
/// ����� ���������� -1. ���� key == 1, ���� �� �����, ���� key == 0, ���� �� ��������.
int searchEntry(PhoneBookEntry phoneBook[], char str[], bool key, int indexLastEntry);