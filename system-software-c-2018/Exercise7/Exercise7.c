/*
 * File:        Exercise7.c
 * Author:      Sami Tanskanen
 * Description: Program for storing and displaying star data
 */

#include "Stars.h"

int main() {
	initStarArray();

	int starAmount = -1;
	while (1) {
		printf("\nHow many stars do you want to add (0 - %d)? ", STAR_ARRAY_LENGTH);

		char isInteger = scanf("%d", &starAmount);
		if (isInteger == 0 ||
		    isInteger == EOF ||
		    starAmount < 0 ||
		    starAmount > STAR_ARRAY_LENGTH)
		{
			printf(INVALID_INPUT);
			flushInput();
		} else {
			putc('\n', stdout);
			flushInput();
			break;
		}
	}

	for ( ; starAmount > 0; starAmount--) {
		char *starName = NULL;
		char *starDistance = NULL;
		char *starYear = NULL;
		int invalidOrNoInput;

		invalidOrNoInput = 1;
		while (invalidOrNoInput) {
			if ((starName = userInput("Enter name of the star: ")) == NULL) {
				printf(INPUT_ALLOCATION_ERROR);
				return (1);
			} else if (strlen(starName) == 0) {
				printf(INVALID_INPUT_LENGTH);
			} else {
				invalidOrNoInput = 0;
			}
		}

		invalidOrNoInput = 1;
		while (invalidOrNoInput) {
			if ((starDistance = userInput("Enter distance from Earth: ")) == NULL) {
				printf(INPUT_ALLOCATION_ERROR);
			} else {
				switch (distanceFormatCheck(starDistance)) {
				case 0:
					printf(INVALID_INPUT_LENGTH);
					break;
				case 1:
					printf(INVALID_INPUT);
					break;
				default:
					invalidOrNoInput = 0;
				}
			}
		}

		invalidOrNoInput = 1;
		while (invalidOrNoInput) {
			if ((starYear = userInput("Enter discovery year: ")) == NULL) {
				printf(INPUT_ALLOCATION_ERROR);
			} else {
				switch (yearFormatCheck(starYear)) {
				case 0:
					printf(INVALID_INPUT_LENGTH);
					break;
				case 1:
					printf(INVALID_INPUT);
					break;
				default:
					invalidOrNoInput = 0;
				}
			}
		}

		enterStar(starName, starDistance, starYear);

		free(starName);
		free(starDistance);
		free(starYear);

		putc('\n', stdout);
	}

	printStars();

	return (0);
}
