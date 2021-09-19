#include "PrimeFactors.h"
#include <stdio.h>  // DEBUG

void fillPrimeArray(int *primeArray, int size) {
	int sizeSqrt = (int)sqrt(size);
	int *primeArrayIndex;

	for (int number = 2; number <= size; number++) {
		primeArrayIndex = primeArray + number - 2;

		if (*primeArrayIndex == -1) {
			continue;
		}

		*primeArrayIndex = number;

		if (number <= sizeSqrt) {
			for (int nonPrime = number << 1; nonPrime <= size; nonPrime += number)  {
				primeArrayIndex += number;
				*primeArrayIndex = -1;
			}
		}
	}
}

void largestPrimeFactor(
    int *primeArray,
    int *randomNumberPointer,
    int *factorReturnPointer
) {
	int number = *randomNumberPointer;
	int *primeArrayIndex = primeArray + number - 2;

	if (*(primeArrayIndex) == number) {
		*factorReturnPointer = number;
	} else {
		*factorReturnPointer = 0;
		// TODO: find largest prime factor
	}
}
