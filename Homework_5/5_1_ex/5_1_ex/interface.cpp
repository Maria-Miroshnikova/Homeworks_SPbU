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
				addEntryList(list->head, parameterInt);
			}
			parameter = "";
		}
		else if (command == commands[2])
		{
			cout << "Please, enter the number to delete: ";
			cin >> parameter;
			parameterInt = strtol(parameter.c_str(), &end, 10);
			if ((parameterInt == 0) && (*end == parameter[0]))
			{
				cout << "Error: incorrect data!" << endl;
			}
			else
			{
				if (!deleteEntryList(list->head, parameterInt))
				{
					cout << endl << "The number " << parameterInt << " NOT found in the list!" << endl;
				}
			}
			parameter = "";
		}
		else if (command == commands[3])
		{
			if (!outputList(list, listForOutput))
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