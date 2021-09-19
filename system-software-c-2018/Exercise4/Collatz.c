/*
 * File:        Collatz.c
 * Author:      Sami Tanskanen
 * Description: Counts the length of a Collatz sequence and stores it
 */

#include "Collatz.h"

void countCollatz() {
	for (int number = 2; number <= 10000 ; number++) {
		int numberCopy = number + 2;
		int length = 1;
		while (1) {
			if ((numberCopy & 1) == 1) {
				numberCopy = numberCopy * 3 + 1;
			} else {
				numberCopy /= 2;
			}

			if (numberCopy <= 1) {
				break;
			}

			length++;
		}

		arrayAdd(number - 2, length);
	}
}
