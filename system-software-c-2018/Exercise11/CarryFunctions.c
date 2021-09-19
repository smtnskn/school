/*
 * File:        CarryFunctions.c
 * Author:      Sami Tanskanen
 * Description: Functions for summing arbitrarily large numbers via chars
 *              and linked lists
 */

#include "CarryFunctions.h"

int addNumber(Node **sumListHead, char valueAsString[]) {
	/* Begin from the head */
	Node *currentSumNode = *sumListHead;

	/* Store the user input backwards (12345 becomes 54321).
	   This makes carrying the one easier. */
	int digits = strlen(valueAsString) - 1;
	for (int index = digits; index >= 0; index--) {

		/* If the current node does not contain a value yet,
		   call pushNode to store the current digit in it and initialise
		   the next empty node */
		if (currentSumNode -> nextNode == NULL) {
			if (!pushNode(&currentSumNode, valueAsString[index])) {
				return (0);
			}

		/* If the current node already stores a value, add the current
		   digit to it, and carry the one if necessary */
		} else {
			char nodeValue = fromAscii(currentSumNode -> value);
			char newNodeValue = fromAscii(valueAsString[index]) + nodeValue;

			/* If the addition DOES NOT require a carry */
			if (newNodeValue < 10) {
				currentSumNode -> value = toAscii(newNodeValue);

			/* If the addition DOES require a carry */
			} else {
				currentSumNode -> value = toAscii(newNodeValue - 10);

				/* Return 0 if malloc in carryTheOne failed */
				if (!carryTheOne(&(currentSumNode -> nextNode))) {
					return (0);
				}
			}
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
		if (currentNode -> nextNode == NULL) {
			if (!pushNode(&currentNode, toAscii(1))) {
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

/* Validate user input (only numbers are allowed) */
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

/* Remove leading zeros */
void removeLeadingZeros(Node **sumListHead) {
	while ((*sumListHead) -> value == 48 &&
	    (*sumListHead) -> nextNode -> nextNode != NULL) {

		Node *newHead = (*sumListHead) -> nextNode;
		free(*sumListHead);
		*sumListHead = newHead;
	}
}
