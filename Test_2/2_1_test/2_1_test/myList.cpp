#include "myList.h"
#include <vector>
#include "myStack.h"

List* createList()
{
	List *list = new List{ nullptr };
	return list;
}

bool isEmptyList(List* list)
{
	return (list->head == nullptr);
}

void addListEntry(List* list, int newValue)
{
	ListEntry* newEntry = new ListEntry{ newValue, nullptr };
	
	if (isEmptyList(list))   // если список пуст
	{
		list->head = newEntry;
		return;
	}

	ListEntry* entry = list->head;
	while (entry->next != nullptr)
	{
		entry = entry->next;
	}
	entry->next = newEntry;
	
	return;
}

bool makeOutputList(List* list, std::vector<int>& sequence)
{
	if (isEmptyList(list))
	{
		return false;
	}
	
	ListEntry* entry = list->head;
	while (entry != nullptr)
	{
		sequence.push_back(entry->value);
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

	if (deleteEntry->value == deleteValue) // если искомый элемент сразу в голове списка
	{
		list->head = deleteEntry->next;
		delete deleteEntry;
		return true;
	}

	if (deleteEntry->value > deleteValue)   // если в списке только большие элементы
	{
		return false;
	}

	while (deleteEntry->value < deleteValue)   
	{
		if (deleteEntry->next == nullptr)   //  если дошли до конца списка
		{
			return false;
		}
		else if (deleteEntry->next->value > deleteValue)   // если следующий элемент больше, а рассматриваемый - меньше искомого
		{
			return false;
		}
		else if (deleteEntry->next->value < deleteValue)   // если можно спуститься по списку
		{
			deleteEntry = deleteEntry->next;
		}
		else   // следующий элемент - искомый
		{
			if (deleteEntry->next->next == nullptr)   // если искомый элемент - последний в списке
			{
				delete deleteEntry->next;
				deleteEntry->next = nullptr;
				return true;
			}
			else   // если искомый элемент посреди списка
			{
				ListEntry* nextEntry = deleteEntry->next->next;
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
		deleteListEntry(list, list->head->value);
	}
	delete list;
}

bool swapList(List* list)
{
	if (isEmptyList(list))
	{
		return false;
	}

	Stack* stack = createStack();
	ListEntry* nextElement = list->head;
	
	while (nextElement != nullptr)
	{
		push(stack, nextElement->value);
		nextElement = nextElement->next;
	}

	nextElement = list->head;
	while (nextElement != nullptr)
	{
		nextElement->value = pop(stack);
		nextElement = nextElement->next;
	}

	deleteStack(stack);
	return true;
}