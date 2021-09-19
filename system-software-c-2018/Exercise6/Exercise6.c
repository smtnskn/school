/*
 * File:        Exercise6.c
 * Author:      Sami Tanskanen
 * Description: Creates binary representations of the arguments given
 *              and prints them into a file
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BYTE 8

int main(int argc, char *argv[]) {
	if (argc == 1) {
		printf("No arguments given!\n");
		return (0);
	}

	int bitArraySize = BYTE;
	char *bitArray = NULL;
	if ((bitArray = (char*)malloc(bitArraySize * sizeof(char))) == NULL) {
		printf("Error allocating memory!");
		return (1);
	}

	/* Count the bits and place them into an array */
	int bitCount = 0;
	for (int argument = 1; argument < argc; argument++) {
		for (int index = 0; argv[argument][index] != '\0'; index++) {
			char currentChar = argv[argument][index];

			if (currentChar == '1' || currentChar == '0') {
				bitArray[bitCount++] = currentChar;

				/* Grow the array if full and initialize the newly
				   created area to 0 with memset */
				if (bitCount == bitArraySize) {
					int oldSize = bitArraySize;
					bitArraySize += BYTE;
					bitArray = realloc(bitArray, bitArraySize);
					void *bitArrayUninitialized = bitArray + oldSize;
					memset(bitArrayUninitialized, 0, BYTE);
				}
			}
		}
	}
	if (bitCount < 8) {
		printf("Not enough bits given!\n");
		return (0);
	}

	/* Round bitCount down to nearest number that is divisible by 8 */
	bitCount &= ~7;

	FILE *filePointer = NULL;
	if ((filePointer = fopen("Binary.txt", "w")) == NULL) {
		printf("Error creating file!");
		return (1);
	}
	fprintf(filePointer,
	    "Exercise 6 - Learning command line arguments and file write\n");

	/* Print the binary representations and the values they represent into a file */
	char binaryRepresentation[BYTE] = { 0 };
	int bitArrayIndex = 0;

	while (bitArrayIndex < bitCount) {
		char representedValue = 0;
		int binaryIndex = 0;

		while (binaryIndex < BYTE) {
			if (bitArray[bitArrayIndex] == '1') {
				representedValue |= 1 << (7 - binaryIndex);
			}
			binaryRepresentation[binaryIndex] = bitArray[bitArrayIndex];
			bitArrayIndex++;
			binaryIndex++;
		}

		fprintf(filePointer, "\nOriginal binary: ");
		for (binaryIndex = 0; binaryIndex < 8; binaryIndex++) {
			fprintf(filePointer, "%c", binaryRepresentation[binaryIndex]);
		}

		fprintf(filePointer, "\nDecimal: %d\n", representedValue);

		if (representedValue < 0) {
			fprintf(filePointer, "Divided decimal: %d\n", representedValue >> 1);
		} else {
			fprintf(filePointer, "Multiplied decimal: %u\n", representedValue << 1);
		}
	}

	fclose(filePointer);

	return (0);
}
