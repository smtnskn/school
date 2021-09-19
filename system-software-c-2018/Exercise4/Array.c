/*
 * File:        Array.c
 * Author:      Sami Tanskanen
 * Description: Stores and prints collatz sequence lengths
 */

#include <stdio.h>
#include "Array.h"

int collatzArray[9998];

void arrayAdd(int index, int number) {
	collatzArray[index] = number;
}

void printLongest() {
	int longestIndex = 0;
	int longestLength = collatzArray[0];

	for (int index = 1; index <= 9998; index++) {
		if (collatzArray[index] > longestLength) {
			longestLength = collatzArray[index];
			longestIndex = index;
		}
	}

	printf("\nNumber: %d Length: %d\n\n", longestIndex + 2, longestLength);
}
