#include "workingWithData.h"
#include "myGraph.h"
#include "myQueue.h"
#include <limits>
#include <iostream>

using namespace std;

void makeMSTPrim(Graph* mst, Graph* graph, Queue* queue)
{
	while (!isEmptyQueue(queue))
	{
		GraphNode* newNode = nullptr;
		GraphNode* newParentNode = nullptr;
		int newDistance = 0;
		getQueueEntry(queue, newNode, newParentNode, newDistance);

		if (newDistance != 0)   // ���� ��� �� ��������� �������
		{
			addGraphEdge(mst, newNode->label, newParentNode->label, newDistance);   // ��������� ����� ����� � �����
		}

		ListEntry* connectedEdge = newNode->connectedNodes->head;
		for (int i = 0; i < countSizeOfList(newNode->connectedNodes); ++i)   // ���������� ����������� ��� ������, ������� � ���������������
		{
			QueueEntry* findNodeInQueue = (findQueueEntry(queue, connectedEdge->edge->endNode));

			if ((findNodeInQueue != nullptr) && (findNodeInQueue->element->priority > connectedEdge->edge->distance))   // ���� ������� ������� ��� �� � ������ � ��������� ������� ��� ���������� ����� ��� � ���������������
			{
				changePrioriryAndParent(queue, findNodeInQueue, newNode, connectedEdge->edge->distance);
			}
			connectedEdge = connectedEdge->next;
		}
	}
}

void workingWithData()
{
	const int infinity = INT_MAX;

	Graph* mst = createGraph();   // ������� ����������� �������� ������

	Graph* graph = createGraph();
	inputMatrix(graph);

	Queue* queue = createQueue();   // ���������� � ������� �������
	
	const int beginningNode = 0;

	for (int i = 0; i < graph->nodes.size(); ++i)
	{
		if (i == beginningNode)
		{
			addQueueEntry(queue, graph->nodes[i], nullptr, 0);
		}
		else
		{
			addQueueEntry(queue, graph->nodes[i], nullptr, infinity);
		}
	}

	makeMSTPrim(mst, graph, queue);

	outputGraph(mst);

	deleteGraph(graph);
	deleteQueue(queue);
	deleteGraph(mst);
}