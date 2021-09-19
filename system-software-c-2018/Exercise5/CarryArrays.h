/*
 * File:        CarryArrays.h
 * Author:      Sami Tanskanen
 * Description: Header for CarryArrays.c
 */

#ifndef ARRAYS_H
#define ARRAYS_H

#include <stdio.h>

#define CARRY_ARRAY_LENGTH 100
#define SUM_ARRAY_LENGTH 200
#define ASCII_CONVERSION 48  // e.g. ('5' - 48) == 5

char carryArray[CARRY_ARRAY_LENGTH];
char sumArray[SUM_ARRAY_LENGTH];

void emptyArray(char array[], int beginIndex, int endIndex);
void initArrays();
void addNumber(char numberArray[]);
int carryTheOne(int offsetCarryIndex, int digitSum);
void shiftLeft(char array[], int arrayLength);
int arrayLength(char array[]);
int inputIsValid(char array[], int arrayLength);
void printSum(int numbersSummed);

#endif
