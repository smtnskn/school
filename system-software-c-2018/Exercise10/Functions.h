/*
 * File:        Functions.h
 * Author:      Sami Tanskanen
 * Description: Header for Functions.h
 */

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define VERB_SIZE 15
#define RULES "\
\n\tRULES:\
\n\tScissors cuts Paper\
\n\tPaper covers Rock\
\n\tRock crushes Lizard\
\n\tLizard poisons Spock\
\n\tSpock smashes Scissors\
\n\tScissors decapitates Lizard\
\n\tLizard eats Paper\
\n\tPaper disproves Spock\
\n\tSpock vaporizes Rock\
\n\n\tBest of 3 wins!"

int chooseOne(int number1, int number2);
int chooseRange(int number1, int number2);
int playerInput();
int chooseCpuWeapon(int previousPlayerWeapon);
void weaponBeatenBy(int weapon, int *beatenBy1, int *beatenBy2);
int checkWinner(int playerWeapon, int cpuWeapon);
void getWeaponVerb(char *verbString, int victorsWeapon, int losersWeapon);
void weaponToString(char *weaponString, int weapon);

#endif
