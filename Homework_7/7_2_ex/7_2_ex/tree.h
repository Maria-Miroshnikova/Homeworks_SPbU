#pragma once
#include <vector>
#include <string>

struct TreeElement;

struct Tree;

/// ������� ������ � ���������� ������ �� ����
Tree* createTree();

/// ��������� ������ �� �������
bool isEmptyTree(Tree* tree);

/// ������� ����� ������� ������, ������� �� � �������� � ���������� ������ �� �����
TreeElement* addTreeElement(TreeElement*& currentNode);

/// ������� ������
void deleteTree(Tree* tree);

/// ���������� ��������� �� ������ � ������ (�������������� ��������: */+-)
void makeExpressionTree(Tree* tree, const std::string& data);

/// ������� �������� ��������� (�������������� ��������: */+-), ����������� � ������, � ���������� ���
int countExpression(Tree* tree);