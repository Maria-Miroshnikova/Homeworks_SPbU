#pragma once
#include "myList.h";
#include <vector>

struct List;

struct GraphNode
{
	int label;
	List* connectedNodes;
};

struct WeightedEdge
{
	int distance;
	GraphNode* startNode;
	GraphNode* endNode;
};

struct Graph
{
	std::vector<GraphNode*> nodes;
};

Graph* createGraph();

bool addGraphEdge(Graph* graph, int startNode, int endNode, int distance);

void outputGraph(Graph* graph);

bool findEdgeInList(GraphNode* node, int findEndNode);

void deleteGraph(Graph* graph);

/// принимает матрицу инцедентности и строит по ней неориентированный взвешенный граф
void inputMatrix(Graph* graph);