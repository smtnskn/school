/*
 * File:        LinkedList.c
 * Author:      Sami Tanskanen
 * Description: A linked list implementation for positive, non-zero chars.
 *              All functions that call malloc() return 0 if it fails.
 */

#include "LinkedList.h"

/* Frees the list from the given Node to the tail */
void freeList(Node **node) {
	while (*node != NULL) {
		Node *nextNode = (*node) -> nextNode;
		free(*node);
		*node = nextNode;
	}
}

/* Prints the list from the given Node to the tail */
void printList(Node *node, char *separator) {
	Node *currentNode = node;
	while (currentNode != NULL) {
		printf("%c%s", currentNode -> value, separator);
		currentNode = currentNode -> nextNode;
	}
}

/* Counts the Nodes in the list from the given Node to the tail */
int listLength(Node *node) {
	int nodeCount = 0;
	Node *currentNode = node;
	while (currentNode != NULL) {
		nodeCount++;
		currentNode = currentNode -> nextNode;
	}

	return (nodeCount);
}

/* Appends a new Node to the tail */
int pushTail(Node **head, char valueToAdd) {
	if (valueToAdd < 1) {
		return (0);
	}

	Node *currentNode = *head;
	Node *previousNode = NULL;
	while (currentNode != NULL) {
		previousNode = currentNode;
		currentNode = currentNode -> nextNode;
	}

	currentNode = malloc(sizeof(Node));
	if (currentNode == NULL) {
		return (0);
	}

	currentNode -> value = valueToAdd;
	currentNode -> nextNode = NULL;

	/* If this wasn't the lone node in the list */
	if (previousNode != NULL) {
		previousNode -> nextNode = currentNode;
	} else {
		*head = currentNode;
	}

	return (1);
}

/* Prepends a new Node to the head */
int pushHead(Node **head, char valueToAdd) {
	if (valueToAdd < 1) {
		return (0);
	}

	Node *newHead = malloc(sizeof(Node));
	if (newHead == NULL) {
		return (0);
	}

	newHead -> value = valueToAdd;
	newHead -> nextNode = *head;
	*head = newHead;

	return (1);
}

/* Removes the head and returns the value it holds */
char popHead(Node **head) {
	if (*head == NULL) {
		return (0);
	}

	Node *newHead = NULL;
	newHead = (*head) -> nextNode;

	char returnValue = (*head) -> value;
	free(*head);
	*head = newHead;

	return (returnValue);
}

/* Removes the tail and returns the value it holds */
char popTail(Node *node) {
	if (node == NULL) {
		return (0);
	}

	/* If this it the tail, remove it and return the value it holds */
	if (node -> nextNode == NULL) {
		char returnValue = node -> value;
		free(node);

		return (returnValue);
	}

	/* Otherwise, find the second to last Node */
	Node *currentNode = node;
	while (currentNode -> nextNode -> nextNode != NULL) {
		currentNode = currentNode -> nextNode;
	}

	/* Once its found, remove it and return the value it holds */
	char returnValue = currentNode -> nextNode -> value;
	free(currentNode -> nextNode);
	currentNode -> nextNode = NULL;

	return (returnValue);
}

/* Reverses a list (12345 becomes 54321) */
void reverseList(Node **head) {
	if (head == NULL) {
		return;
	}

	Node *currentNode = (*head) -> nextNode;
	Node *newHead = *head;
	newHead -> nextNode = NULL;

	while (currentNode != NULL) {
		Node *nextNode = currentNode -> nextNode;
		currentNode -> nextNode = newHead;
		newHead = currentNode;
		currentNode = nextNode;
	}

	*head = newHead;
}
