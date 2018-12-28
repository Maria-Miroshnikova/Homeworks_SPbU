#pragma once
#include <vector>
#include <string>

struct TreeElement;

struct Tree;

/// создает дерево и возвращает ссылку на него
Tree* createTree();

/// проверяет дерево на пустоту
bool isEmptyTree(Tree* tree);

/// возвращает ссылку на искомый по ключу элемент дерева
TreeElement* findTreeEelement(Tree* tree, const std::string& findKey);

/// возвращает значение, соответствующее заданному ключу в дереве (если ключа в дереве нет, возвращает пустую строку)
std::string getValue(Tree* tree, const std::string& findKey);

/// проверяет наличие ключа в дереве
bool existsKey(Tree* tree, const std::string& findKey);

/// добавляет в дерево ключ со значением (если ключ уже есть в дереве, меняет соответствующее ему значение на новое)
void addTreeElement(Tree* tree, const std::string& newKey, const std::string& newValue);

/// удаляет элемент с заданными ключем из дерева, вернув true, если ключ был в дереве, иначе возвращает false
bool removeTreeElement(Tree* tree, const std::string& removeKey);

/// удаляет дерево
void deleteTree(Tree* tree);