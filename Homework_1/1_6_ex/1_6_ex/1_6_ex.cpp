#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	printf("%s\n", "Please, enter: length[s] length[s1]");
	printf("%s\n", "Then, enter: s s1");
	int lenS, lenS1;
	scanf("%d %d\n", &lenS, &lenS1);
	char *s = new char[lenS + 1];
	char *s1 = new char[lenS1 + 1];
	int meeting = 0;
	scanf("%s %s", s, s1);
	for (int stepS = 0; stepS < lenS; ++stepS) {
		if ((s[stepS] == s1[0]) && ((lenS - stepS) >= lenS1)) {
			int i = stepS + 1;
			int same = 1;
			for (int stepS1 = 1; stepS1 < lenS1; ++stepS1) {
				if (s1[stepS1] == s[i]) {
					same++;
				}
				i++;
			}
			if (same == lenS1) {
				meeting++;
			}
		}
	}
	printf("%d", meeting);
	delete[] s;
	delete[] s1;
	return 0;
}