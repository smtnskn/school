/*
 * File:        PrimeFactors.c
 * Author:      Sami Tanskanen
 * Description: Functions for finding primes and prime factors
 */

#include "PrimeFactors.h"

void fillPrimeArray(int *primeArray, int *size) {
	int sizeSqrt = (int)sqrt(*size);
	int *primeArrayIndex;

	/* Sieve of Eratosthenes */
	for (int number = 2; number <= *size; number++) {
		primeArrayIndex = primeArray + number - 2;

		if (*primeArrayIndex == -1) {
			continue;
		}

		*primeArrayIndex = number;

		if (number <= sizeSqrt) {
			for (int nonPrime = number << 1; nonPrime <= *size; nonPrime += number)  {
				primeArrayIndex += number;
				*primeArrayIndex = -1;
			}
		}
	}
}

void largestPrimeFactor(int *primeArray,
    int *randomNumberPointer,
    int *factorReturnPointer) {

	int number = *randomNumberPointer;
	int *primeArrayIndex = primeArray + number - 2;

	if (*(primeArrayIndex) == number) {
		*factorReturnPointer = number;
	} else {
		float numberDivided = 0.0;
		int numberDividedInt = 0;
		primeArrayIndex = primeArray + (number >> 1) - 2;

		while (1) {
			if (*primeArrayIndex != -1) {
				numberDivided = number / (float)*primeArrayIndex;
				numberDividedInt = (int)numberDivided;

				if (numberDivided - numberDividedInt < FLT_MIN) {
					break;
				}
			}
			primeArrayIndex--;
		}

		*factorReturnPointer = *primeArrayIndex;
	}
}
