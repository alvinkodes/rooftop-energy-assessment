#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <ctype.h>

int count_digit(int n) {
	int count = 0;

	if (n > 0)
		count = count_digit(n / 10);
	if (n % 10 == 3)
		count += 1;
	return (count);
}

bool safe_positive_atoi(char* arg, long* val)
{
	size_t i = 0;
	
	// Return false if arg is empty.
	if (!*arg)
			return (false);
	// Return false if negative number.
	if (arg[i] == '+' || arg[i] == '-') {
			if (arg[i] == '-')
		return (false);
			i++;
	}
	// Return false if there is no digits after.
	if (!isdigit(arg[i]))
			return (false);
	while (arg[i]) {
			if (!isdigit(arg[i]))
					return (false);
			*val = (*val * 10) + arg[i] - '0';
			// Return false if integer overflows.
			if (*val > INT_MAX)
					return (false);
			i++;
	}
	return (true);
}

int main(int ac, char* av[]) {
	if (ac != 2) {
		printf("Usage: ./program <positive_integer>\n");
		return (1);
	}
	long val = 0;
	if (!safe_positive_atoi(av[1], &val)) {
		printf("Error: Invalid argument\n");
		return (1);
	}
	printf("Digit 3 appears %d times.\n", count_digit(val));
	return (0);
}
