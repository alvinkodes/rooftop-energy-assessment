#include <stdio.h> //printf
#include <stdbool.h> //booleans
#include <ctype.h> //isdigit
#include <limits.h> //INT_MAX && INT_MIN

/* This is a custom atoi that does two more additional checks than normal atoi
 * 1. check int overflows
 * 2. check if arg provided is all digits
 */
bool safe_atoi(char* arg, long* val)
{
	int sign = 1;
	size_t i = 0;
	
	// Return false if arg is empty.
	if (!*arg)
		return (false);
	if (arg[i] == '+' || arg[i] == '-') {
		if (arg[i] == '-')
			sign *= -1;
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
		if ((sign == 1 && *val > INT_MAX) || (sign == -1 && -*val < INT_MIN))
			return (false);
		i++;
	}
	*val *= sign;
	return (true);
}

bool is_even(int n)
{
	return ((n % 2) == 0);
}

int main(int ac, char* av[])
{
	// Exit program if arguments provided are not exactly two.
	if (ac != 2) {
		printf("Usage: ./program <integer>\n");
		return (0);
	}
	long value = 0;
	if (!safe_atoi(av[1], &value)) {
		printf("Error: invalid argument!\n");
		return (1);
	}
	is_even(value) ? printf("%ld is even!\n", value) : printf("%ld is not even!\n", value);
	return (0);
}
