/*
 * File:        Exercise8.c
 * Author:      Sami Tanskanen
 * Description: Finds and prints the highest prime factors for for random numbers
 */

#include <stdio.h>
#include <time.h>
#include <sys/stat.h>
#include <stdlib.h>

#include "PrimeFactors.h"

#define MAX_RANDOM 1000000
#define FILE_NAME "primes.bin"

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

	/* Allocate memory for an array to hold the primes and zero it out */
	int *primeArray;
	if ((primeArray = calloc(MAX_RANDOM, sizeof(int))) == NULL) {
		printf("Error allocating memory for primes. Exiting...\n");

		return (1);
	}

	/* Determine if FILE_NAME exists using stat() and proceed accordingly */
	FILE *filePointer;
	struct stat fileInfo;
	int writeToFile = stat(FILE_NAME, &fileInfo); // Returns 0 if file exists
	int primeArraySize = MAX_RANDOM;

	if (!writeToFile) {
		/* If fopen() fails, find primes again and overwrite the file */
		printf("Opening %s...\n", FILE_NAME);

		if ((filePointer = fopen(FILE_NAME, "rb")) == NULL) {
			printf("Error opening file. Continuing...\n");
			writeToFile = 1;
		} else {
			/* If MAX_RANDOM is larger than the one in the file,
			   find primes again and overwrite the file */
			fread(&primeArraySize, sizeof(int), 1, filePointer);
			if (primeArraySize < MAX_RANDOM) {
				printf("Existing file is incompatible. Continuing...\n");
				primeArraySize = MAX_RANDOM;
				writeToFile = 1;
			} else {
				/* Read primes from the file */
				printf("Reading primes from file...\n");

				for (int index = 0; index < MAX_RANDOM; index++) {
					fread(primeArray + index, sizeof(int), 1, filePointer);
				}
			}

			fclose(filePointer);
		}
	}

	if (writeToFile) {
		/* Find primes up to primeArraySize */
		printf("Looking for primes...\n");
		fillPrimeArray(primeArray, &primeArraySize);

		/* Write primeArraySize and found primes to file */
		printf("Creating %s...\n", FILE_NAME);

		if ((filePointer = fopen(FILE_NAME, "wb")) == NULL) {
			printf("Error creating file. Continuing without saving primes...\n");
		} else {
			printf("Writing primes to file...\n");

			fwrite(&primeArraySize, sizeof(int), 1, filePointer);
			for (int index = 0; index < primeArraySize; index++) {
				fwrite(primeArray + index, sizeof(int), 1, filePointer);
			}

			fclose(filePointer);
		}
	}

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

	/* Find and print largest prime factors */
	int *factorReturnPointer;
	if ((factorReturnPointer = malloc(sizeof(int))) == NULL) {
		printf("Error allocating memory for factor return pointer. Exiting...\n");

		return (1);
	}

	putc('\n', stdout);
	for (int index = 0; index < randomArraySize; index++) {
		largestPrimeFactor(primeArray, randomArray + index, factorReturnPointer);
		printf("Largest prime factor of %d is %d\n",
		    *(randomArray + index),
		    *factorReturnPointer);
	}
	putc('\n', stdout);

	free(randomArray);
	free(primeArray);
	free(factorReturnPointer);

	return (0);
}
