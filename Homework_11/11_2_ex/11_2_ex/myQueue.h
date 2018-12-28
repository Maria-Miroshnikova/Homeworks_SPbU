#pragma once
#include <vector>
#include "myGraph.h"

/// элемент очереди, содержащий указатель на вершину графа, на вершину, из которой
/// до нее кратчайший путь, и приоритет (расстояние)
struct QueueElement
{
	GraphNode* node;
	GraphNode* parent;
	int priority;
};

/// элемент очереди, содержащий указатель на структуру с данными о нем и указатель на следующий элемент
struct QueueEntry
{
	QueueElement* element;
	QueueEntry* next;
};

/// указатель на начало очереди с приоритетами
struct Queue
{
	QueueEntry* head;
};

/// проверяет, является ли очередь пустой
bool isEmptyQueue(Queue* queue);

/// создает пустую очередь и возвращает указатель на нее
Queue* createQueue();

/// добавляет запись в сортированную от меньшего к большему по значению приоритету очередь, сохраняя порядок
void addQueueEntry(Queue* queue, GraphNode* newNode, GraphNode* parentNode, int distance);

/// записывает очередь в вектор, если она не пуста,
/// и возвращает true, иначе возвращает false.
bool makeOutputQueue(Queue* queue, std::vector<GraphNode*>& sequence);

/// удаляет запись из очереди и возвращает true, если она там была,
/// иначе возвращает false (в частности, если список был пуст)
bool deleteQueueEntry(Queue* queue);

/// удаляет очередь
void deleteQueue(Queue* queue);

/// записывает в заранее заведенные переменные указатели на вершниу и родительскую вершину и
/// значение приоритета, и возвращает false, если очередь не пуста, иначе возвращает false
bool getQueueEntry(Queue* queue, GraphNode*& node, GraphNode*& parentNode, int& priority);

/// ищет вершину в очереди и возвращает указатель на элемент очереди, содержащий ее
QueueEntry* findQueueEntry(Queue* queue, GraphNode* findNode);

/// изменяет приоритет и родителя конкретной записи из очереди на данные,
/// перестраивает очередь, удаляя данную запись из очереди и добавляя заново.
void changePrioriryAndParent(Queue* queue, QueueEntry* entry, GraphNode* newParent, int newPriority);