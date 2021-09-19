/*
 * File:        EvenNumbers.c
 * Author:      Sami Tanskanen
 * Description: Prints all even numbers from 30 to 0
 */

#include <stdio.h>

int main() {
	for (int number = 30; number > 0; number--) {
		if ((number & 1) == 0) {
			printf("Number %d is even.\n", number);
		}
	}

	return (0);
}
