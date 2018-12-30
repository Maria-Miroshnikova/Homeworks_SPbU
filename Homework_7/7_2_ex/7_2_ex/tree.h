#pragma once
#include <vector>
#include <string>

struct TreeElement;

struct Tree;

/// создает дерево и возвращает ссылку на него
Tree* createTree();

/// проверяет дерево на пустоту
bool isEmptyTree(Tree* tree);

/// создает новую вершину дерева, цепляет ее к заданной и возвращает ссылку на новую
TreeElement* addTreeElement(TreeElement*& currentNode);

/// удаляет дерево
void deleteTree(Tree* tree);

/// записывает выражение из строки в дерево (поддерживаемые операции: */+-)
void makeExpressionTree(Tree* tree, const std::string& data);

/// считает значение выражения (поддерживаемые операции: */+-), записанного в дерево, и возвращает его
int countExpression(Tree* tree);