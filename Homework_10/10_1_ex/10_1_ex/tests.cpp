#include "tests.h"
#include "workingWithData.h"
#include "myGraph.h"
#include <cassert>
#include <fstream>
#include <string>
#include "workingWithData.h"
#include <iostream>

using namespace std;

bool readTestDataFromFile(string& data, istream& file)
{
	if (file.eof())
	{
		data = "";
		return false;
	}
	getline(file, data);
	if (data == "\0")
	{
		data = "";
		getline(file, data);
	}
	return true;
};

bool makeGraphFromFile(Graph* graph, istream& testDataFile, string& data, vector<Country*>& testCountries)
{
	int testCountNodes = 0;
	int testCountEdges = 0;
	int testCountCapitals = 0;

	if (!readTestDataFromFile(data, testDataFile))
	{
		return false;
	}
	testCountNodes = strtol(data.c_str(), nullptr, 10);
	data = "";

	readTestDataFromFile(data, testDataFile);
	testCountEdges = strtol(data.c_str(), nullptr, 10);
	data = "";

	int startNode = 0;
	int endNode = 0;
	int distance = 0;

	for (int i = 0; i < testCountEdges; ++i)
	{
		testDataFile >> startNode >> endNode >> distance;
		addGraphEdge(graph, startNode, endNode, distance);
	}

	readTestDataFromFile(data, testDataFile);
	testCountCapitals = strtol(data.c_str(), nullptr, 10);
	data = "";

	int newTestCapitalLabel = 0;
	for (int i = 0; i < testCountCapitals; ++i)
	{
		readTestDataFromFile(data, testDataFile);
		newTestCapitalLabel = strtol(data.c_str(), nullptr, 10);
		data = "";

		GraphNode* newCapital = findGraphNode(graph, newTestCapitalLabel);

		newCapital->conquered = 1;   // столицы изначально посещены
		Country* newCountry = new Country{ newCapital, 0, {} };
		testCountries.push_back(newCountry);
	}
	return true;
}

void tests()
{
	ifstream testDataFile("testData.txt", ios::in);
	assert(testDataFile);
	ifstream testAnswerFile("testAnswer.txt", ios::in);
	assert(testAnswerFile);

	vector<Country*> testCountries;
	string data = "";
	string answer = "";

	while (!testDataFile.eof())
	{
		while (true)
		{
			Graph* testGraph = createGraph();

			if (!makeGraphFromFile(testGraph, testDataFile, data, testCountries))
			{
				deleteGraph(testGraph);
				break;
			}

			makeCountries(testGraph, testCountries);

			for (int i = 0; i < testCountries.size(); ++i)
			{
				for (int j = 0; j < testCountries[i]->cities.size(); ++j)
				{
					readTestDataFromFile(answer, testAnswerFile);
					assert((testCountries[i]->cities[j]->label) == strtol(answer.c_str(), nullptr, 10));
					answer = "";
				}
			}

			deleteGraph(testGraph);
			deleteCountries(testCountries);
			testCountries.resize(0);

		}
	}

	testDataFile.close();
	testAnswerFile.close();
}