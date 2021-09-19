/*
 * File:        Stars.h
 * Author:      Sami Tanskanen
 * Description: Header for Stars.c
 */

#ifndef STARS_H
#define STARS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define STAR_ARRAY_LENGTH 5
#define INPUT_LENGTH 10
#define INPUT_ALLOCATION_ERROR "\n\tError allocating memory for user input!\n"
#define INVALID_INPUT "\tInvalid input. Try again.\n"
#define INVALID_INPUT_LENGTH "\tInvalid input length. Try again.\n"
#define STRUCT_ALLOCATION_ERROR "\n\tError allocating memory for star data!\n"

typedef struct starStruct {
	char *name;
	char *distanceFromEarth;
	char *yearDiscovered;
} starStruct;

starStruct starArray[STAR_ARRAY_LENGTH];
int starIndex;

void initStarArray();
void flushInput();
char *userInput(char *printMessage);
int enterStar(char *name, char *distance, char *year);
int floatFormatCheck(char *input, int length);
int integerFormatCheck(char *input, int length);
int distanceFormatCheck(char *distance);
int yearFormatCheck(char *year);
void printStar(int index);
void printStars();

#endif
