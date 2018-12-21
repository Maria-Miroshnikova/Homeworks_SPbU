#include "myGraph.h"
#include <vector>
#include "myQueue.h"
#include <iostream>

using namespace std;

struct NodeAndParents
{
	GraphNode* node;
	vector<GraphNode*> parents;
};

struct IsReachebleNode
{
	bool visited;
	GraphNode* node;
};

void outputNodesAndParents(vector<NodeAndParents*> nodesAndParents)
{
	for (int i = 0; i < nodesAndParents.size(); ++i)
	{
		cout << endl << "the node is " << nodesAndParents[i]->node->label << " and parents:" << endl << endl;
		for (int j = 0; j < nodesAndParents[i]->parents.size(); ++j)
		{
			cout << nodesAndParents[i]->parents[j]->label << endl;
		}
	}
}

void specialBFS(GraphNode* startNode, vector<NodeAndParents*>& nodesAndParents)
{
	Queue* queue = createQueue();
	addQueueEntry(queue, startNode);

	while (!isEmptyQueue(queue))
	{
		GraphNode* node = getQueueEntry(queue);
		node->isVisited = true;
		cout << "now in " << node->label << endl;

		ListEntry* nextNode = node->connectedNodes->head;
		while (nextNode != nullptr)
		{
			for (int i = 0; i < nodesAndParents.size(); ++i)
			{
				if (nextNode->edge->endNode == nodesAndParents[i]->node)
				{
					bool notFound = true;
					for (int k = 0; k < nodesAndParents[i]->parents.size(); ++k)
					{
						if (nodesAndParents[i]->parents[k] == node)
						{
							notFound = false;
						}
					}

					if (notFound)
					{
						nodesAndParents[i]->parents.push_back(node);
					}
				}
			}

			if (!nextNode->edge->endNode->isVisited)
			{
				addQueueEntry(queue, nextNode->edge->endNode);
				nextNode->edge->endNode->isVisited = true;
			}
			nextNode = nextNode->next;
		}
	}
}

IsReachebleNode* findIsReachable(vector<IsReachebleNode*>& isReachebale, GraphNode* node)
{
	for (int i = 0; i < isReachebale.size(); ++i)
	{
		if (isReachebale[i]->node == node)
		{
			return isReachebale[i];
		}
	}
}

void findReachableNodes()
{
	Graph* graph = createGraph();
	inputMatrix(graph);

	vector<NodeAndParents*> nodesAndParents;
	for (int i = 0; i < graph->nodes.size(); ++i)
	{
		NodeAndParents* newNode = new NodeAndParents{ graph->nodes[i], {} };
		nodesAndParents.push_back(newNode);
	}

	for (int i = 0; i < nodesAndParents.size(); ++i)
	{
		specialBFS(nodesAndParents[i]->node, nodesAndParents);
		for (int j = 0; j < graph->nodes.size(); ++j)
		{
			graph->nodes[i]->isVisited = false;
		}
	}

//	outputNodesAndParents(nodesAndParents);

	vector<IsReachebleNode*> isReachebale;

	for (int i = 0; i < graph->nodes.size(); ++i)
	{
		IsReachebleNode* newNode = new IsReachebleNode{ false, graph->nodes[i] };
		isReachebale.push_back(newNode);
	}

	for (int i = 0; i < nodesAndParents.size(); ++i)
	{
		for (int k = 0; k < nodesAndParents[i]->parents.size(); ++k)
		{
			findIsReachable(isReachebale, nodesAndParents[i]->parents[k])->visited = true;
		}

		for (int j = 0; j < graph->nodes.size(); ++j)
		{
			graph->nodes[i]->isVisited = false;
		}
	}

	vector<GraphNode*> reachebaleNodes;

	deleteGraph(graph);
}

