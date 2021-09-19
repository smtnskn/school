/*
 * File:        Functions.c
 * Author:      Sami Tanskanen
 * Description: Functions for Exercise10.c
 */

#include "Functions.h"

/* Randomly chooses and returns one of the given numbers */
int chooseOne(int number1, int number2) {
	/* If rand() returns an even number, return number1 */
	if ((rand() & 1) == 0) {
		return (number1);
	}
	return (number2);
}

/* Randomly chooses a number within the given range, inclusive */
int chooseRange(int number1, int number2) {
	int min = (number1 < number2 ? number1 : number2);
	int max = (min == number1 ? number2 : number1);

	return (min + (rand() % (max - min + 1)));
}

int playerInput() {
	while (1) {
		printf("\n\n1. Rock\n2. Paper\n3. Scissors\n4. Lizard\n5. Spock");
		printf("\nChoose your weapon (1-5), or type \"help\" for assistance: ");

		char input[5];
		scanf("%s4", input);

		/* Player asked for assistance */
		if (strcmp(input, "help") == 0) {
			printf(RULES);
			continue;
		}

		/* Player chose a weapon */
		int weapon = atoi(input);
		if (weapon > 0 && weapon < 6) {
			return (weapon);
		}

		/* Invalid input */
		printf("\nINVALID INPUT");
		printf("\nOnly whole numbers from 1 to 5 and \"help\" are allowed");
	}
}

int chooseCpuWeapon(int previousPlayerWeapon) {
	/* If this is the first round, choose a random weapon
	   Otherwise, there is a 50% chance that the CPU chooses randomly */
	if (previousPlayerWeapon == 0 || chooseOne(0, 1) == 0) {
		return (chooseRange(1, 5));
	}

	/* Choose a weapon that beats the player's previously played weapon */
	int beatenBy1 = 0;
	int beatenBy2 = 0;
	weaponBeatenBy(previousPlayerWeapon, &beatenBy1, &beatenBy2);

	return (chooseOne(beatenBy1, beatenBy2));
}

void weaponBeatenBy(int weapon, int *beatenBy1, int *beatenBy2) {
	switch (weapon) {
	case 1:
		*beatenBy1 = 2; // Paper covers Rock
		*beatenBy2 = 5; // Spock vaporizes Rock
		break;
	case 2:
		*beatenBy1 = 3; // Scissors cuts Paper
		*beatenBy2 = 4; // Lizard eats Paper
		break;
	case 3:
		*beatenBy1 = 1; // Rock crushes Scissors
		*beatenBy2 = 5; // Spock smashes Scissors
		break;
	case 4:
		*beatenBy1 = 3; // Scissors decapitates Lizard
		*beatenBy2 = 1; // Rock crushes Lizard
		break;
	case 5:
		*beatenBy1 = 4; // Lizard poisons Spock
		*beatenBy2 = 2; // Paper disproves Spock
		break;
	}
}

void weaponToString(char *weaponString, int weapon) {
	switch (weapon) {
	case 1:
		strcpy(weaponString, "Rock");
		break;
	case 2:
		strcpy(weaponString, "Paper");
		break;
	case 3:
		strcpy(weaponString, "Scissors");
		break;
	case 4:
		strcpy(weaponString, "Lizard");
		break;
	case 5:
		strcpy(weaponString, "Spock");
		break;
	}
}

void getWeaponVerb(char *verbString, int victorsWeapon, int losersWeapon) {
	char verb[VERB_SIZE];
	switch (victorsWeapon) {
	case 1: // Rock
		strcpy(verb, "crushes");
		break;
	case 2: // Paper
		strcpy(verb, (losersWeapon == 1 ? "covers" : "disproves"));
		break;
	case 3: // Scissors
		strcpy(verb, (losersWeapon == 2 ? "cuts" : "decapitates"));
		break;
	case 4: // Lizard
		strcpy(verb, (losersWeapon == 5 ? "poisons" : "eats"));
		break;
	case 5: // Spock
		strcpy(verb, (losersWeapon == 3 ? "smashes" : "vaporizes"));
		break;
	}

	strcpy(verbString, verb);
}

int checkWinner(int playerWeapon, int cpuWeapon) {
	int beatenBy1 = 0;
	int beatenBy2 = 0;

	/* Return 1 if player won */
	weaponBeatenBy(cpuWeapon, &beatenBy1, &beatenBy2);
	if (beatenBy1 == playerWeapon || beatenBy2 == playerWeapon) {
		return (1);
	}

	/* Return 2 if CPU won */
	weaponBeatenBy(playerWeapon, &beatenBy1, &beatenBy2);
	if (beatenBy1 == cpuWeapon || beatenBy2 == cpuWeapon) {
		return (2);
	}

	/* Return 0 if the round is a tie */
	return (0);
}
