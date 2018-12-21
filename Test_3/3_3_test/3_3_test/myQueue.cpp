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

void addQueueEntry(Queue* queue, GraphNode* newNode)
{
	QueueEntry* newEntry = new QueueEntry{ newNode, nullptr };

	if (isEmptyQueue(queue))
	{
		queue->head = newEntry;
		return;
	}

	QueueEntry* entry = queue->head;
	while (entry->next != nullptr)
	{
		entry = entry->next;
	}
	entry->next = newEntry;
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
		sequence.push_back(entry->node);
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
	delete deleteEntry;

}

void deleteQueue(Queue* queue)
{
	while (!isEmptyQueue(queue))
	{
		deleteQueueEntry(queue);
	}
	delete queue;
}

GraphNode* getQueueEntry(Queue* queue)
{
	if (isEmptyQueue(queue))
	{
		return nullptr;
	}

	GraphNode* getNode = queue->head->node;
	deleteQueueEntry(queue);

	return getNode;
}