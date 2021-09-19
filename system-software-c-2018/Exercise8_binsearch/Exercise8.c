/*
 * File:        Exercise8.c
 * Author:      Sami Tanskanen
 * Description: Finds and prints the highest prime factors for random numbers
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "PrimeFactors.h"

#define MAX_RANDOM 1000000

int main(int argc, char *argv[]) {
	putc('\n', stdout);

	if (MAX_RANDOM < 2) {
		printf("No primes in range 0 ... %d. Exiting...\n", MAX_RANDOM);
		return (0);
	}

	/* Verify input, exit early if invalid */
	int randomArraySize = 0;

	if (argc == 1) {
		printf("Error: No arguments given\n");
	} else if (argc > 2) {
		printf("Error: Only 1 argument is allowed\n");
	} else if (!(randomArraySize = atoi(argv[1])) || randomArraySize < 1) {
		printf("Error: Only whole, positive numbers are allowed\n");
	}

	if (randomArraySize < 1) {
		return (1);
	}

	/* Find primes up to primeArraySize */
	printf("Looking for primes...\n");

	int *primeArray;
	int *tempArray;
	int primeArraySize = MAX_RANDOM;

	if ((primeArray = malloc(primeArraySize * sizeof(int))) == NULL) {
		printf("Error allocating memory for primes. Exiting...\n");

		return (1);
	}
	if ((tempArray = calloc(primeArraySize, sizeof(int))) == NULL) {
		printf("Error allocating memory for primes. Exiting...\n");

		return (1);
	}

	fillPrimeArray(primeArray, tempArray, &primeArraySize);

	/* Resize primeArray to only hold the found primes
	   (the value of primeArraySize has been changed by fillPrimeArray()) */
	if ((primeArray = realloc(primeArray, primeArraySize * sizeof(int))) == NULL) {
		printf("Error reallocating memory for primes. Exiting...\n");

		return (1);
	}

	free(tempArray);

	/* Fill an array with random integers */
	int *randomArray;
	if ((randomArray = calloc(randomArraySize, sizeof(int))) == NULL) {
		printf("Error allocating memory for random numbers. Exiting...\n");

		return (1);
	}

	srand(time(NULL));
	for (int index = 0; index < randomArraySize; index++) {
		*(randomArray + index) = rand() % primeArraySize;
	}

	/* Find and print the largest prime factors */
	int largestFactor = 0;

	putc('\n', stdout);
	for (int index = 0; index < randomArraySize; index++) {
		largestPrimeFactor(primeArray,
		    &primeArraySize,
		    randomArray + index,
		    &largestFactor);
		printf("Largest prime factor of %d is %d\n",
		    *(randomArray + index),
		    largestFactor);
	}
	putc('\n', stdout);

	free(randomArray);
	free(primeArray);

	return (0);
}
