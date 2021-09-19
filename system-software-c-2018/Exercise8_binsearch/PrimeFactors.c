/*
 * File:        PrimeFactors.c
 * Author:      Sami Tanskanen
 * Description: Functions for finding primes and prime factors
 */

#include "PrimeFactors.h"

/* Fills primeArray with all primes between 2 and the given size and
   returns the number of primes found via the size pointer */
void fillPrimeArray(int *primeArray, int *tempArray, int *size) {
	int sizeSqrt = (int)sqrt(*size);
	int *tempArrayIndex;
	int *primeArrayIndex = primeArray;
	int primesFound = 0;

	/* Sieve of Eratosthenes */
	for (int number = 2; number <= *size; number++) {
		tempArrayIndex = tempArray + number - 2;

		if (*tempArrayIndex == -1) {
			continue;
		}

		*tempArrayIndex = number;
		*primeArrayIndex = number;
		primeArrayIndex++;
		primesFound++;

		if (number <= sizeSqrt) {
			for (int nonPrime = number << 1; nonPrime <= *size; nonPrime += number)  {
				tempArrayIndex += number;
				*tempArrayIndex = -1;
			}
		}
	}

	*size = primesFound;
}

/* Places the int value of the highest prime found into factorReturnPointer */
void largestPrimeFactor(int *primeArray,
    int *primeArraySize,
    int *randomNumberPointer,
    int *factorReturnPointer) {

	int number = *randomNumberPointer;
	int isPrime = -1;

	/* Check if number itself is a prime */
	binarySearch(primeArray, primeArraySize, &number, &isPrime);

	if (isPrime != -1) {
		*factorReturnPointer = number;
	} else {
		/* Find the largest prime that is less than (or equal to)
		   the given number halved */
		int primeArrayIndex = -1;
		int searchTarget = number << 1;
		int offset = 0;
		while (primeArrayIndex == -1) {
			binarySearch(primeArray,
			    primeArraySize,
			    &searchTarget,
			    &primeArrayIndex);

			searchTarget -= ++offset;
		}

		/* Find the largest prime that the number can be cleanly divided by */
		float numberDivided = 0.0;
		int numberDividedInt = 0;
		while (1) {
			numberDivided = number / (float)*(primeArray + primeArrayIndex);
			numberDividedInt = (int)numberDivided;

			if (numberDivided - numberDividedInt < FLT_MIN) {
				break;
			}

			primeArrayIndex--;
		}

		*factorReturnPointer = *(primeArray + primeArrayIndex);
	}
}

/* If a match is found, its index is placed in returnPointer
   If a match is not found, -1 gets placed in returnPointer */
void binarySearch(int *array,
    int *arraySize,
    int *numberToFind,
    int *returnPointer) {

	int begin = 0;
	int end = *arraySize - 1;

	while (begin <= end) {
		int index = (begin + end) >> 1;

		if (*(array + index) == *numberToFind) {
			/* Number was found */
			*returnPointer = index;
			return;
		} else if (*numberToFind > *(array + index)) {
			begin = index + 1;
		} else {
			end = index - 1;
		}
	}

	/* The number wasn't found */
	*returnPointer = -1;
}
