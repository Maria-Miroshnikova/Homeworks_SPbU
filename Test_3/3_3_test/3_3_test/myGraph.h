#pragma once
#include "myList.h";
#include <vector>

struct List;

struct GraphNode
{
	int label;
	bool isVisited;
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

void inputMatrix(Graph* graph);

void dfs(GraphNode* startNode);

void bfs(GraphNode* startNode);