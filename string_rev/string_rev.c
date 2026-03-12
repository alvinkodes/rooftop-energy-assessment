#include <stdio.h> //printf
#include <string.h> //strlen
#include <stdlib.h> //calloc && free

char* string_rev(char *ori_str) {
	if (!*ori_str)
		return (NULL);
	size_t len = strlen(ori_str);
	char* rev_str = (char*)calloc(len + 1, sizeof(char));
	if (!rev_str)
		return (NULL);
	size_t end = len - 1;
	for (size_t i = 0; i < len; i++) {
		rev_str[i] = ori_str[end--];
	}
	return (rev_str);
}

int main(int ac, char *av[]) {
	if (ac != 2) {
		printf("Usage: ./program <string>\n");
		return (0);
	}
	char* rev_str = string_rev(av[1]);
	if (!rev_str)
		return (1);
	printf("Original string: %s\n", av[1]);
	printf("Reversed string: %s\n", rev_str);
	free(rev_str);
	return (0);
}
