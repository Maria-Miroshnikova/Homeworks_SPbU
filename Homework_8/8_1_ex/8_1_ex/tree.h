#pragma once
#include <vector>
#include <string>

struct TreeElement;

struct Tree;

/// ������� ������ � ���������� ������ �� ����
Tree* createTree();

/// ��������� ������ �� �������
bool isEmptyTree(Tree* tree);

/// ���������� ������ �� ������� �� ����� ������� ������
TreeElement* findTreeEelement(Tree* tree, const std::string& findKey);

/// ���������� ��������, ��������������� ��������� ����� � ������ (���� ����� � ������ ���, ���������� ������ ������)
std::string getValue(Tree* tree, const std::string& findKey);

/// ��������� ������� ����� � ������
bool existsKey(Tree* tree, const std::string& findKey);

/// ��������� � ������ ���� �� ��������� (���� ���� ��� ���� � ������, ������ ��������������� ��� �������� �� �����)
void addTreeElement(Tree* tree, const std::string& newKey, const std::string& newValue);

/// ������� ������� � ��������� ������ �� ������, ������ true, ���� ���� ��� � ������, ����� ���������� false
bool removeTreeElement(Tree* tree, const std::string& removeKey);

/// ������� ������
void deleteTree(Tree* tree);