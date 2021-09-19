/*
 * File:        Exercise11.c
 * Author:      Sami Tanskanen
 * Description: A program that does addition using chars and linked lists
 */

#include "CarryFunctions.h"

int main(int argc, char *argv[]) {
	Node *sumListHead = NULL;

	/*
	switch (argc) {
	case 2: ; // When numbers are read from a file
		FILE *filePointer = NULL;
		if ((filePointer = fopen(argv[1], "r")) == NULL) {
			printf("Error opening file!\n");

			return (1);
		}

		int numberCount = 0;
		char readBuffer[CARRY_ARRAY_LENGTH] = "";
		while ((fscanf(filePointer, "%s", readBuffer)) != EOF) {
			if (inputIsValid(readBuffer, numberCount + 1)) {
				addNumber(readBuffer);
				numberCount++;
			} else {
				printf("Invalid input!\n");
				fclose(filePointer);

				return (1);
			}
		}
		fclose(filePointer);

		printSum(numberCount);
		break;

		default: // When numbers are passed as arguments
	*/
		for (int index = 1; index < argc; index++) {
			if (inputIsValid(argv[index])) {
				if (!addNumber(&sumListHead, argv[index])) {
					printf("Error allocating memory for linked list node!\n");

					return (1);
				}
			} else {
				printf("Invalid input!\n");

				return (1);
			}

			/* printf("main, sumListHead -> value: %c\n", sumListHead -> value); // DEBUG */
			printf("Length: %d\n", listLength(sumListHead));
		}
		printSum(&sumListHead, argc - 1);
		//		break;
		//}

	return (0);
}
