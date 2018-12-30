#include "myList.h"
#include <vector>
#include "myGraph.h"

using namespace std;

struct ListEntry;

struct List;

List* createList()
{
	List *list = new List{ nullptr };
	return list;
}

bool isEmptyList(List* list)
{
	return (list->head == nullptr);
}

void addListEntry(List* list, WeightedEdge* newElement)
{
	ListEntry* newEntry = new ListEntry{ newElement, nullptr };

	if (isEmptyList(list))   // если список пуст
	{
		list->head = newEntry;
		return;
	}

	ListEntry* entry = list->head;
	if (entry->edge->endNode->label > newElement->endNode->label)   // если место элемента сразу в голове списка
	{
		list->head = newEntry;
		newEntry->next = entry;
		return;
	}

	while (entry->edge->endNode->label <= newElement->endNode->label)
	{
		if (entry->next == nullptr)   // если место элемента в конце списка
		{
			entry->next = newEntry;
			break;
		}
		else if (entry->next->edge->endNode->label > newElement->endNode->label)   //   если место элемента между рассматриваемым и следующим элементами
		{
			ListEntry* nextEntry = entry->next;
			entry->next = newEntry;
			newEntry->next = nextEntry;
			break;
		}
		else   // если можно опуститься вниз по списку
		{
			entry = entry->next;
		}
	}
}

bool makeOutputList(List* list, vector<WeightedEdge*>& sequence)
{
	if (isEmptyList(list))
	{
		return false;
	}

	ListEntry* entry = list->head;
	while (entry != nullptr)
	{
		sequence.push_back(entry->edge);
		entry = entry->next;
	}
	return true;
}

bool deleteListEntry(List* list, int deleteValue)
{
	if (isEmptyList(list))   // если список пуст
	{
		return false;
	}

	ListEntry* deleteEntry = list->head;

	if (deleteEntry->edge->endNode->label == deleteValue) // если искомый элемент сразу в голове списка
	{
		list->head = deleteEntry->next;
		delete deleteEntry->edge;
		delete deleteEntry;
		return true;
	}

	if (deleteEntry->edge->endNode->label > deleteValue)   // если в списке только большие элементы
	{
		return false;
	}

	while (deleteEntry->edge->endNode->label < deleteValue)
	{
		if (deleteEntry->next == nullptr)   //  если дошли до конца списка
		{
			return false;
		}
		else if (deleteEntry->next->edge->endNode->label > deleteValue)   // если следующий элемент больше, а рассматриваемый - меньше искомого
		{
			return false;
		}
		else if (deleteEntry->next->edge->endNode->label < deleteValue)   // если можно спуститься по списку
		{
			deleteEntry = deleteEntry->next;
		}
		else   // следующий элемент - искомый
		{
			if (deleteEntry->next->next == nullptr)   // если искомый элемент - последний в списке
			{
				delete deleteEntry->next->edge;
				delete deleteEntry->next;
				deleteEntry->next = nullptr;
				return true;
			}
			else   // если искомый элемент посреди списка
			{
				ListEntry* nextEntry = deleteEntry->next->next;
				delete deleteEntry->next->edge;
				delete deleteEntry->next;
				deleteEntry->next = nextEntry;
				return true;
			}
		}
	}
}

void deleteList(List* list)
{
	while (!isEmptyList(list))
	{
		deleteListEntry(list, list->head->edge->endNode->label);
	}
	delete list;
}

int countSizeOfList(List* list)
{
	int size = 0;
	ListEntry* entry = list->head;
	while (entry != nullptr)
	{
		++size;
		entry = entry->next;
	}
	return size;
}

bool findEdgeInList(GraphNode* node, int findEndNode)
{
	if (isEmptyList(node->connectedNodes))
	{
		return false;
	}

	ListEntry* entry = node->connectedNodes->head;
	while (entry != nullptr)
	{
		if (entry->edge->endNode->label == findEndNode)
		{
			return true;
		}
		entry = entry->next;
	}
	return false;
}