#include <stdio.h>
#define SUCCESS 0
#define ERROR 1

int div_mod(int x, int y, int* q, int* r) {
	if (y == 0) 
		return (ERROR);
	int negative = x < 0 != y < 0; // 1 if exactly one is negative
	int abs_x = x < 0 ? -x : x; // absolute value of x
	int abs_y = y < 0 ? -y : y; // absolute value of y
	
	int quotient = 0;
	int remainder = abs_x;

	while (remainder >= abs_y) {
		remainder -= abs_y;
		quotient++;
	}
	if (negative)
		quotient = -quotient; // quotient is negative if exactly one is negative
	if (x < 0 && remainder != 0)
		remainder = -remainder; // remainder is negative if x is negative
	*q = quotient;
	*r = remainder;
	return (SUCCESS);
}

int main() {
	int cases[][2] = {
		{10, 3},
		{20, 4},
		{17, 5},
		{0, 7},
		{7, 1},
		{100, 10},
		{1, 2},
		{-10, 3},
		{10, -3},
		{-10, -3},
		{10, 0},
	};

	int n = sizeof(cases) / sizeof(cases[0]);
	printf("%6s %6s | %8s %8s | %10s %10s\n",
           "x", "y", "div", "mod", "expected /", "expected %");
    printf("--------------------------------------------------------------\n");
 
    for (int i = 0; i < n; i++) {
        int x = cases[i][0];
        int y = cases[i][1];
        int q, r;
        if (div_mod(x, y, &q, &r) == SUCCESS)
        	printf("%6d %6d | %8d %8d | %10d %10d\n", x, y, q, r, x / y, x % y);
		else
			printf("Error: y cannot be 0!\n");
    }

}