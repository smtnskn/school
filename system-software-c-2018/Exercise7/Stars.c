/*
 * File:        Stars.c
 * Author:      Sami Tanskanen
 * Description: Functions for adding and reading star data to/from starArray
 */

#include "Stars.h"

int starIndex = 0;

void initStarArray() {
	for (int index = 0; index < STAR_ARRAY_LENGTH; index++) {
		starArray[index].name = NULL;
		starArray[index].distanceFromEarth = NULL;
		starArray[index].yearDiscovered = NULL;
	}
}

void flushInput() {
	char inputCharacter = 0;
	while ((inputCharacter = getc(stdin)) != '\n') {
		;
	};
}

/* Gets user input of unknown length */
char *userInput(char *printMessage) {
	printf("%s", printMessage);

	size_t currentLength = 0;
	size_t stringLength = INPUT_LENGTH;
	char *inputString;
	char inputChar;

	/* Early exit if allocation fails */
	if ((inputString = (char*) malloc(stringLength * sizeof(char))) == NULL) {
		return (inputString);
	}

	while ((inputChar = getc(stdin)) != '\n') {
		inputString[currentLength++] = inputChar;

		if (currentLength == stringLength) {
			inputString =
			    realloc(inputString, (stringLength += INPUT_LENGTH) * sizeof(char));

			if (inputString == NULL) {
				return (inputString);
			}
		}
	}

	/* Exit early if there is no input */
	if (currentLength == 0) {
		return ("");
	}

	inputString[currentLength] = '\0';
	inputString = realloc(inputString, currentLength * sizeof(char));

	return (inputString);
}

/* Enters user input into starArray[starIndex]
   Exits early if allocation fails and returns 0 */
int enterStar(char *name, char *distance, char *year) {
	int size = sizeof(char);
	starStruct *star = &starArray[starIndex];

	if ((star->name = (char*) malloc(strlen(name) * size)) == NULL ||
	    (star->distanceFromEarth = (char*) malloc(strlen(distance) * size)) == NULL ||
	    (star->yearDiscovered = (char*) malloc(strlen(year) * size)) == NULL) {

		return (0);
	}

	strcpy(star->name, name);
	strcpy(star->distanceFromEarth, distance);
	strcpy(star->yearDiscovered, year);
	starIndex++;

	return (1);
}

int floatFormatCheck(char *input, int length) {
	int dividerCount = 0;

	for (int index = 0; index < length; index++) {
		if (input[index] == '.' && dividerCount == 0) {
			dividerCount++;
		} else if (!isdigit(input[index])) {
			return (0);
		}
	}

	return (1);
}

int integerFormatCheck(char *input, int length) {
	for (int index = 0; index < length; index++) {
		if (!isdigit(input[index])) {
			return (0);
		}
	}

	return (1);
}

int distanceFormatCheck(char *distance) {
	int length = strlen(distance);

	if (length == 0) {
		return (0);  // Fail
	}

	if (!floatFormatCheck(distance, length) &&
	    !(strcmp(distance, "N/A") == 0 || strcmp(distance, "n/a") == 0)) {
		return (1);  // Fail
	} else {
		return (2);  // Success
	}
}

int yearFormatCheck(char *year) {
	int length = strlen(year);

	if (length != 4) {
		return (0);  // Fail
	}

	if (!integerFormatCheck(year, length) &&
	    !(strcmp(year, "N/A") == 0 || strcmp(year, "n/a") == 0)) {
		return (1);  // Fail
	} else {
		return (2);  // Success
	}
}

void printStar(int index) {
	printf("Name: %s\n", starArray[index].name);
	printf("Distance: %s\n", starArray[index].distanceFromEarth);
	printf("Discovery: %s\n", starArray[index].yearDiscovered);
}

void printStars() {
	printf("*** List of stars you entered ***\n\n");
	for (int index = 0; index < starIndex; index++) {
		printStar(index);
		putc('\n', stdout);
	}
}
