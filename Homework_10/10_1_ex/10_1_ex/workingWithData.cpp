#include "workingWithData.h"
#include "myGraph.h"
#include "myList.h"
#include <vector>
#include <iostream>
#include <limits>

using namespace std;

struct Country;

void outputCountries(vector<Country*>& countries)
{
	for (int i = 0; i < countries.size(); ++i)
	{
		cout << endl << "The country with the capital (" << countries[i]->capital->label << ") :" << endl;
		
		if (countries[i]->cities.size() == 0)
		{
			cout << endl << "The country is consists of capital only!" << endl;
		}

		for (int j = 0; j < countries[i]->cities.size(); ++j)
		{
			cout << countries[i]->cities[j]->label << endl;
		}
	}
}

bool getData(Graph* graph, vector<Country*>& countries, int& countNodes, int& countEdges)
{
	cout << endl << "Please, input the count of cities: ";
	cin >> countNodes;
	if (countNodes < 2)
	{
		if (countNodes == 1)
		{
			cout << endl << "The country (1) includes only the capital!" << endl;
			return false;
		}
		cout << endl << "Incorrect data!" << endl;
		return false;
	}

	cout << endl << "Please, input the count of roads: ";
	cin >> countEdges;
	if (countEdges < 1)
	{
		cout << endl << "Incorrect data!" << endl;
		return false;
	}

	cout << endl << "Please, input: <city1> <city2> <distance>" << endl << endl;

	int startNode = 0;
	int endNode = 0;
	int distance = 0;

	for (int i = 0; i < countEdges; ++i)
	{
		cin >> startNode >> endNode >> distance;
		addGraphEdge(graph, startNode, endNode, distance);
	}

	int countCapitals = 0;
	cout << endl << "Please, input the count of capitals: ";
	cin >> countCapitals;
	if (countCapitals < 1)
	{
		cout << endl << "Incorrect data!" << endl;
		return false;
	}

	cout << endl << "Please, input all capitals:" << endl;
	int newCapitalLabel = 0;
	for (int i = 0; i < countCapitals; ++i)
	{
		cin >> newCapitalLabel;
		GraphNode* newCapital = findGraphNode(graph, newCapitalLabel);
		
		newCapital->conquered = 1;   // столицы изначально посещены
		Country* newCountry = new Country{ newCapital, 0, {} };
		countries.push_back(newCountry);
	}
}

void makeCountries(Graph* graph, vector<Country*>& countries)
{
	int conqueredCities = countries.size();
	while (conqueredCities < graph->nodes.size())
	{
		for (int i = 0; i < countries.size(); ++i)
		{
			if (!countries[i]->done)
			{
				int minDistance = INT_MAX;
				GraphNode* nearestCity = nullptr;
				int distance = INT_MAX;
				GraphNode* city = nullptr;

				// проверяем столицу на наличие ближайшего незахваченного города
				distance = findMinNotConqueredNode(countries[i]->capital->connectedNodes, &city);
				if ((distance >= 0) && (distance < minDistance))
				{
					minDistance = distance;
					nearestCity = city;
				}

				// проверяем захваченные города на наличие ближайшего незахваченного города
				for (int j = 0; j < countries[i]->cities.size(); ++j)
				{
					distance = findMinNotConqueredNode(countries[i]->cities[j]->connectedNodes, &city);
					if ((distance >= 0) && (distance < minDistance))
					{
						minDistance = distance;
						nearestCity = city;
					}
				}

				// если доступных незахваченных городов не осталось, объявляем страну завершенной, исключая ее из раздачи
				if (nearestCity == nullptr)
				{
					++countries[i]->done;
				}

				// иначе найденный город объявляем захваченным, увеличиваем число захваченных городов, добавляем его в страну
				else
				{
					countries[i]->cities.push_back(nearestCity);
					++nearestCity->conquered;
					++conqueredCities;
					if (conqueredCities == graph->nodes.size())
					{
						break;
					}
				}
			}
		}
	}
}

void deleteCountries(vector<Country*>& countries)
{
	for (int i = 0; i < countries.size(); ++i)
	{
		countries[i]->cities.resize(0);
		delete countries[i];
	}
}

void workingWothData()
{
	Graph* graph = createGraph();
	vector<Country*> countries;
	int countNodes = 0;
	int countEdges = 0;
	
	if (!getData(graph, countries, countNodes, countEdges))
	{
		deleteGraph(graph);
		deleteCountries(countries);
		return;
	}

	makeCountries(graph, countries);

	outputCountries(countries);

	deleteGraph(graph);
	deleteCountries(countries);
}

