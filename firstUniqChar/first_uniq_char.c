#include <stdio.h> //printf

char first_uniq_char(char *s)
{
	char counts[128] = {0}; // one slot per ASCII character

	for (size_t i = 0; s[i] != '\0'; i++) {
		counts[s[i]] += 1;
	}
	for (size_t j = 0; s[j] != '\0'; j++) {
		if (counts[s[j]] == 1) {
			return (s[j]);
		}
	}
	return ('\0');
}

int main(void)
{
	struct test_case {
		char *input;
		char expected;
	} cases[] = {
		{"parallel", 'p'},
		{"aabb", '\0'},
		{"aabbc", 'c'},
		{"z", 'z'},
		{"", '\0'},
		{"ajoifooafvb", 'j'},
		{"ggggggggg", '\0'},
	};

	size_t size = sizeof(cases) / sizeof(cases[0]);

	printf("%-14s | %-8s | %-8s\n", "String", "Result", "Expected");
	printf("%-14s | %-8s | %-8s\n", "--------------", "--------", "--------");

	for (size_t i = 0; i < size; i++) {
		char result = first_uniq_char(cases[i].input);

		printf("%-14s | ", cases[i].input);
		if (result == '\0') {
			printf("%-8s", "\\0");
		} else {
			printf("%-8c", result);
		}
		printf(" | ");
		if (cases[i].expected == '\0') {
			printf("%-8s\n", "\\0");
		} else {
			printf("%-8c\n", cases[i].expected);
		}
	}

	return (0);
}