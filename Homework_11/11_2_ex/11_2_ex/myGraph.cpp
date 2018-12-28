#include "myGraph.h"
#include <vector>
#include "myList.h"
#include <iostream>

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
	GraphNode* newNode = new GraphNode{ node, connectedListForNode };
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

	WeightedEdge* newStartEdge = new WeightedEdge{ distance, findStartNode, findEndNode };
	addListEntry(findStartNode->connectedNodes, newStartEdge);

	WeightedEdge* newEndEdge = new WeightedEdge{ distance, findEndNode, findStartNode };
	addListEntry(findEndNode->connectedNodes, newEndEdge);

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

void makeGraphFromMatrix(Graph* graph, vector<vector<int>>& matrix)
{
	for (int column = 0; column < matrix[0].size(); ++column)
	{
		int firstNode = 0;
		int secondNode = 0;
		int distance = 0;

		for (int line = 0; line < matrix.size(); ++line)
		{
			if (matrix[line][column] > 0)
			{
				if (firstNode != 0)
				{
					secondNode = line + 1;
					addGraphEdge(graph, firstNode, secondNode, distance);
					break;
				}
				firstNode = line + 1;
				distance = matrix[line][column];
			}
		}
	}
}

void inputMatrix(Graph* graph)
{
	int countNodes = 0;
	cout << endl << "Please, enter the count of nodes: ";
	cin >> countNodes;
	int countEdges = 0;
	cout << endl << "Please, enter the count of edges: ";
	cin >> countEdges;

	cout << endl << "Please, enter the matrix of connections:" << endl << endl;
	vector<vector<int>> matrix;
	for (int line = 0; line < countNodes; ++line)
	{
		vector<int> newLine;
		matrix.push_back(newLine);

		for (int column = 0; column < countEdges; ++column)
		{
			int distance = 0;
			cin >> distance;
			matrix[line].push_back(distance);
		}
	}

	makeGraphFromMatrix(graph, matrix);
}

/*

6
10

1 1 1 1 0 0 0 0 0 0
1 0 0 0 1 1 0 0 0 0
0 1 0 0 1 0 1 0 0 0
0 0 1 0 0 1 1 1 1 0
0 0 0 0 0 0 0 1 0 1
0 0 0 1 0 0 0 0 1 1


7
11

7 5 0 0 0 0 0 0 0 0 0
7 0 8 9 7 0 0 0 0 0 0
0 0 8 0 0 0 0 5 0 0 0
0 5 0 9 0 15 6 0 0 0 0
0 0 0 0 7 15 0 5 8 9 0
0 0 0 0 0 0 6 0 8 0 11
0 0 0 0 0 0 0 0 0 9 11

*/