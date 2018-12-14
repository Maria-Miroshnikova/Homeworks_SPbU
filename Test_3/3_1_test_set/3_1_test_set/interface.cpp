#include "interface.h"
#include "set.h"
#include <iostream>
#include <vector>

using namespace std;

void outputVectors(vector<int>& outputNumbers, vector<int>& outputCounts)
{
	for (int i = 0; i < outputNumbers.size(); ++i)
	{
		cout << outputNumbers[i] << " (" << outputCounts[i] << ")" << endl;
	}
}

void workingWithData()
{
	int data = -1;
	cin >> data;

	if (data == 0)
	{
		cout << endl << "No data!" << endl;
		return;
	}

	Set* numberSet = createSet();

	while (data != 0)
	{
		addSetElement(numberSet, data);
		cin >> data;
	}

	vector<int> outputNumbers;
	vector<int> outputCounts;

	outputSetElements(numberSet, outputNumbers, outputCounts);

	cout << endl << "Numbers and (count):" << endl << endl;

	outputVectors(outputNumbers, outputCounts);

	deleteSet(numberSet);
}