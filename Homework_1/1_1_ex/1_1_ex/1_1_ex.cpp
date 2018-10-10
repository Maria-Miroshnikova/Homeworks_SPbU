#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int x;
	scanf("%d", &x);
	const int secondDegree = x * x;
	int polynomial = (secondDegree + 1) * (secondDegree + x) + 1;
	printf("%d", polynomial);
	return 0;
}