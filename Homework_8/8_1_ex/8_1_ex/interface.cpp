#include "interface.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cassert>
#include "tree.h"

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

void getCommand()
{
	vector<string> commands = { "0", "1", "2", "3", "4", "HELP" };
	Tree* tree = createTree();
	string command = "";
	string parameter = "";
	string parameterOdd = "";

	help();
	cout << endl << "Please, enter the command: ";
	cin >> command;
	while (command != commands[0])
	{
		if (command == commands[1])
		{
			cout << "Please, enter the key to add: ";
			cin >> parameter;

			cout << "Please, enter the value for this key: ";
			cin >> parameterOdd;

			addTreeElement(tree, parameter, parameterOdd);
			
			parameter = "";
			parameterOdd = "";
		}
		else if (command == commands[2])
		{
			cout << "Please, enter the key which value you want to find: ";
			cin >> parameter;

			if (!findTreeEelement(tree, parameter))
			{
				cout << endl << "The key '" << parameter << "' NOT found in the array!" << endl;
			}
			else
			{
				cout << endl << "The value is: " << getValue(tree, parameter) << endl;
			}
	
			parameter = "";
		}
		else if (command == commands[3])
		{
			cout << "Please, enter the key which existence you want to check: ";
			cin >> parameter;

			if (!existsKey(tree, parameter))
			{
				cout << endl << "The key '" << parameter << "' NOT found in the array!" << endl;
			}
			else
			{
				cout << endl << "The key '" << parameter << "' found in the array!" << endl;
			}

			parameter = "";
		}
		else if (command == commands[4])
		{
			cout << "Please, enter the key to delete: ";
			cin >> parameter;

			if (!removeTreeElement(tree, parameter))
			{
				cout << endl << "The key '" << parameter << "' NOT found int the array!" << endl;
			}

			parameter = "";
		}
		else if (command == commands[5])
		{
			cout << endl;
			help();
			cout << endl;
		}
		else
		{
			cout << endl << "Error: wrong command! Please, enter HELP to see the list of commands!" << endl;
		}
		command = "";
		cout << endl << endl << "Please, enter the command: ";
		cin >> command;
	}
	deleteTree(tree);
}