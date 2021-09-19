/*
 * File:        Exercise11.c
 * Author:      Sami Tanskanen
 * Description: A program that does addition using chars and linked lists
 */

#include "CarryFunctions.h"

int main(int argc, char *argv[]) {
	int numberCount = 0;

	/* Allocate memory for the first node (the head) */
	Node *sumListHead = NULL;
	if (!initialiseList(&sumListHead)) {
		printf("Error initializing linked list!\n");

		return (1);
	}

	switch (argc) {
	case 2: ; // When numbers are read from a file
		FILE *filePointer = NULL;
		if ((filePointer = fopen(argv[1], "r")) == NULL) {
			printf("Error opening file!\n");

			freeList(&sumListHead);
			return (1);
		}

		char readBuffer[200] = "";
		while ((fscanf(filePointer, "%s", readBuffer)) != EOF) {
			if (inputIsValid(readBuffer)) {
				if (!addNumber(&sumListHead, readBuffer)) {
					printf("Error expanding linked list!\n");

					freeList(&sumListHead);
					return (1);
				}
				numberCount++;
			} else {
				printf("Invalid input!\n");
				fclose(filePointer);

				freeList(&sumListHead);
				return (1);
			}
		}
		fclose(filePointer);
		break;

	default: // When numbers are passed as arguments
		numberCount = argc - 1;
		for (int index = 1; index < argc; index++) {
			if (inputIsValid(argv[index])) {
				if (!addNumber(&sumListHead, argv[index])) {
					printf("Error expanding linked list!\n");

					freeList(&sumListHead);
					return (1);
				}
			} else {
				printf("Invalid input!\n");

				freeList(&sumListHead);
				return (1);
			}
		}
		break;
	}

	if (!reverseList(&sumListHead)) {
		printf("Error expanding linked list!\n");

		freeList(&sumListHead);
		return (1);
	}
	removeLeadingZeros(&sumListHead);
	printSum(&sumListHead, numberCount);
	freeList(&sumListHead);

	return (0);
}
