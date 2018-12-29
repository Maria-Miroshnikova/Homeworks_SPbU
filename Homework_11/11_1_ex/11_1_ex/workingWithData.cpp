#include "workingWithData.h"
#include "myAlgorithm.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

bool workingWithData()
{
	ifstream dataFile("data.txt", ios::in);
	if (!dataFile)
	{
		return false;
	}

	string data = "";
	getline(dataFile, data);
	dataFile.close();
	cout << endl << "String is: " << data << endl;

	string sample = "";
	cout << endl << "Please, input the sample: ";
	cin >> sample;

	int meetingPosition = findFirstMeeting(data, sample);

	if (meetingPosition == -1)
	{
		cout << endl << "There is no meeting of sample in the srting!" << endl;
	}
	else
	{
		cout << endl << "The position of first meeting is: " << meetingPosition << endl;
	}

	return true;
}