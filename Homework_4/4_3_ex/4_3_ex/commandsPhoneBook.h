#pragma once
#include "myStructures.h"

/// ������� ������-����������
void deletePhoneBook(PhoneBookEntry phoneBook[]);

/// ������� ���������� ����� "HELP.txt"
void help();

/// ������� ��� ������ �� �������-�����������
void outputAllEntries(PhoneBookEntry phoneBook[]);

/// ��������� ������ � ������-����������, �������� ����� ��������� ������� ������,
/// ���� ������ ������ � ����� ��� ��� � ���� ��������� ����� � �������, ������ 0,
/// ����� ����������: 1 - ��� ��� ���� � �������, 2 - ������� ��� ���� � �������,
/// 3 - ������������ �������.
int addEntry(PhoneBookEntry phoneBook[], PhoneBookEntry newEntry, int *indexLastEntry);

/// ���� ����� �� ��������� ����� � ������� ����� � ���������� ��� ������, ���� �������,
/// ����� ���������� -1
int findPhone(PhoneBookEntry phoneBook[], char name[], int indexLasrEntry);

/// ���� ��� �� ��������� ������ � ������� ����� � ���������� ��� ������, ���� �������,
/// ����� ���������� -1
int findName(PhoneBookEntry phoneBook[], char phone[], int indexLasrEntry);

/// ���������� ���� ������-������ � ���� "phonebook.txt"
void savePhoneBook(PhoneBookEntry phoneBook[], int indexLastEntry);

/// ������� ������-����������, ��������� � ���� ������ �� ���������� ����� �����������
/// � ���������� ��������� �� ����
PhoneBookEntry *createPhoneBook(int *indexLastEntry, FILE *phonebook);
