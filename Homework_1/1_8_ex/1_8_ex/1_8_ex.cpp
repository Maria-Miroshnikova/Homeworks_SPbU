#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	printf("%s\n", "Please, enter len(array)");
	int len;
	scanf("%d", &len);
	int *theArray = new int[len];
	int null = 0;
	printf("%s\n", "Please, enter array");
	for (int i = 0; i < len; ++i) {
		scanf("%d", &theArray[i]);
	}
	for (int i = 0; i < len; ++i) {
		if (theArray[i] == 0) {
			null++;
		}
	}
	printf("%d", null);
	delete[] theArray;
	return 0;
}