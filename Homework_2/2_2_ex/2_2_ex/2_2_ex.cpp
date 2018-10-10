#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>

long long exponentLoop(int number, int exponent)
{
	long long result = number;
	for (int i = 1; i < exponent; ++i)
	{
		result *= number;
	}
	return result;
}

void findOperationWay(int length, int operations[], int exponent)
{
	int numberOfOperation = 0;
	while (exponent > 1)
	{
		if (exponent % 2 == 0)
		{
			exponent = exponent / 2;
			operations[numberOfOperation] = 2;
			++numberOfOperation;
		}
		else
		{
			exponent = exponent - 1;
			operations[numberOfOperation] = 1;
			++numberOfOperation;
		}
	}
}

long long exponentLog(int number, int exponent)
{
	int operationCount = exponent / 2;
	int *operations = new int[operationCount + 1]{};
	findOperationWay(operationCount, operations, exponent);
	long long result = number;
	for (int i = operationCount + 1; i >= 0; --i)
	{
		if (operations[i] == 1)
		{
			result *= number;
		}
		if (operations[i] == 2)
		{
			result *= result;
		}
	}
	delete[] operations;
	return result;
}

long long pathSelection(int number, int exponent, int way)
{
	long long result = 0;
	int signNumber = 1;
	if (number < 0)
	{
		number = -number;
		signNumber = -1;
	}
	if (way == 1)
	{
		result = exponentLoop(number, exponent);
	}
	else
	{
		result = exponentLog(number, exponent);
	}
	if ((signNumber == -1) && (exponent % 2 != 0))
	{
		result = -result;
	}
	return result;
}

int specialCase(int number, int exponent)
{
	if ((exponent == 0) || (number == 1) || ((number == -1) && (exponent % 2 == 0)))
	{
		return 1;
	}
	if ((exponent == 1) || (number == 0))
	{
		return number;
	}
	if (number == -1)
	{
		return -1;
	}
}

bool isSpecialCase(int number, int exponent)
{
	if ((exponent == 0) || (exponent == 1) || (number == 1) || (number == -1) || (number == 0))
	{
		return true;
	}
	return false;
}

void itIsDoneNews()
{
	printf("It is done: ");
}

void problemNews(int problem)
{
	printf("Your input is incorrect: ");
	if (problem == 1)
	{
		printf("forbidden exponent.");
	}
	if (problem == 2)
	{
		printf("nonexistent way of multiplication.");
	}
	else
	{
		printf("0 ^ 0 - uncertainty.");
	}
}

/////////////////////////////////////////////////////////////////////////////

void tests()
{
	const int testCount = 10;
	long long numbers[testCount]{ 0, 1, -1, -1, 5, -5, -5, 2, 9, -9 };
	long long exponents[testCount]{ 9, 9, 9, 8, 6, 6, 7, 35, 0, 1 };
	long long answers[testCount]{ 0, 1, -1, 1, 15625, 15625, -78125, 34359738368, 1, -9 };
	for (int i = 0; i < testCount; ++i)
	{
		long long result1 = -2;
		long long result2 = -3;
		if (isSpecialCase(numbers[i], exponents[i]))
		{
			result1 = specialCase(numbers[i], exponents[i]);
			result2 = result1;
		}
		else
		{
			result1 = pathSelection(numbers[i], exponents[i], 1);
			result2 = pathSelection(numbers[i], exponents[i], 2);
		}
		assert((result1 == result2) && (result2 == answers[i]));
	}
}

/////////////////////////////////////////////////////////////////////////////

int main()
{
	printf("Now program is testing, please, wait.\n");
	tests();
	printf("Tests are ok!\n");
	printf("This program can work only with natural and zero exponents.\n");
	printf("Please, enter the number which you want to multiplicate:\n");
	int number = 0;
	scanf("%d", &number);
	printf("Please, enter the exponent:\n");
	int exponent = 0;
	scanf("%d", &exponent);
	if (exponent <= 0)
	{
		if ((exponent == 0) && (number == 0))
		{
			problemNews(3);
			return 0;
		}
		if (exponent < 0)
		{
			problemNews(1);
			return 0;
		}
	}
	long long result = 0;
	if (isSpecialCase(number, exponent))
	{
		result = specialCase(number, exponent);
		itIsDoneNews();
		printf("%lli", result);
		return 0;
	}
	printf("Which way of multiplication would you prefer: 1 - loop, 2 - log? Please, enter 1 or 2:\n");
	int way = 0;
	scanf("%d", &way);
	if ((way != 1) && (way != 2))
	{
		problemNews(2);
		return 0;
	}
	result = pathSelection(number, exponent, way);
	printf("%lli", result);
	return 0;
}