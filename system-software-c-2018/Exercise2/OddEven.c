/*
 * File:        OddEven.c
 * Author:      Sami Tanskanen
 * Description: Checks if an integer is odd or even and prints the result
 */

#include <stdio.h>

int main() {
	int number = 0;

	printf("Give a number: ");
	scanf("%d", &number);

	if (number == 0) {
		printf("Number %d is neither odd nor even.\n", number);
	} else if ((number & 1) == 1) {
		printf("Number %d is odd.\n", number);
	} else {
		printf("Number %d is even.\n", number);
	}

	return (0);
}
