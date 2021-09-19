/*
 * File:        PrimeFactors.h
 * Author:      Sami Tanskanen
 * Description: Header for PrimeFactors.c
 */

#ifndef PRIMEFACTORS_H
#define PRIMEFACTORS_H

#include <math.h>
#include <float.h>

void fillPrimeArray(int *primeArray, int *size);
void largestPrimeFactor(
    int *primeArray,
    int *randomNumberPointer,
    int *factorReturnPointer
);

#endif
