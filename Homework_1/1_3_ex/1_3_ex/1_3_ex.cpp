#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void change(int x[], int i, int middle, int len)
{
	int end = 0;
	for (i; i < middle; ++i) {
		x[i] = (x[i]) ^ (x[len - end]);
		x[len - end] = (x[i]) ^ (x[len - end]);
		x[i] = (x[i]) ^ (x[len - end]);
		end++;
	}
}

int main()
{
	int m, n;
	printf("Please, enter the length of the first and the second part of the array: \n");
	scanf("%d %d", &m, &n);
	const int length = m + n;
	int * x = new int[length];
	printf("Please, enter the array: \n");
	for (int i = 0; i < length; ++i) {
		scanf("%d", &x[i]);
	}
	const int start1 = 0;
	const int start2 = m;
	change(x, start1, m / 2, length - n - 1);
	change(x, start2, (length + m) / 2, length - 1);
	change(x, start1, length / 2, length - 1);
	for (int i = 0; i < length; ++i) {
		printf("%d", x[i]);
	}
	delete[] x;
	return 0;
}