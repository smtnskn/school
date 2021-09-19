#ifndef PRIMEFACTORS_H
#define PRIMEFACTORS_H

#include <math.h>

void fillPrimeArray(int *primeArray, int size);
void largestPrimeFactor(
    int *primeArray,
    int *randomNumberPointer,
    int *factorReturnPointer
);

#endif
