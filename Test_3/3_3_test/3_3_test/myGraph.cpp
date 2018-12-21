#include "myGraph.h"
#include <vector>
#include "myList.h"
#include <iostream>
#include "myQueue.h"

using namespace std;

struct GraphNode;

struct WeightedEdge;

struct Graph;

Graph* createGraph()
{
	Graph* graph = new Graph {};
	return graph;
}

GraphNode* findGraphNode(Graph* graph, int findLabel)
{
	for (int i = 0; i < graph->nodes.size(); ++i)
	{
		if (graph->nodes[i]->label == findLabel)
		{
			return graph->nodes[i];
		}
	}
	return nullptr;
}

void addGraphNode(Graph* graph, GraphNode** findNode, int node)
{
	List* connectedListForNode = createList();
	GraphNode* newNode = new GraphNode{ node, 0, connectedListForNode };
	graph->nodes.push_back(newNode);
	*findNode = newNode;
}

bool addGraphEdge(Graph* graph, int startNode, int endNode, int distance)
{
	GraphNode* findStartNode = findGraphNode(graph, startNode);
	GraphNode* findEndNode = findGraphNode(graph, endNode);

	if (findStartNode == nullptr)   // если начальной вершины нет, создаем ее
	{
		addGraphNode(graph, &findStartNode, startNode);
	}

	if (findEdgeInList(findStartNode, endNode))   // проверка на попытку добавить кратное ребро
	{
		return false;
	}

	if (findEndNode == nullptr)   // если конечной вершины нет, создаем ее
	{
		if (startNode == endNode)   // петля
		{
			findEndNode = findStartNode;
		}
		else
		{
			addGraphNode(graph, &findEndNode, endNode);
		}
	}

	WeightedEdge* newEdge = new WeightedEdge{ distance, findStartNode, findEndNode };
	addListEntry(findStartNode->connectedNodes, newEdge);
	return true;
}

void deleteGraph(Graph* graph)
{
	for (int i = 0; i < graph->nodes.size(); ++i)
	{
		deleteList(graph->nodes[i]->connectedNodes);
		delete graph->nodes[i];
	}
	delete graph;
}

void outputGraph(Graph* graph)
{
	std::vector<WeightedEdge*> outputEdges;

	for (int i = 0; i < graph->nodes.size(); ++i)
	{
		std::cout << std::endl << "the Node is (" << graph->nodes[i]->label << ") :" << std::endl << std::endl;
		if (makeOutputList(graph->nodes[i]->connectedNodes, outputEdges))
		{
			for (int j = 0; j < outputEdges.size(); ++j)
			{
				std::cout << outputEdges[j]->startNode->label << " ---> " << outputEdges[j]->endNode->label << " : " << outputEdges[j]->distance << std::endl;
			}
		}
		else
		{
			std::cout << "no connected nodes!" << std::endl;
		}

		std::cout << std::endl;
		outputEdges.resize(0);
	}
}

void inputMatrix(Graph* graph)
{
	int sizeMatrix = 0;
	cout << endl << "Please, enter the size of matrix: ";
	cin >> sizeMatrix; 
	cout << endl << "Please, enter the matrix of connections:" << endl << endl;
	for (int line = 0; line < sizeMatrix; ++line)
	{
		for (int column = 0; column < sizeMatrix; ++column)
		{
			int distance = 0;
			cin >> distance;
			if (distance > 0)   // для взвешенного графа прием при расстоянии > 0;
			{
				addGraphEdge(graph, line + 1, column + 1, distance);
			}
		}
	}
}

void dfs(GraphNode* startNode)
{
	if (startNode == nullptr)
	{
		return;
	}

	++startNode->isVisited;
	cout << "now in " << startNode->label << endl;
	ListEntry* nextNode = startNode->connectedNodes->head;
	while (nextNode != nullptr)
	{
		if (!nextNode->edge->endNode->isVisited)
		{
			dfs(nextNode->edge->endNode);
		}
		nextNode = nextNode->next;
	}

}

void bfs(GraphNode* startNode)
{
	Queue* queue = createQueue();
	addQueueEntry(queue, startNode);

	while (!isEmptyQueue(queue))
	{
		GraphNode* node = getQueueEntry(queue);
		++node->isVisited;
		cout << "now in " << node->label << endl;
		
		ListEntry* nextNode = node->connectedNodes->head;
		while (nextNode != nullptr)
		{
			if (!nextNode->edge->endNode->isVisited)
			{
				addQueueEntry(queue, nextNode->edge->endNode);
				++nextNode->edge->endNode->isVisited;
			}
			nextNode = nextNode->next;
		}
	}
}