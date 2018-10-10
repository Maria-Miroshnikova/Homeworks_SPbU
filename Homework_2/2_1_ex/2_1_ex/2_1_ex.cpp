#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>

int recursiveFibonacci(int n)
{
	if ((n == 0) || (n == 1))
	{
		return 1;
	}
	else
	{
		return recursiveFibonacci(n - 1) + recursiveFibonacci(n - 2);
	}
}

int iterationFibonacci(int n)
{
	int fibonacciOne = 0;
	int fibonacciTwo = 1;
	for (int i = 1; i <= n; ++i)
	{
		const int tmp = fibonacciOne;
		fibonacciOne = fibonacciTwo;
		fibonacciTwo += tmp;
	}
	return fibonacciTwo;
}

/////////////////////////////

bool tests(int index)
{
	int test1 = 1;
	int answer1 = 1;
	int test2 = 2;
	int answer2 = 1;
	int test3 = 3;
	int answer3 = 2;
	int test4 = 9;
	int answer4 = 34;
	if ((iterationFibonacci(test1 - 1) != answer1) || (recursiveFibonacci(test1 - 1) != iterationFibonacci(test1 - 1)))
	{
		printf("Test 1 is not ok.\n");
		return false;
	}
	if ((iterationFibonacci(test2 - 1) != answer2) || (recursiveFibonacci(test2 - 1) != iterationFibonacci(test2 - 1)))
	{
		printf("Test 2 is not ok.\n");
		return false;
	}
	if ((iterationFibonacci(test3 - 1) != answer3) || (recursiveFibonacci(test3 - 1) != iterationFibonacci(test3 - 1)))
	{
		printf("Test 3 is not ok.\n");
		return false;
	}
	if ((iterationFibonacci(test4 - 1) != answer4) || (recursiveFibonacci(test4 - 1) != iterationFibonacci(test4 - 1)))
	{
		printf("Test 4 is not ok.\n");
		return false;
	}
	return true;
}

/////////////////////////

int main()
{
	printf("In this program F(1) = 1, F(2) = 1, F(3) = 2, etc.\n");
	printf("Please, enter the index of Fibonacci number which you want to see:\n");
	int index = 0;
	scanf("%d", &index);
	assert(index > 0);
	printf("Now program is testing, please, wait.\n");
	if (!tests(index))
	{
		return 0;
	}
	printf("Tests is ok!\n");
	int way = 0;
	printf("Which way would you prefer: 1 - recursive, 2 - iteration? Please, enter 1 or 2:\n");
	scanf("%d", &way);
	assert((way == 1) || (way == 2));
	if (way == 1)
	{
		index = recursiveFibonacci(index - 1);
	}
	else
	{
		index = iterationFibonacci(index - 1);
	}
	printf("%d", index);
	return 0;
}