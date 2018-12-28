#pragma once
#include <vector>

/// ���������, �������������� ����� ���� ������, �������� � ���� ����� ����� � ���������
/// �� ����� � ������ ����
struct SetElement;

/// ���������, ���������� ��������� �� ������ ������
struct Set;

/// ������� ���������, ���������� ��������� �� ������ ������
Set* createSet();

/// ���� ������� � ���������, ���������� ��������� �� ���������� ��� ���������,
/// ���� �� ���������� � ���������, ����� ���������� nullptr
SetElement* findSetEelement(Set *set, int findValue);

/// ��������� ������, � �������, ���� ��������� �������, ���������� �������� ���������
/// � �������� ������������������: isIncreasingSequence = 1 - � ������������, ����� -
/// � ���������; � ���������� true; ����� ���������� false
bool outputSetElements(Set* set, std::vector<int>& sequence, std::vector<int>& countsOfElements);

/// ��������� ������� � ���������, ���� ��� ��� ���, ������ true,
/// ����� ���������� false
void addSetElement(Set *set, int newValue);

/// ������� ������� �� ���������, ���� �� ���� ����, ������ true,
/// ����� ���������� false
bool removeSetElement(Set* set, int removeValue);

/// ������� ���������
void deleteSet(Set* set);

/// ���������� �������� �������� ��������� � ���������� ����������� ���������
int findMaxSetElement(Set* set);