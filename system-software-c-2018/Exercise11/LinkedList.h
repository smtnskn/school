/*
 * File:        LinkedList.h
 * Author:      Sami Tanskanen
 * Description: Header for LinkedList.c
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
	char value;
	struct Node *nextNode;
} Node;

int initialiseList(Node **head);
void freeList(Node **head);
void printList(Node *head, char *separator);
int pushNode(Node **head, char valueToAdd);
int reverseList(Node **head);

#endif
