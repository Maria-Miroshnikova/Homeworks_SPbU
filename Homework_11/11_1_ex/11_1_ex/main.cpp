#include "workingWithData.h"
#include <iostream>

using namespace std;

int main()
{
	cout << endl << "This program will find the position of meeting sample in the string";
	cout << endl << "and output it. String gets from file 'data.txt'" << endl;
	
	if (!workingWithData())
	{
		cout << endl << "File 'data.txt' not found!" << endl;
		return 1;
	}

	return 0;
}