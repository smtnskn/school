/*
 * File:        CarryFunctions.h
 * Author:      Sami Tanskanen
 * Description: Header for CarryFunctions.c
 */

#ifndef CARRYFUNCTIONS_H
#define CARRYFUNCTIONS_H

#include <string.h>
#include "LinkedList.h"

#define ASCII_CONVERSION 48  // e.g. ('5' - 48) == 5

int addNumber(Node **sumListHead, char valueAsString[]);
char fromAscii(char character);
char toAscii(char number);
int carryTheOne(Node **sumListNode);
int inputIsValid(char array[]);
void printSum(Node **sumListHead, int numbersSummed);

#endif
