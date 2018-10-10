#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	if (b == 0) {
		printf("Division by zero\n");
		return 0;
	}
	int sign = 1;
	if (a * b <= 0) {
		sign = -1;
	}
	if (a < 0) {
		a = -a;
	}
	if (b < 0) {
		b = -b;
	}
	int quotient = 0;
	while (a >= b) {
		a -= b;
		quotient++;
	}
	printf("%d", quotient * sign);
	return 0;
}