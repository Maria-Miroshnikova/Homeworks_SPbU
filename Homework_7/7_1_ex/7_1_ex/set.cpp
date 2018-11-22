#include "set.h"
#include <stdio.h>
#include <vector>

using namespace std;

struct SetElement
{
	int value;
	SetElement *leftChild;
	SetElement *rightChild;
};

struct Set
{
	SetElement *head;
};

Set* createSet()
{
	Set* set = new Set { nullptr };
	return set;
}

bool isEmptySet(Set* set)
{
	return (set->head == nullptr);
}

SetElement* findSetEelement(Set* set, int findValue)
{
	if (isEmptySet(set))
	{
		return nullptr;
	}
	SetElement* element = set->head;
	while (true)
	{
		if (element->value > findValue)
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
		else if (element->value < findValue)
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

bool addSetElement(Set* set, int newValue)
{
	if (findSetEelement(set, newValue) != nullptr)
	{
		return false;
	}
	SetElement* newElement = new SetElement { newValue, nullptr, nullptr };
	if (isEmptySet(set))
	{
		set->head = newElement;
		return true;
	}
	SetElement* element = set->head;
	while (true)
	{
		if (element->value > newValue)
		{
			if (element->leftChild == nullptr)
			{
				element->leftChild = newElement;
				return true;
			}
			else
			{
				element = element->leftChild;
			}
		}
		else
		{
			if (element->rightChild == nullptr)
			{
				element->rightChild = newElement;
				return true;
			}
			else
			{
				element = element->rightChild;
			}
		}
	}
}

void dfs(SetElement* element, bool isIncreasingSequence, vector<int>& sequence)
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
	sequence.push_back(element->value);
	if (isIncreasingSequence)
	{
		dfs(element->rightChild, isIncreasingSequence, sequence);
	}
	else
	{
		dfs(element->leftChild, isIncreasingSequence, sequence);
	}
}

bool outputSetElements(Set* set, bool isIncreasingSequesnce, vector<int>& sequence)
{
	if (!isEmptySet(set))
	{
		dfs(set->head, isIncreasingSequesnce, sequence);
		return true;
	}
	return false;
}

void deleteSimpleCase(SetElement*& element)
{
	SetElement* elementDelete = element;

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

SetElement*& findReplacement(SetElement*& element)
{
	if (element->rightChild != nullptr)
	{
		return findReplacement(element->rightChild);
	}
	return element;
}

bool deleteElement(SetElement*& element, int deleteValue)
{
	if (element == nullptr)
	{
		return false;
	}
	else if (element->value == deleteValue)
	{
		if ((element->leftChild != nullptr) && (element->rightChild != nullptr)) // удаление элемента с двумя сыновьями
		{
			SetElement*& replacement = findReplacement(element->leftChild);
			element->value = replacement->value; // копирует значение заменителя в удаляемый элемент
			deleteSimpleCase(replacement);		// удаляет заменитель
		}
		else
		{
			deleteSimpleCase(element);
		}
		return true;
	}
	else if (element->value < deleteValue)
	{
		return deleteElement(element->rightChild, deleteValue);
	}
	else
	{
		return deleteElement(element->leftChild, deleteValue);
	}
}

bool removeSetElement(Set* set, int removeValue)
{
	if (isEmptySet(set))
	{
		return false;
	}
	return deleteElement(set->head, removeValue);
}

void deleteAllElements(SetElement*& element, Set* set)
{
	if (element == nullptr)
	{
		return;
	}
	deleteAllElements(element->leftChild, set);
	deleteAllElements(element->rightChild, set);
	deleteSimpleCase(element);
}

void deleteSet(Set* set)
{
	if (!isEmptySet(set))
	{
		deleteAllElements(set->head, set);
	}
	delete set;
}