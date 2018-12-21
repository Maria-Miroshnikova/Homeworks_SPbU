#pragma once
#include <vector>
#include "myGraph.h"

/// ������� ������, ���������� �������� � ��������� �� ��������� �������
struct QueueEntry
{
	GraphNode* node;
	QueueEntry* next;
};

/// ��������� �� ������ ������
struct Queue
{
	QueueEntry* head;
};

/// ���������, �������� �� ������ ������
bool isEmptyQueue(Queue* queue);

/// ������� ������ ������ � ���������� ��������� �� ����
Queue* createQueue();

/// ��������� ������ � ������������� ������, �������� �������
void addQueueEntry(Queue* queue, GraphNode* newNode);

/// ���������� ������ � ������, ���� ������ �� ����,
/// � ���������� true, ����� ���������� false.
bool makeOutputQueue(Queue* queue, std::vector<GraphNode*>& sequence);

/// ������� ������ �� ������ � ���������� true, ���� ��� ��� ����,
/// ����� ���������� false (� ���������, ���� ������ ��� ����)
bool deleteQueueEntry(Queue* queue);

/// ������� ������
void deleteQueue(Queue* queue);

GraphNode* getQueueEntry(Queue* queue);