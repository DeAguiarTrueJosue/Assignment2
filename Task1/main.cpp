#include <stdio.h>

void SwapNumbers(int* num1, int* num2, int* num3) {
	*num3 = *num1;
	*num1 = *num2;
	*num2 = *num3;
	*num3 = *num1 + *num2;
}

int main() {
	int num1 = 1;
	int num2 = 3;
	int num3 = 5;

	printf("First: %i\n", num1);
	printf("Second: %i\n", num2);
	printf("Third: %i\n", num3);

	SwapNumbers(&num1, &num2, &num3);

	printf("First: %i\n", num1);
	printf("Second: %i\n", num2);
	printf("Third: %i\n", num3);

	return 0;
}