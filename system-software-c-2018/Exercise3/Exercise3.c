/*
 * File:        Exercise3.c
 * Author:      Sami Tanskanen
 * Description: Function exercises
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int random(int, int);
char isHexanacci(int, int);
char isPrime(int);

int main() {
	srand(time(NULL));

	int upperBound = 150000;

	for (int i = 0; i < 5; i++) {
		int randomInt = random(0, upperBound);

		if (isHexanacci(randomInt, upperBound)) {
			printf("\nNumber %d is a Hexanacci number\n", randomInt);
		} else {
			printf("\nNumber %d is not a Hexanacci number\n", randomInt);
		}

		if (isPrime(randomInt)) {
			printf("Number %d is a prime\n", randomInt);
		} else {
			printf("Number %d is not a prime\n", randomInt);
		}
	}

	printf("\n");

	return (0);
}

int random(int lowerBound, int upperBound) {
	return ((rand() % (upperBound - lowerBound)) + lowerBound);
}

char isHexanacci(int numberToCheck, int upperBound) {
	/* The sum of indices 0-5 is placed in index 6,
	   which is then compared to numberToCheck */
	int numbers[] = { 0, 0, 0, 0, 0, 1, 0};

	do {
		numbers[6] = 0;
		for (int i = 0; i < 6; i++) {
			numbers[6] += numbers[i];
			numbers[i] = numbers[i + 1];
		}
		if (numbers[6] == numberToCheck) {
			return (1);
		}
	} while (numbers[6] <= upperBound);

	return (0);
}

char isPrime(int numberToCheck) {
	/* Check if the number is even */
	if ((numberToCheck & 1) == 0) {
		return (0);
	}

	for (int divisor = 3; divisor * divisor <= numberToCheck; divisor += 2) {
		if (numberToCheck % divisor == 0) {
			return (0);
		}
	}

	return (1);
}
