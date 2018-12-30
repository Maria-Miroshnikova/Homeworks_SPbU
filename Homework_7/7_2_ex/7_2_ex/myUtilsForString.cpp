#include "myUtilsForString.h"
#include <string>

using namespace std;

bool getNewSimbol(const string& data, size_t& i)
{
	if (i >= data.length())
	{
		return false;
	}
	else
	{
		++i;
		return true;
	}
}

bool getNewChar(const string& data, size_t& i)
{
	if (!getNewSimbol(data, i))
	{
		return false;
	}
	while ((data[i] == '(') || (data[i] == ')') || (data[i] == ' '))
	{
		if (!getNewSimbol(data, i))
		{
			return false;
		}
	}
	return true;
}