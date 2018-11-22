#pragma once
#include <vector>

using namespace std;

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
bool outputSetElements(Set* set, bool isIncreasingSequence, vector<int>& sequence);

/// ��������� ������� � ���������, ���� ��� ��� ���, ������ true,
/// ����� ���������� false
bool addSetElement(Set *set, int newValue);

/// ������� ������� �� ���������, ���� �� ���� ����, ������ true,
/// ����� ���������� false
bool removeSetElement(Set* set, int removeValue);

/// ������� ���������
void deleteSet(Set* set);