#include <stdio.h> //printf
#include <stdbool.h> //booleans
#include <limits.h> //INT_MIN && INT_MAX
#include <ctype.h> //isdigit

long long greater_of_two(long long x, long long y) {
	long long diff = x - y;
	long long sign = (diff >> 63) & 1; // 0 if x >= y, 1 if x < y. Right shift by 63 bits to get the sign bit.
	return (x - sign * diff); // if sign = 0, means x >= y, return x. Otherwise, return x + (1 * diff), which would be y.
}

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

int main(int ac, char* av[]) {
	if (ac != 3) {
		printf("Usage: ./program <integer 1> <integer 2>\n");
		return (0);
	}
	long val1 = 0;
	long val2 = 0;
	if (!safe_atoi(av[1], &val1) || !safe_atoi(av[2], &val2)) {
		printf("Error: Invalid arguments.\n");
		return (1);
	}
	printf("The greater of two is: %lld\n", greater_of_two(val1, val2));
	return (0);
}
