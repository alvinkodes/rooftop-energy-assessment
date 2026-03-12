#include <stdio.h> //printf

void fizzbuzz(int n) {
	if (n % 3 == 0 && n % 5 == 0)
		printf("FizzBuzz\n");
	else if (n % 3 == 0)
		printf("Fizz\n");
	else if (n % 5 == 0)
		printf("Buzz\n");
	else
		printf("%d\n", n);
}

int main(void)
{
	for (int i = 1; i <= 100; i++) {
		fizzbuzz(i);
	}
	return (0);
}
