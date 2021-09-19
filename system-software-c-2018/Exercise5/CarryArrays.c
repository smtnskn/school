/*
 * File:        CarryArrays.c
 * Author:      Sami Tanskanen
 * Description: Functions for summing arbitrarily large numbers via char arrays
 */

#include "CarryArrays.h"

void emptyArray(char array[], int beginIndex, int endIndex) {
	for (int index = beginIndex; index < endIndex; index++) {
		array[index] = 0;
	}
}

void initArrays() {
	/* See the header for array declarations */
	emptyArray(sumArray, 0, SUM_ARRAY_LENGTH);
	emptyArray(carryArray, 0, CARRY_ARRAY_LENGTH);
}

void addNumber(char numberArray[]) {
	int digits = arrayLength(numberArray);

	/* Copy number to the end of the carry array */
	for (int index = 0; index < digits; index++) {
		carryArray[CARRY_ARRAY_LENGTH - digits + index] = numberArray[index];
	}

	/* Add the number to the sum, digit by digit, starting from the last index */
	for (int carryIndex = CARRY_ARRAY_LENGTH - 1, sumIndex = SUM_ARRAY_LENGTH - 1;
	     carryArray[carryIndex] > 0;
	     carryIndex--, sumIndex--) {

		/* Don't take sumArray[sumIndex] into account if it is 0
		   (== '\0' == NUL), otherwise the result will be off due
		   to the subtraction */
		char digitSum = carryArray[carryIndex] - ASCII_CONVERSION;
		if (sumArray[sumIndex] != 0) {
			digitSum += sumArray[sumIndex] - ASCII_CONVERSION;
		}
		sumArray[sumIndex] = (digitSum % 10) + ASCII_CONVERSION;

		/* If the sum of the digits is >= 10, carry the 1 up the array */
		if (digitSum >= 10) {
			digits += carryTheOne(carryIndex, digitSum);
		}
	}

	emptyArray(carryArray, CARRY_ARRAY_LENGTH - digits, CARRY_ARRAY_LENGTH);
}

/*
  Carries the one up the array, returns 1 if the carry added a new digit
  Example:

  1
  +  999
  ------
  1000   <- now 4 digits instead of 3
*/
int carryTheOne(int offsetCarryIndex, int digitSum) {
	int digitAdded = 0;
	offsetCarryIndex -= 1;

	do {
		if (carryArray[offsetCarryIndex] == 0) {
			digitSum = 1;
			digitAdded = 1;
		} else {
			digitSum = 1 + carryArray[offsetCarryIndex] - ASCII_CONVERSION;
		}
		carryArray[offsetCarryIndex] = (digitSum % 10) + ASCII_CONVERSION;
		offsetCarryIndex--;
	} while (digitSum >= 10);

	return (digitAdded);
}

/* Shift digits to the beginning of the array */
void shiftLeft(char array[], int arrayLength) {
	int copyIndex = 0;
	while (array[copyIndex] == 0) {
		copyIndex++;
	}

	for (int index = 0; copyIndex < arrayLength; index++, copyIndex++) {
		array[index] = array[copyIndex];
		array[copyIndex] = 0;
	}
}

int arrayLength(char array[]) {
	int length = 0;
	while (array[length] != 0) {
		length++;
	}

	return (length);
}

int inputIsValid(char array[], int arrayLength) {
	for (int index = 0; index < arrayLength; index++) {
		if (array[index] < 48 || array[index] > 57) {
			return (0);
		}
	}

	return (1);
}

void printSum(int numbersSummed) {
	if (numbersSummed == 0) {
		printf("Nothing to sum!\n");
	} else {
		shiftLeft(sumArray, SUM_ARRAY_LENGTH);
		printf("%d numbers summed!\n", numbersSummed);
		printf("Sum: %s\n", sumArray);
	}
}
