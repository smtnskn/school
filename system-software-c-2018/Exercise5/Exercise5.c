/*
 * File:        Exercise5.c
 * Author:      Sami Tanskanen
 * Description: A program that does addition via char arrays
 */

#include "CarryArrays.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
	initArrays();

	switch (argc) {
	case 2: ; // When numbers are read from a file
		FILE *filePointer = NULL;
		char readBuffer[CARRY_ARRAY_LENGTH] = "";

		if ((filePointer = fopen(argv[1], "r")) == NULL) {
			printf("Error opening file!\n");
			goto exit;
		}

		int numberCount = 0;
		while ((fscanf(filePointer, "%s", readBuffer)) != EOF) {
			if (inputIsValid(readBuffer, arrayLength(readBuffer))) {
				addNumber(readBuffer);
				numberCount++;
			} else {
				printf("Invalid input!\n");
				fclose(filePointer);
				goto exit;
			}
		}
		fclose(filePointer);

		printSum(numberCount);
		break;

	default: // When numbers are passed as arguments
		for (int index = 1; index < argc; index++) {
			if (inputIsValid(argv[index], arrayLength(argv[index]))) {
				addNumber(argv[index]);
			} else {
				printf("Invalid input!\n");
				goto exit;
			}
		}
		printSum(argc - 1);
		break;
	}

	return (0);
 exit: return (1);
}
