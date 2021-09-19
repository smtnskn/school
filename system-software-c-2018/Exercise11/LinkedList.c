/*
 * File:        LinkedList.c
 * Author:      Sami Tanskanen
 * Description: A linked list implementation for positive, non-zero chars.
 *              All functions that call malloc() return 0 if it fails.
 */

#include "LinkedList.h"

/* Allocates memory for the head (the first node) of the list */
int initialiseList(Node **head) {
	*head = malloc(sizeof(Node));
	if (*head == NULL) {
		return (0);
	}

	(*head) -> value = -1;
	(*head) -> nextNode = NULL;

	return (1);
}

/* Deallocates the memory that is reserved for the list */
void freeList(Node **head) {
	while (*head != NULL) {
		Node *nextNode = (*head) -> nextNode;
		free(*head);
		*head = nextNode;
	}
}

/* Prints the list  */
void printList(Node *head, char *separator) {
	Node *currentNode = head;
	while (currentNode -> nextNode != NULL) {
		printf("%c%s", currentNode -> value, separator);
		currentNode = currentNode -> nextNode;
	}
}

/* Appends a new node to the tail (the last node) */
int pushNode(Node **node, char valueToAdd) {
	/* Nodes that have NULL as nextNode have been initialized (malloc),
	   but don't yet store a value.
	   (in this case, -1 signifies no value)
	   The last node on the list, the tail node, never holds a value.
	   We can find the tail by checking nextNode until we find NULL. */
	Node *currentNode = *node;
	while (currentNode -> nextNode != NULL) {
		currentNode = currentNode -> nextNode;
	}

	/* Once we've found the tail, we'll store the given number in it
	   and initialise the next empty node */
	currentNode -> value = valueToAdd;
	currentNode -> nextNode = malloc(sizeof(Node));
	if (currentNode -> nextNode == NULL) {
		return (0);
	}
	currentNode -> nextNode -> value = -1;
	currentNode -> nextNode -> nextNode = NULL;

	return (1);
}

/* Reverses the list (12345 becomes 54321) */
int reverseList(Node **head) {
	/* If the list has only 1 node, return */
	if ((*head) -> nextNode == NULL) {
		return (1);
	}

	/* Current head becomes the new tail */
	Node *newTail = *head;

	/* Store previous node */
	Node *previousNode = *head;

	/* For every node... */
	Node *currentNode = previousNode -> nextNode;
	while (currentNode -> nextNode != NULL) {

		/* Store the next node */
		Node *nextNode = currentNode -> nextNode;

		/* Make the current node point to the previous node */
		currentNode -> nextNode = previousNode;

		/* Update the variables, and move to the next node */
		previousNode = currentNode;
		currentNode = nextNode;
	}

	/* previousNode now points to the node that used to be the tail,
	   so let's make it the new head */
	*head = previousNode;

	/* Finally, make the tail point to the left-over empty node */
	newTail -> nextNode = currentNode;

	return (1);
}
