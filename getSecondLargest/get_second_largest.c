#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#define SUCCESS 0
#define FAILED 1

int get_second_largest(int arr[], size_t size, int* res) {
	if (size < 2) return (FAILED);

	int largest = INT_MIN;
	int second_largest = INT_MIN;
	bool found = false;
	
	for (size_t i = 0; i < size; i ++) {
		if (arr[i] > largest) {
			if (largest != INT_MIN) {
				second_largest = largest;
				found = true;
			}
			largest = arr[i];
		} else if (arr[i] > second_largest && arr[i] != largest) {
			second_largest = arr[i];
			found = true;
		}
	}
	if (!found) return (FAILED);
	*res = second_largest; return (SUCCESS);
}

int main(void) {
	printf("Test 1: Normal case - with dups\n");
	int arr[] = {3, 1, 4, 1, 5, 9, 7};
	size_t size = sizeof(arr) / sizeof(arr[0]);
	int res;

	if (get_second_largest(arr, size, &res) == SUCCESS)
		printf("The second largest number is: %d\n", res);
	else
		printf("Error: no valid second largest number!\n");
	
	printf("\nTest 2: Normal case - without dups\n");
	int arr1[] = {2, 9, -2147483647, 99, -23, 42, -42};
	size_t size1 = sizeof(arr1) / sizeof(arr1[0]);

	if (get_second_largest(arr1, size1, &res) == SUCCESS)
		printf("The second largest number is: %d\n", res);
	else
		printf("Error: no valid second largest number!\n");

	printf("\nTest 3: One element\n");
	int one_elem[] = {42};
	size_t size2 = sizeof(one_elem) / sizeof(one_elem[0]);

	if (get_second_largest(one_elem, size2, &res) == SUCCESS)
		printf("The second largest number is: %d\n", res);
	else
		printf("Error: no valid second largest number!\n");

	printf("\nTest 4: All same\n");
	int all_same[] = {42, 42, 42};
	size_t size3 = sizeof(all_same) / sizeof(all_same[0]);

	if (get_second_largest(all_same, size3, &res) == SUCCESS)
		printf("The second largest number is: %d\n", res);
	else
		printf("Error: no valid second largest number!\n");

	printf("\nTest 5: Two unique integers\n");
	int two_uniq[] = {2147483647, -2146483648};
	size_t size4 = sizeof(two_uniq) / sizeof(two_uniq[0]);

	if (get_second_largest(two_uniq, size4, &res) == SUCCESS)
		printf("The second largest number is: %d\n", res);
	else
		printf("Error: no valid second largest number!\n");
	return (0);
}