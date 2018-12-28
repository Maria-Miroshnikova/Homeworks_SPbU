#include "myQueue.h"
#include <vector>

using namespace std;

Queue* createQueue()
{
	Queue* queue = new Queue { nullptr };
	return queue;
}

bool isEmptyQueue(Queue* queue)
{
	return (queue->head == nullptr);
}

void addQueueEntry(Queue* queue, GraphNode* newNode, GraphNode* parentNode, int distance)
{
	QueueElement* newElement = new QueueElement{ newNode, parentNode, distance };
	QueueEntry* newEntry = new QueueEntry{ newElement, nullptr };

	if (isEmptyQueue(queue))
	{
		queue->head = newEntry;
		return;
	}

	QueueEntry* entry = queue->head;
	if (entry->element->priority > newEntry->element->priority)   // если место элемента сразу в голове очереди
	{
		queue->head = newEntry;
		newEntry->next = entry;
		return;
	}

	while (entry->element->priority <= newEntry->element->priority)
	{
		if (entry->next == nullptr)   // если место элемента в конце очереди
		{
			entry->next = newEntry;
			break;
		}
		else if (entry->next->element->priority > newEntry->element->priority)   //   если место элемента между рассматриваемым и следующим элементами
		{
			QueueEntry* nextEntry = entry->next;
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

bool makeOutputQueue(Queue* queue, vector<GraphNode*>& sequence)
{
	if (isEmptyQueue(queue))
	{
		return false;
	}

	QueueEntry* entry = queue->head;
	while (entry != nullptr)
	{
		sequence.push_back(entry->element->node);
		entry = entry->next;
	}
	return true;
}

bool deleteQueueEntry(Queue* queue)
{
	if (isEmptyQueue(queue))
	{
		return false;
	}

	QueueEntry* deleteEntry = queue->head;
	queue->head = queue->head->next;
	delete deleteEntry->element;
	delete deleteEntry;
	return true;
}

void deletePaticularyQueueEntry(Queue* queue, QueueEntry* deleteEntry)
{
	QueueEntry* entry = queue->head;

	if (entry == deleteEntry)
	{
		deleteQueueEntry(queue);
		return;
	}

	while (entry->next != nullptr)
	{
		if (entry->next == deleteEntry)
		{
			entry->next = deleteEntry->next;
			
			delete deleteEntry->element;
			delete deleteEntry;

			return;
		}
		entry = entry->next;
	}

}

void deleteQueue(Queue* queue)
{
	while (!isEmptyQueue(queue))
	{
		deleteQueueEntry(queue);
	}
	delete queue;
}

bool getQueueEntry(Queue* queue, GraphNode*& node, GraphNode*& parentNode, int& priority)
{
	if (isEmptyQueue(queue))
	{
		return false;
	}

	QueueEntry* getNode = queue->head;
	node = getNode->element->node;
	parentNode = getNode->element->parent;
	priority = getNode->element->priority;

	deleteQueueEntry(queue);

	return true;
}

QueueEntry* findQueueEntry(Queue* queue, GraphNode* findNode)
{
	QueueEntry* entry = queue->head;
	while (entry != nullptr)
	{
		if (entry->element->node == findNode)
		{
			return entry;
		}
		entry = entry->next;
	}
	return nullptr;
}

void changePrioriryAndParent(Queue* queue, QueueEntry* entry, GraphNode* newParent, int newPriority)
{
	GraphNode* node = entry->element->node;

	deletePaticularyQueueEntry(queue, entry);

	addQueueEntry(queue, node, newParent, newPriority);
}