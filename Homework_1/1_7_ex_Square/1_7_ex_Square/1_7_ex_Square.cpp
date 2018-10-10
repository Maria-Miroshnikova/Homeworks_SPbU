#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int findRoot(int number)
{
	int root = 1;
	while ((root + 1) * (root + 1) <= number) {
		root++;
	}
	return root;
}

bool IsPrime(int number)
{
	int sqrtNumber = findRoot(number);
	for (int i = 2; i <= sqrtNumber; ++i) {
		if (number % i == 0) {
			return false;
		}
	}
	return true;
}

int main()
{
	int n;
	scanf("%d", &n);
	if (n <= 1) {
		printf("%s", "There is no prime numbers!");
		return 0;
	}
	bool *numbers = new bool[n];
	for (int i = 1; i <= n; ++i) {
		numbers[i] = true;
	}
	for (int i = 2; i <= n; ++i) {
		numbers[i] = IsPrime(i);
	}
	for (int i = 2; i <= n; ++i) {
		if (numbers[i]) {
			printf("%d ", i);
		}
	}
	return 0;
}