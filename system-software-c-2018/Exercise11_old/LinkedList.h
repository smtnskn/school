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

void freeList(Node **node);
void printList(Node *node, char *separator);
int listLength(Node *node);
int pushTail(Node **node, char valueToAdd);
int pushHead(Node **head, char valueToAdd);
char popHead(Node **head);
char popTail(Node *node);
void reverseList(Node **head);

#endif
