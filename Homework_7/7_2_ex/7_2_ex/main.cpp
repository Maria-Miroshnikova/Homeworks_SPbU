#include "workingWithData.h"
#include "tests.h"
#include <string>
#include <iostream>

using namespace std;

int main()
{
	cout << "Now program is testing, please, wait..." << endl;
	tests();
	cout << "Tests are OK!" << endl;

	getData();
	return 0;
}