#include "workingWithData.h"
#include <fstream>
#include <string>
#include "tree.h"
#include <iostream>
#include "myUtilsForString.h"

using namespace std;

bool getData()
{
	ifstream dataFile("data.txt", ios::in);
	if (!dataFile)
	{
		return false;
	}

	string data = "";
	getline(dataFile, data);

	Tree* tree = createTree();
	
	makeExpressionTree(tree, data);

	cout << endl << "The expression is: " << endl << data << endl;
	cout << endl << "The value of expression is: " << countExpression(tree) << endl;

	deleteTree(tree);
	return true;
}