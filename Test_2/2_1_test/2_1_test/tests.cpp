#define _CRT_SECURE_NO_WARNINGS
#include "tests.h"
#include "myList.h"
#include "workingWithData.h"
#include <fstream>
#include <iostream>
#include <cassert>
#include <string>

using namespace std;



void tests()
{
	vector<int> testList1 = { 2, 0, 0, 0, -1, -1, -1, 3 };
	vector<int> testAnswer1 = { 3, -1, -1, -1, 0, 0, 0, 2 };

	vector<int> testList2 = { 1, 1, 2, 2 };
	vector<int> testAnswer2 = { 2, 2, 1, 1 };

	vector<int> testList3 = { };
	vector<int> testAnswer3 = { };

}