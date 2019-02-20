#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include "myUtils.h"
#include "myQuickSort.h"
#include "tests.h"
#include "myUtilsForFiles.h"
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	cout << "Now program is testing, please, wait.";
	tests();
	cout << endl << "Tests are ok!" << endl << endl;
	ifstream inputData("inputData.txt", ios::in);
	if (!inputData)
	{
		cout << endl << "File - inputData.txt - not found!";
		return 1;
	}

	vector<int> arrayForSort;
	readArrayFromFile(inputData, arrayForSort);
	
	outputVector(arrayForSort);
	cout << endl << endl;

	int left = 0;
	int right = arrayForSort.size() - 1;
	quickSort(arrayForSort, left, right);
	
	outputVector(arrayForSort);
	cout << endl << endl;

	int oftenElement = findOftenElement(arrayForSort);
	
	cout << "The most often element is: " << oftenElement << endl;

	inputData.close();
	return 0;
}