#include "workingWithData.h"
#include "tests.h"
#include <iostream>

using namespace std;

int main()
{
	cout << "Now program is testing, please, wait..." << endl;
	tests();
	cout << "Tests are OK!" << endl;

	if (!workingWithData())
	{
		return 1;
	}

	return 0;
}
