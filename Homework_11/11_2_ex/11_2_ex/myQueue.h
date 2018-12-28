#pragma once
#include <vector>
#include "myGraph.h"

/// ������� �������, ���������� ��������� �� ������� �����, �� �������, �� �������
/// �� ��� ���������� ����, � ��������� (����������)
struct QueueElement
{
	GraphNode* node;
	GraphNode* parent;
	int priority;
};

/// ������� �������, ���������� ��������� �� ��������� � ������� � ��� � ��������� �� ��������� �������
struct QueueEntry
{
	QueueElement* element;
	QueueEntry* next;
};

/// ��������� �� ������ ������� � ������������
struct Queue
{
	QueueEntry* head;
};

/// ���������, �������� �� ������� ������
bool isEmptyQueue(Queue* queue);

/// ������� ������ ������� � ���������� ��������� �� ���
Queue* createQueue();

/// ��������� ������ � ������������� �� �������� � �������� �� �������� ���������� �������, �������� �������
void addQueueEntry(Queue* queue, GraphNode* newNode, GraphNode* parentNode, int distance);

/// ���������� ������� � ������, ���� ��� �� �����,
/// � ���������� true, ����� ���������� false.
bool makeOutputQueue(Queue* queue, std::vector<GraphNode*>& sequence);

/// ������� ������ �� ������� � ���������� true, ���� ��� ��� ����,
/// ����� ���������� false (� ���������, ���� ������ ��� ����)
bool deleteQueueEntry(Queue* queue);

/// ������� �������
void deleteQueue(Queue* queue);

/// ���������� � ������� ���������� ���������� ��������� �� ������� � ������������ ������� �
/// �������� ����������, � ���������� false, ���� ������� �� �����, ����� ���������� false
bool getQueueEntry(Queue* queue, GraphNode*& node, GraphNode*& parentNode, int& priority);

/// ���� ������� � ������� � ���������� ��������� �� ������� �������, ���������� ��
QueueEntry* findQueueEntry(Queue* queue, GraphNode* findNode);

/// �������� ��������� � �������� ���������� ������ �� ������� �� ������,
/// ������������� �������, ������ ������ ������ �� ������� � �������� ������.
void changePrioriryAndParent(Queue* queue, QueueEntry* entry, GraphNode* newParent, int newPriority);