#include <iostream>
#include <fstream>
#include "tests.h"
#include "interface.h"

using namespace std;

int main()
{
	//cout << "Now program is testing, please, wait..." << endl;
	//tests();
	//cout << "Test are OK!" << endl;
	cout << endl << "This program will count the number of repetitions of each word in text ";
	cout << endl << "from file 'data.txt' without punctuation marks (excluding apostrophe: ' ).";
	cout << endl << "Please, don`t use such sequences: <letters, numbers><MARKS><letters, numbers>.";
	cout << endl << endl << "The size of hash table is 10 now. If you want to change it, ";
	cout << endl << "see 'interface.cpp': void workingWithData.";
	cout << endl << endl << "Hash table is: " << endl << endl;

	ifstream dataFile("data.txt", ios::in);
	if (!dataFile)
	{
		return 1;
	}

	workingWithData(dataFile);

	dataFile.close();
	return 0;
}