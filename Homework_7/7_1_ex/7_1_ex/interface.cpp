#include "interface.h"
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <cassert>
#include "set.h"

using namespace std;

void help()
{
	ifstream help("HELP.txt", ios::in);
	assert(help);
	cout << endl;
	string line = "";
	while (!help.eof())
	{
		getline(help, line);
		cout << line << endl;
	}
	help.close();
}

void outputVector(vector<int> vectorOut)
{
	for (int i = 0; i < vectorOut.size(); ++i)
	{
		cout << vectorOut[i] << " ";
	}
	cout << endl;
}

void getCommand()
{
	vector <string> commands = { "0", "1", "2", "3", "4", "5", "HELP" };
	Set* set = createSet();
	string command = "";
	string parameter = "";
	char* end = nullptr;
	long int parameterInt = 0;
	vector<int> sequence;

	help();
	cout << endl << "Please, enter the command: ";
	cin >> command;
	while (command != commands[0])
	{
		if (command == commands[1])
		{
			cout << "Please, enter the number to add: ";
			cin >> parameter;
			parameterInt = strtol(parameter.c_str(), &end, 10);
			if ((parameterInt == 0) && (*end == parameter[0]))
			{
				cout << "Error: incorrect data!" << endl;
			}
			else
			{
				if (!addSetElement(set, parameterInt))
				{
					cout << endl << "The number " << parameterInt << " is already in the set!" << endl;
				}
			}
			parameter = "";
		}
		else if (command == commands[2])
		{
			cout << "Please, enter the number to remove: ";
			cin >> parameter;
			parameterInt = strtol(parameter.c_str(), &end, 10);
			if ((parameterInt == 0) && (*end == parameter[0]))
			{
				cout << "Error: incorrect data!" << endl;
			}
			else
			{
				if (!removeSetElement(set, parameterInt))
				{
					cout << endl << "The number " << parameterInt << " NOT found int the set!" << endl;
				}
			}
			parameter = "";
		}
		else if (command == commands[3])
		{
			cout << "Please, enter the number to find: ";
			cin >> parameter;
			parameterInt = strtol(parameter.c_str(), &end, 10);
			if ((parameterInt == 0) && (*end == parameter[0]))
			{
				cout << "Error: incorrect data!" << endl;
			}
			else
			{
				if (!findSetEelement(set, parameterInt))
				{
					cout << endl << "The number " << parameterInt << " NOT found in the set!" << endl;
				}
				else
				{
					cout << endl << "The number " << parameterInt << " found in the set!" << endl;
				}
			}
			parameter = "";
		}
		else if (command == commands[4])
		{
			if (!outputSetElements(set, 1, sequence))
			{
				cout << endl << "The set is empty!" << endl;
			}
			else
			{
				cout << endl << "Increasing sequence:" << endl;
				outputVector(sequence);
			}
			sequence.resize(0);
		}
		else if (command == commands[5])
		{
			if (!outputSetElements(set, 0, sequence))
			{
				cout << endl << "The set is empty!" << endl;
			}
			else
			{
				cout << endl << "Decreasing sequence:" << endl;
				outputVector(sequence);
			}
			sequence.resize(0);
		}
		else if (command == commands[6])
		{
			help();
		}
		else
		{
			cout << endl << "Error: wrong command! Please, enter HELP to see the list of commands!" << endl;
		}
		command = "";
		cout << endl << "Please, enter the command: ";
		cin >> command;
	}
	deleteSet(set);
}