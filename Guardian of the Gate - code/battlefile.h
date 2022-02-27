#ifndef battlefile
#define battlefile
#include "herostatistics.h"

void heroattack(herostats*, int[]);
// function called each time the player attacks an enemy
void validlivetargets(int[], int[]);
// function called by heroattack function. Checks which enemies are a valid target
int whosalive(int[], int[]);
// function which checks which enemies are alive and returns a value equal the amount of alive enemies
int battle(herostats*, int[], int[]);
// function which controls the battle against a single wave of enemies. Called each time the waveloop starts
void dideveryonemove(int[]);
// function which checks if everyone moved during a battle. if yes, it resets the whomoved array to its original state
void enemyturn(int[], int, herostats*);
// function during which the actions of enemy are carried out
void heroturn(int[], herostats*);
// function during which the player decides what to do in battle. chosen action is also carried out inside this function
int heroheal(herostats*);
// function called during heroturn function if the player decides to heal. If int curenergy is high enough, int curhealth is raised by a calculated amount
int calculatedamage(int*, int);
// function which calculates how much damage an enemy does to hero when attacking

#endif
