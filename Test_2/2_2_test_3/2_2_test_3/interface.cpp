#include "interface.h"
#include "myList.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cassert>

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
		line = "";
	}
	help.close();
}

void outputVector(vector<int>& vectorOut)
{
	for (int i = 0; i < vectorOut.size(); ++i)
	{
		cout << vectorOut[i] << endl;
	}
}

void getCommand()
{
	vector<string> commands = { "0", "1", "2", "3", "HELP" };
	List* list = createList();
	string command = "";
	string parameter = "";
	int parameterInt = 0;
	int secondParameterInt = 0;
	char* end = nullptr;
	vector<int> listForOutput;

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
				parameter = "";
				cout << "Please, enter the position to add: ";
				cin >> parameter;
				secondParameterInt = strtol(parameter.c_str(), &end, 10);
				if (((secondParameterInt == 0) && (*end == parameter[0])) || (secondParameterInt < 0))
				{
					cout << "Error: incorrect data!" << endl;
				}
				else
				{
					if (!addListEntry(list, parameterInt, secondParameterInt))
					{
						cout << endl << "The size of list is less than your position! " << endl;
					}
				}
			}
			parameter = "";
		}
		else if (command == commands[2])
		{
			cout << "Please, enter the position of list element to delete: ";
			cin >> parameter;
			parameterInt = strtol(parameter.c_str(), &end, 10);
			if (((parameterInt == 0) && (*end == parameter[0])) || ((parameterInt < 0)))
			{
				cout << "Error: incorrect data!" << endl;
			}
			else
			{
				if (!deleteListEntry(list, parameterInt))
				{
					cout << endl << "The size of list is less than your position! " << endl;
				}
			}
			parameter = "";
		}
		else if (command == commands[3])
		{
			if (!makeOutputList(list, listForOutput))
			{
				cout << endl << "The list is empty!" << endl;
			}
			else
			{
				cout << endl << "The list is:" << endl << endl;
				outputVector(listForOutput);
				listForOutput.resize(0);
			}
		}
		else if (command == commands[4])
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
	deleteList(list);
}