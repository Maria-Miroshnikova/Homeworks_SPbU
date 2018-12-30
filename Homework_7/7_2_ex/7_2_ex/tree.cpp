#include "tree.h"
#include <stdio.h>
#include <vector>
#include <string>
#include "myUtilsForString.h"

using namespace std;

/// элемент дерева, содержащий указатели на левого и правого сыновей, операцию и значение
struct TreeElement
{
	char operation;
	int value;
	TreeElement *leftChild;
	TreeElement *rightChild;
};

/// двоичное дерево
struct Tree
{
	TreeElement *head;
};

Tree* createTree()
{
	Tree* tree = new Tree { nullptr };
	return tree;
}

bool isEmptyTree(Tree* tree)
{
	return (tree->head == nullptr);
}

TreeElement* addTreeElement(TreeElement*& currentNode)
{
	TreeElement* newNode = new TreeElement{ '\0', -10, nullptr, nullptr };
	currentNode = newNode;
	return newNode;
}

int countDFS(TreeElement* element)
{
	int result = 0;
	if (element != nullptr)
	{
		if (element->operation != '\0')
		{
			int firstOperand = countDFS(element->leftChild);
			int secondOperand = countDFS(element->rightChild);
			if (element->operation == '+')
			{
				result += firstOperand + secondOperand;
			}
			else if (element->operation == '-')
			{
				result += firstOperand - secondOperand;
			}
			else if (element->operation == '*')
			{
				result += firstOperand * secondOperand;
			}
			else
			{
				result += firstOperand / secondOperand;
			}
		}
		else
		{
			result = element->value;
		}
	}
	return result;
}

int countExpression(Tree* tree)
{
	return countDFS(tree->head);
}

void deleteDFS(TreeElement* element)
{
	if (element == nullptr)
	{
		return;
	}

	deleteDFS(element->leftChild);
	TreeElement* nextElement = element->rightChild;
	deleteDFS(element->rightChild);

	delete element;
}

void deleteTree(Tree* tree)
{
	if (!isEmptyTree(tree))
	{
		deleteDFS(tree->head);
	}
	delete tree;
}

bool makeNumberNode(TreeElement* currentNode, const string& data, size_t& i)
{
	while ((data[i] >= '0') && (data[i] <= '9'))
	{
		if (currentNode->leftChild == nullptr)
		{
			TreeElement* leftNode = addTreeElement(currentNode->leftChild);
			leftNode->value = data[i] - '0';
		}
		else
		{
			TreeElement* rightNode = addTreeElement(currentNode->rightChild);
			rightNode->value = data[i] - '0';
			return false;
		}

		if (!getNewChar(data, i))
		{
			return false;
		}
	}
	return true;
}

void makeTree(Tree* tree, TreeElement* currentNode, const string& data, size_t& i)
{
	if (!getNewChar(data, i))
	{
		return;
	}

	if (!makeNumberNode(currentNode, data, i))
	{
		return;
	}

	while ((data[i] == '*') || (data[i] == '/') || (data[i] == '+') || (data[i] == '-'))
	{
		if (isEmptyTree(tree))
		{
			currentNode = addTreeElement(tree->head);
			currentNode->operation = data[i];
			makeTree(tree, currentNode, data, i);

		}
		else if (currentNode->leftChild == nullptr)
		{
			TreeElement* nodeLeft = addTreeElement(currentNode->leftChild);
			nodeLeft->operation = data[i];
			makeTree(tree, nodeLeft, data, i);
		}
		else
		{
			TreeElement* nodeRight = addTreeElement(currentNode->rightChild);
			nodeRight->operation = data[i];
			makeTree(tree, nodeRight, data, i);
			return;
		}

		if (!getNewChar(data, i))
		{
			return;
		}
	}

	if (!makeNumberNode(currentNode, data, i))
	{
		return;
	}

}

void makeExpressionTree(Tree* tree, const string& data)
{
	size_t i = 0;
	makeTree(tree, nullptr, data, i);
}