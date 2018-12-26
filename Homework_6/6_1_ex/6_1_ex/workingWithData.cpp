#include "workingWithData.h"
#include "myStack.h"
#include <iostream>
#include <string>

using namespace std;

int countExpressionValue(int amountOfData)
{
	Stack* stack = createStack();
	string data = "";
	for (int i = 0; i < amountOfData; ++i)
	{
		cin >> data;
		
		if (data == "*")
		{	
			push(stack, pop(stack) * pop(stack));
		}
		else if (data == "/")
		{
			int firsValue = pop(stack);
			int secondValue = pop(stack);
			push(stack, secondValue / firsValue);
		}
		else if (data == "+")
		{
			push(stack, pop(stack) + pop(stack));
		}
		else if (data == "-")
		{
			int firsValue = pop(stack);
			int secondValue = pop(stack);
			push(stack, secondValue - firsValue);
		}

		else
		{
			push(stack, strtol(data.c_str(), nullptr, 10));
		}

		data = "";
	}

	int expressionValue = pop(stack);
	deleteStack(stack);
	return expressionValue;
}

void workingWithData()
{
	cout << endl << "Please, input the count of numbers and operations: ";
	int amountOfData = 0;
	cin >> amountOfData;

	cout << endl << "Please, input the expression in postfix form:" << endl << endl;

	cout << endl << "The expression value is : " << countExpressionValue(amountOfData) << endl;
}