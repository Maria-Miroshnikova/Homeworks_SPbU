#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void sieveErato(int *numbers, int n, int prime)
{
	if (prime < n) {
		for (int i = prime + 1; i <= n; ++i) {
			if ((numbers[i] % prime == 0) && (numbers[i] != -1)) {
				numbers[i] = -1;
			}
		}
		int nextPrime = prime;
		for (int i = prime + 1; i <= n; ++i) {
			if (numbers[i] != -1) {
				nextPrime = numbers[i];
				break;
			}
		}
		if (nextPrime != prime) {
			sieveErato(numbers, n, nextPrime);
		}
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	int *numbers = new int[n + 1];
	if (n <= 1) {
		printf("%s", "There is no prime numbers!");
		return 0;
	}
	for (int i = 1; i <= n; ++i) {
		numbers[i] = i;
	}
	sieveErato(numbers, n, numbers[2]);
	for (int i = 2; i <= n; ++i) {
		if (numbers[i] != -1) {
			printf("%d ", numbers[i]);
		}
	}
	delete[] numbers;
	return 0;
}