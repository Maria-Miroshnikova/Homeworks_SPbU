#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int len;
	scanf("%d\n", &len);
	char *brackets = new char[len];
	for (int i = 0; i < len; ++i) {
		scanf("%c", &brackets[i]);
	}
	int goodBracket = 0;
	for (int i = 0; i < len; ++i) {
		if (brackets[i] == '(') {
			goodBracket++;
		}
		if (brackets[i] == ')') {
			if (goodBracket == 0) {
				goodBracket = -1;
				break;
			}
			else {
				goodBracket--;
			}
		}
	}
	if (goodBracket == 0) {
		printf("%s", "True");
		delete[] brackets;
		return 0;
	}
	printf("%s", "False");
	delete[] brackets;
	return 0;
}