#include "tree.h"
#include <vector>
#include <string>

using namespace std;

/// элемент дерева, содержащий ключ, соответствующее ему значение,
/// разницу высот левого и правого поддеревьев, ссылки на левого и правого сыновей
struct TreeElement
{
	string key;
	string value;
	int difference;   // left - right
	TreeElement *leftChild;
	TreeElement *rightChild;
};

/// ассоциативный массив на основе АВЛ-дерева
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

TreeElement* findTreeEelement(Tree* tree, const string& findKey)
{
	if (isEmptyTree(tree))
	{
		return nullptr;
	}

	TreeElement* element = tree->head;
	while (true)
	{
		if (element->key > findKey)
		{
			if (element->leftChild == nullptr)
			{
				return nullptr;
			}
			else
			{
				element = element->leftChild;
			}
		}
		else if (element->key < findKey)
		{
			if (element->rightChild == nullptr)
			{
				return nullptr;
			}
			else
			{
				element = element->rightChild;
			}
		}
		else
		{
			return element;
		}
	}
}

string getValue(Tree* tree, const string& findKey)
{
	TreeElement* findElement = findTreeEelement(tree, findKey);
	if (findElement == nullptr)
	{
		return "";
	}
	else
	{
		return findElement->value;
	}
}

bool existsKey(Tree* tree, const string& findKey)
{
	return (findTreeEelement(tree, findKey) != nullptr);
}

TreeElement* findParent(Tree* tree, TreeElement* findElement)
{
	if (findElement == tree->head)
	{
		return nullptr;
	}

	TreeElement* element = tree->head;
	while (true)
	{
		if (element->key > findElement->key)
		{
			if (element->leftChild == findElement)
			{
				return element;
			}
			else
			{
				element = element->leftChild;
			}
		}
		else if (element->key < findElement->key)
		{
			if (element->rightChild == findElement)
			{
				return element;
			}
			else
			{
				element = element->rightChild;
			}
		}
	}
}

int countHight(TreeElement* element)
{
	int h = 1;
	while (element != nullptr)
	{
		if (element->difference >= 0)
		{
			element = element->leftChild;
		}
		else
		{
			element = element->rightChild;
		}
		++h;
	}
	return h;
}

void fixDifference(TreeElement* element)
{
	if (element->rightChild != nullptr)
	{
		fixDifference(element->rightChild);
	}

	if (element->leftChild != nullptr)
	{
		fixDifference(element->leftChild);
	}

	element->difference = countHight(element->leftChild) - countHight(element->rightChild);
}

void smallRightRotation(TreeElement*& element)
{
	TreeElement* downNode = element;
	element = element->leftChild;
	TreeElement* downTree = element->rightChild;
	element->rightChild = downNode;
	downNode->leftChild = downTree;
	
	fixDifference(element->rightChild);
	fixDifference(element);
}

void smallLeftRotation(TreeElement*& element)
{
	TreeElement* downNode = element;
	element = element->rightChild;
	TreeElement* downTree = element->leftChild;
	element->leftChild = downNode;
	downNode->rightChild = downTree;

	fixDifference(element->leftChild);
	fixDifference(element);
}

void bigLefttRotation(TreeElement*& element)
{
	smallRightRotation(element->rightChild);
	smallLeftRotation(element);
}

void bigRightRotation(TreeElement*& element)
{
	smallLeftRotation(element->leftChild);
	smallRightRotation(element);
}

void balancing(TreeElement*& element)
{
	if ((countHight(element->leftChild) > countHight(element->rightChild) + 1))
	{
		if (countHight(element->leftChild->rightChild) <= countHight(element->leftChild->leftChild))
		{
			smallRightRotation(element);
		}
		else
		{
			bigRightRotation(element);
		}
	}
	else if ((countHight(element->rightChild) > countHight(element->leftChild) + 1))
	{
		if ((countHight(element->rightChild->leftChild) <= countHight(element->rightChild->leftChild) + 1))
		{
			smallLeftRotation(element);
		}
		else
		{
			bigLefttRotation(element);
		}
	}
}

void checkBalance(TreeElement* tree, Tree* treeRoot)
{
	if (tree == nullptr)   /// после удаления простого случая
	{
		return;
	}

	fixDifference(tree);
	if ((tree->difference < -1) || (tree->difference > 1))
	{
		TreeElement* parent = findParent(treeRoot, tree);
		if (parent == nullptr)
		{
			balancing(treeRoot->head);
		}
		else if (tree == parent->leftChild)
		{
			balancing(parent->leftChild);
		}
		else
		{
			balancing(parent->rightChild);
		}
	}
}

void addNewTreeElement(Tree* treeRoot, TreeElement* tree, TreeElement* newElement)
{
	if (newElement->key > tree->key)
	{
		if (tree->rightChild != nullptr)
		{
			addNewTreeElement(treeRoot, tree->rightChild, newElement);
		}
		else
		{
			tree->rightChild = newElement;
		}

		checkBalance(tree, treeRoot);

	}
	else if (newElement->key < tree->key)
	{
		if (tree->leftChild != nullptr)
		{
			addNewTreeElement(treeRoot, tree->leftChild, newElement);
		}
		else
		{
			tree->leftChild = newElement;
		}

		checkBalance(tree, treeRoot);
	}
}

void addTreeElement(Tree* tree, const string& newKey, const string& newValue)
{
	TreeElement* findElement = findTreeEelement(tree, newKey);
	if (findElement == nullptr)
	{
		TreeElement* newElement = new TreeElement{ newKey, newValue, 0, nullptr, nullptr };
		if (isEmptyTree(tree))
		{
			tree->head = newElement;
			return;
		}
		addNewTreeElement(tree, tree->head, newElement);
	}
	else
	{
		findElement->value = newValue;
	}
}

void dfs(TreeElement* element, bool isIncreasingSequence, vector<TreeElement*>& sequence)
{
	if (element == nullptr)
	{
		return;
	}
	if (isIncreasingSequence)
	{
		dfs(element->leftChild, isIncreasingSequence, sequence);
	}
	else
	{
		dfs(element->rightChild, isIncreasingSequence, sequence);
	}

	sequence.push_back(element);
	
	if (isIncreasingSequence)
	{
		dfs(element->rightChild, isIncreasingSequence, sequence);
	}
	else
	{
		dfs(element->leftChild, isIncreasingSequence, sequence);
	}
}

bool outputTreeElements(Tree* tree, bool isIncreasingSequesnce, vector<TreeElement*>& sequence)
{
	if (!isEmptyTree(tree))
	{
		dfs(tree->head, isIncreasingSequesnce, sequence);
		return true;
	}
	return false;
}

void deleteSimpleCase(TreeElement*& element)
{
	TreeElement* elementDelete = element;

	if ((element->leftChild == nullptr) && (element->rightChild == nullptr)) // удаление листа
	{
		element = nullptr;
		delete elementDelete;
	}

	else if ((element->leftChild == nullptr) || (element->rightChild == nullptr)) // удаление элемента с одним сыном
	{
		if (element->leftChild == nullptr)
		{
			element = element->rightChild;
		}
		else
		{
			element = element->leftChild;
		}
		delete elementDelete;
	}
}

TreeElement*& findReplacement(TreeElement*& element)
{
	if (element->rightChild != nullptr)
	{
		return findReplacement(element->rightChild);
	}
	return element;
}

bool deleteTreeElement(Tree* treeRoot, TreeElement*& element, const string& deleteKey)
{
	if (element == nullptr)
	{
		return false;
	}
	else if (element->key == deleteKey)
	{
		if ((element->leftChild != nullptr) && (element->rightChild != nullptr)) // удаление элемента с двумя сыновьями
		{
			TreeElement*& replacement = findReplacement(element->leftChild);
			
			element->key = replacement->key;	// копирует значение заменителя в удаляемый элемент
			element->value = replacement->value;
			
			deleteSimpleCase(replacement);		// удаляет заменитель
		}
		else
		{
			deleteSimpleCase(element);
		}

		checkBalance(element, treeRoot);
		return true;
	}
	else if (element->key < deleteKey)
	{
		return deleteTreeElement(treeRoot, element->rightChild, deleteKey);
	}
	else
	{
		return deleteTreeElement(treeRoot, element->leftChild, deleteKey);
	}

	checkBalance(element, treeRoot);
}

bool removeTreeElement(Tree* tree, const string& removeKey)
{
	if (isEmptyTree(tree))
	{
		return false;
	}
	return deleteTreeElement(tree, tree->head, removeKey);
}

void deleteAllElements(TreeElement*& element, Tree* tree)
{
	if (element == nullptr)
	{
		return;
	}
	deleteAllElements(element->leftChild, tree);
	deleteAllElements(element->rightChild, tree);
	deleteSimpleCase(element);
}

void deleteTree(Tree* tree)
{
	if (!isEmptyTree(tree))
	{
		deleteAllElements(tree->head, tree);
	}
	delete tree;
}