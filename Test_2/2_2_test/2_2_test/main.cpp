#include <fstream>
#include "workingWithData.h"
#include <iostream>
#include "tests.h"

using namespace std;

int main()
{
	cout << "Now program is testing, please, wait..." << endl;
	tests();
	cout << "Tests are OK!" << endl << endl;

	cout << "This program will check if the list from file 'data.txt' is symmetric." << endl << endl;

	ifstream dataFile("data.txt", ios::in);
	if (!dataFile)
	{
		dataFile.close();
		return 1;
	}
	
	if (workingWithData(dataFile))
	{
		cout << "The list is symmetric!" << endl;
	}
	else
	{
		cout << "The list is NOT symmetric!" << endl;
	}

	dataFile.close();
	return 0;
}