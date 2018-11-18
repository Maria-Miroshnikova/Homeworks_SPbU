#include <iostream>
#include "interface.h"
#include "tests.h"

using namespace std;

int main()
{
	cout << "Now program is testing, please, wait..." << endl;
	tests();
	cout << "Tests are OK!" << endl;
	getCommand();
	return 0;
}