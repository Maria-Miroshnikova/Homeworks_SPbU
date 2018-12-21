#pragma once
#include <vector>
#include "myGraph.h"

/// элемент списка, содержащий значение и указатель на следующий элемент
struct QueueEntry
{
	GraphNode* node;
	QueueEntry* next;
};

/// указатель на начало списка
struct Queue
{
	QueueEntry* head;
};

/// проверяет, является ли список пустым
bool isEmptyQueue(Queue* queue);

/// создает пустой список и возвращает указатель на него
Queue* createQueue();

/// добавляет запись в сортированный список, сохраняя порядок
void addQueueEntry(Queue* queue, GraphNode* newNode);

/// записывает список в вектор, если список не пуст,
/// и возвращает true, иначе возвращает false.
bool makeOutputQueue(Queue* queue, std::vector<GraphNode*>& sequence);

/// удаляет запись из списка и возвращает true, если она там была,
/// иначе возвращает false (в частности, если список был пуст)
bool deleteQueueEntry(Queue* queue);

/// удаляет список
void deleteQueue(Queue* queue);

GraphNode* getQueueEntry(Queue* queue);