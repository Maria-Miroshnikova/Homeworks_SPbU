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

		if (newDistance != 0)   // если это не стартовая вершина
		{
			addGraphEdge(mst, newNode->label, newParentNode->label, newDistance);   // добавляем новое ребро в остов
		}

		ListEntry* connectedEdge = newNode->connectedNodes->head;
		for (int i = 0; i < countSizeOfList(newNode->connectedNodes); ++i)   // перерасчет приоритетов для вершин, смежных с новодобавленной
		{
			QueueEntry* findNodeInQueue = (findQueueEntry(queue, connectedEdge->edge->endNode));

			if ((findNodeInQueue != nullptr) && (findNodeInQueue->element->priority > connectedEdge->edge->distance))   // если смежная вершина еще не в остове и приоритет большем чем расстояние между ней и новодобавленной
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

	Graph* mst = createGraph();   // будущее минимальное остовное дерево

	Graph* graph = createGraph();
	inputMatrix(graph);

	Queue* queue = createQueue();   // записываем в очередь вершины
	
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