/*
 * File:        Exercise9.c
 * Author:      Sami Tanskanen
 * Description: Finds the largest palindrome number that is the product of 2
 *              3-digit numbers
 */

#include <stdio.h>
#include <string.h>

int isPalindrome(char *string);

int main() {
	int multiplier = 999;
	int multiplicand = 999;
	int largestPalindrome = 0;
	int multiplierOfLargest = 0;
	int multiplicandOfLargest = 0;

	while (multiplicand > 99) {
		int product = multiplier * multiplicand;

		if (product % 10 != 0) {
			char productAsString[7];
			sprintf(productAsString, "%d", product);

			if (isPalindrome(productAsString) && product > largestPalindrome) {
				largestPalindrome = product;
				multiplierOfLargest = multiplier;
				multiplicandOfLargest = multiplicand;
			}
		}

		if (--multiplier < 100) {
			multiplier = --multiplicand;
		}
	}

	printf("Largest palindrome number is %d\n", largestPalindrome);
	printf("Numbers are %d and %d\n", multiplierOfLargest, multiplicandOfLargest);

	return (0);
}

int isPalindrome(char *string) {
	int firstIndex = 0;
	int secondIndex = strlen(string) - 1;

	while (firstIndex <= secondIndex) {
		if (string[firstIndex++] != string[secondIndex--]) {
			return (0);
		}
	}

	return (1);
}
