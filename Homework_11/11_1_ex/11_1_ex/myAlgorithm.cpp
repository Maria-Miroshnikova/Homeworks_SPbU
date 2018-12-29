#include "myAlgorithm.h"
#include <string>
#include <vector>

using namespace std;

bool isGoodOldChar(const string& data, vector<int>& prefixValue, const char newChar, int i)
{
	return (newChar == data[prefixValue[i]]);	// ����� �������� ����� ������ � ������������� �������� ��� �������� ���������
}

void prefixFunction(const string& data, vector<int>& prefixValue)
{
	prefixValue.push_back(0);	// � ��������� �����, ��������� �� 1 �������, ��� ������������� ����������� ��������� � ���������

	for (int i = 1; i < strlen(data.c_str()); ++i)
	{
		int indexChek = i - 1;

		if (i == 17)
		{
			int k = 0;
		}

		while ((indexChek >= 0) && (!isGoodOldChar(data, prefixValue, data[i], indexChek)))
		{
			indexChek = prefixValue[indexChek] - 1;
		}

		if (indexChek < 0)	// �� ������� ����������
		{
			prefixValue.push_back(0);
		}
		else
		{
			prefixValue.push_back(prefixValue[indexChek] + 1);
		}
	}
}

int findFirstMeeting(const string& data, const string& sample)
{
	vector<int> prefixValue;
	prefixFunction(sample, prefixValue);

	int indexSample = 0;
	int i = 0;

	while (i < strlen(data.c_str()))
	{
		while (sample[indexSample] == data[i])
		{
			++i;
			++indexSample;
			if (indexSample == strlen(sample.c_str()))	// ������� ��� �������
			{
				return i - indexSample;
			}
		}

		if (indexSample == 0)
		{
			++i;
		}
		else
		{
			indexSample = prefixValue[indexSample - 1];
		}
	}
	return -1;
}