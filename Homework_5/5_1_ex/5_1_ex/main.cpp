#include "interface.h"
#include "tests.h"
#include "iostream"

using namespace std;

int main()
{
	cout << "Now program is testing, please, wait..." << endl;
	tests();
	cout << "Tests are OK!" << endl;
	getCommand();
	return 0;
}