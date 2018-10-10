#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	const int len = 28;
	int summ = 0;
	int summs[len]{};
	const int maxx = 9;
	for (int i = 0; i <= maxx; ++i) {
		for (int j = 0; j <= maxx; ++j) {
			for (int k = 0; k <= maxx; ++k) {
				summs[i + j + k]++;
			}
		}
	}
	for (int i = 0; i < len; ++i) {
		summ += summs[i] * summs[i];
	}
	printf("%d", summ);
	return 0;
}