/*
 * File:        Exercise10.c
 * Author:      Sami Tanskanen
 * Description: An implementation of Rock, Paper, Scissors, Lizard, Spock
 */

#include "Functions.h"

int main() {
	int play = 1;
	int player = 1;

	srand(time(NULL));

	/* Main game loop */
	while (play) {
		int round = 1;
		int playerScore = 0;
		int cpuScore = 0;
		int previousPlayerWeapon = 0;

		printf("\n\n****************************************");
		printf("\n  Rock, Paper, Scissors, Lizard, Spock");
		printf("\n****************************************");
		printf("\n\nBest of 3 wins!");

		/* Rounds */
		while (cpuScore + playerScore < 3) {
			printf("\n\n========== ROUND %d ==========", round);
			printf("\n\nPlayer - %d", playerScore);
			printf("\nCPU - %d", cpuScore);
			round++;

			int playerWeapon = playerInput();
			int cpuWeapon = chooseCpuWeapon(previousPlayerWeapon);
			previousPlayerWeapon = playerWeapon;

			char playerWeaponString[10];
			char cpuWeaponString[10];
			weaponToString(playerWeaponString, playerWeapon);
			weaponToString(cpuWeaponString, cpuWeapon);

			printf("\nPlayer: %s", playerWeaponString);
			printf("\nCPU: %s", cpuWeaponString);

			int winner = checkWinner(playerWeapon, cpuWeapon);

			if (!winner) {
				printf("\nTied!");
				continue;
			}

			char verb[VERB_SIZE];
			if (winner == player) {
				getWeaponVerb(verb, playerWeapon, cpuWeapon);
				printf("\n%s %s %s.\nPlayer wins!",
				    playerWeaponString, verb, cpuWeaponString);
				playerScore++;
			} else {
				getWeaponVerb(verb, cpuWeapon, playerWeapon);
				printf("\n%s %s %s.\nCPU wins!",
				    cpuWeaponString, verb, playerWeaponString);
				cpuScore++;
			}
		}

		/* Declare winner, ask to continue */
		printf("\n\n%d-%d: ", playerScore, cpuScore);
		if (playerScore > cpuScore) {
			printf("Player won! Well played!");
		} else {
			printf("CPU won! Better luck next time!");
		}

		char input[2];
		while (1) {
			printf("\n\nPlay again? (y/n): ");
			scanf("%s2", input);

			if (strcmp(input, "n") == 0) {
				play = 0;
				break;
			} else if (strcmp(input, "y") == 0) {
				break;
			} else {
				printf("\nINVALID INPUT\nPlease enter \"y\" or \"n\".");
			}
		}
	}
}
