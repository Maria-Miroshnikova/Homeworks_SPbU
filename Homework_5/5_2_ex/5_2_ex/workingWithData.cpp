#include "workingWithData.h"
#include "myList.h"
#include <iostream>

using namespace std;

int findTheSurvivor(int countMen, int numberToKill)
{
	List* listSicarii = createList();
	for (int i = 1; i <= countMen; ++i)
	{
		addListEntry(listSicarii, i);
	}

	ListEntry* nextToDie = listSicarii->head;

	for (int i = 1; i < countMen; ++i)
	{
		int k = 1;
		while (k != numberToKill)
		{
			nextToDie = nextToDie->next;
			++k;
		}
		ListEntry* manToKill = nextToDie;
		nextToDie = manToKill->next;
		deleteListEntry(listSicarii, manToKill->value);
	}

	int survivor = listSicarii->head->value;
	deleteList(listSicarii);
	return survivor;
}

void workingWithData()
{
	cout << endl << "Please, enter the count of men: ";
	int countMen = 0;
	cin >> countMen;
	if (countMen < 2)
	{
		cout << endl << "Wrong data!" << endl;
		return;
	}

	cout << endl << "Please, enter the number of man to kill.";
	cout << endl << "Consider that counting starts from one: ";
	int numberToKill = 0;
	cin >> numberToKill;
	if (numberToKill < 1)
	{
		cout << endl << "Wrong data!" << endl;
		return;
	}

	cout << endl << "The survivor`s position is: " << findTheSurvivor(countMen, numberToKill) << endl;
}