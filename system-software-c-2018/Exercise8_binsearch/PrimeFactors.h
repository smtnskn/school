#ifndef PRIMEFACTORS_H
#define PRIMEFACTORS_H

#include <math.h>
#include <float.h>

void fillPrimeArray(int *primeArray, int *tempArray, int *size);

void largestPrimeFactor(
    int *primeArray,
    int *primeArraySize,
    int *randomNumberPointer,
    int *factorReturnPointer
);

void binarySearch(
    int *array,
    int *arraySize,
    int *numberToFind,
    int *returnPointer
);

#endif
