#pragma once
#include "myStructures.h"

/// ���������� ���� ������ � ����
void saveEntry(PhoneBookEntry entry, FILE *phonebook);

/// ��������� ���������� ���������� �� ����� (���� �� �������) � ������-����������
void readStartPhoneBook(PhoneBookEntry phoneBook[], int *indexLastEntry, FILE *phonebook);

/// ������� ���������� �����
void outputFile(FILE *file);