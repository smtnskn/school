/*
 * File:        Calculator.c
 * Author:      Sami Tanskanen
 * Description: Performs calculations on two integers
 */

#include <stdio.h>

int main() {
	int number1 = 20;
	int number2 = 5;

	printf("Integer 1:\t%d\n", number1);
	printf("Integer 2:\t%d\n", number2);

	int sum = number1 + number2;
	printf("Sum:\t\t%d\n", sum);

	int difference = number1 - number2;
	printf("Difference:\t%d\n", difference);

	int product = number1 * number2;
	printf("Product:\t%d\n", product);

	int division = number1 / number2;
	printf("Division:\t%d\n", division);

	return (0);
}
