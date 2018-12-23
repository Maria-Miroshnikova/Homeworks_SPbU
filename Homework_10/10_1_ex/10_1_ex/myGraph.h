#pragma once
#include "myList.h";
#include <vector>

struct List;

/// ������� �����, ���������� ���� ��������, ������ ��������� � ����� ������������
struct GraphNode
{
	int label;
	bool conquered;
	List* connectedNodes;
};

/// ���������� �����, ���������� ��������� �� ��������� � �������� ������� � ���������� ����� ����
struct WeightedEdge
{
	int distance;
	GraphNode* startNode;
	GraphNode* endNode;
};

/// ����, ��������� �� �������, �������� �������� - ��������� �� ������� �����
struct Graph
{
	std::vector<GraphNode*> nodes;
};

/// ������� ����, ��������� ��������� �� ����
Graph* createGraph();

/// ���� � ����� ������� � �������� ��������� � ���������� ������ �� ���
GraphNode* findGraphNode(Graph* graph, int findLabel);

/// ��������� � ���� ����� � ��������� ��������� � �������� ��������� � ����������� ����� ����
bool addGraphEdge(Graph* graph, int startNode, int endNode, int distance);

/// ������� ���� �� ����� (��������������)
void outputGraph(Graph* graph);

/// ��������� ������� ����� � ������ ��������� �������� �������
bool findEdgeInList(GraphNode* node, int findEndNode);

/// ������� ����
void deleteGraph(Graph* graph);