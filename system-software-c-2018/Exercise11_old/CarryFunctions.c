/*
 * File:        CarryFunctions.c
 * Author:      Sami Tanskanen
 * Description: Functions for summing arbitrarily large numbers via chars
 *              and linked lists
 */

#include "CarryFunctions.h"

int addNumber(Node **sumListHead, char valueAsString[]) {
	Node *currentSumNode = *sumListHead;

	int digits = strlen(valueAsString) - 1;
	for (int index = digits; index >= 0; index--) {
		if (currentSumNode == NULL) {
			if (!pushTail(sumListHead, valueAsString[index])) {
				return (0);
			}
			if (currentSumNode == NULL) {
				currentSumNode = *sumListHead;
			}
			printf("index, NULL: %d\n", index); // DEBUG
		} else {
			/* printf("%c, ", currentSumNode -> value); // DEBUG */
			char nodeValue = fromAscii(currentSumNode -> value);
			char newNodeValue = fromAscii(valueAsString[index]) + nodeValue;

			if (newNodeValue < 10) {
				currentSumNode -> value = toAscii(newNodeValue);
			} else {
				currentSumNode -> value = toAscii(newNodeValue - 10);

				if (!carryTheOne(&(currentSumNode -> nextNode))) {
					return (0);
				}
			}
			printf("index, !NULL: %d\n", index); // DEBUG
		}

		currentSumNode = currentSumNode -> nextNode;
	}

	return (1);
}

char fromAscii(char character) {
	return (character - ASCII_CONVERSION);
}

char toAscii(char number) {
	return (number + ASCII_CONVERSION);
}

/*
  Carries the one up the list
  Example:

  1
  +  999
  ------
  1000   <- now 4 digits instead of 3
*/
int carryTheOne(Node **sumListNode) {
	Node *currentNode = *sumListNode;

	while (1) {
		/* We've reached the tail of the list!
		   Push the one to the tail and return */
		if (currentNode == NULL) {
			if (!pushTail(&currentNode, toAscii(1))) {
				return (0);
			}
			return (1);
		}

		char newNodeValue = fromAscii(currentNode -> value) + 1;

		/* Nothing more to carry
		   Change the value in this node and return */
		if (newNodeValue < 10) {
			currentNode -> value = toAscii(newNodeValue);

			return (1);
		}

		/* Carry continues */
		currentNode -> value = toAscii(newNodeValue - 10);
		currentNode = currentNode -> nextNode;
	}
}

int inputIsValid(char array[]) {
	int arrayLength = strlen(array);
	for (int index = 0; index < arrayLength; index++) {
		if (array[index] < 48 || array[index] > 57) {
			return (0);
		}
	}

	return (1);
}

void printSum(Node **sumListHead, int numbersSummed) {
	if (numbersSummed == 0) {
		printf("Nothing to sum!\n");
	} else {
		printf("%d numbers summed!\n", numbersSummed);
		printf("Sum: ");
		printList(*sumListHead, "");
		putc('\n', stdout);
	}
}
