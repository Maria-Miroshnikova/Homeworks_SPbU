#pragma once
#include "myList.h";
#include <vector>

struct List;

/// вершина графа, содержащая свои значение, список смежности и метку посещенности
struct GraphNode
{
	int label;
	bool conquered;
	List* connectedNodes;
};

/// взвешенное ребро, содержащее указатели на начальную и конечную вершины и расстояние между ними
struct WeightedEdge
{
	int distance;
	GraphNode* startNode;
	GraphNode* endNode;
};

/// граф, состоящий из вектора, элементы которого - указатели на вершины графа
struct Graph
{
	std::vector<GraphNode*> nodes;
};

/// создает граф, возвращая указатель на него
Graph* createGraph();

/// ищет в графе вершину с заданным значением и возвращает ссылку на нее
GraphNode* findGraphNode(Graph* graph, int findLabel);

/// добавляем в граф ребро с заданными начальной и конечной вершинами и расстоянием между ними
bool addGraphEdge(Graph* graph, int startNode, int endNode, int distance);

/// выводит граф на экран (вспомогательно)
void outputGraph(Graph* graph);

/// проверяет наличие ребра в списке смежности заданной вершины
bool findEdgeInList(GraphNode* node, int findEndNode);

/// удаляет граф
void deleteGraph(Graph* graph);