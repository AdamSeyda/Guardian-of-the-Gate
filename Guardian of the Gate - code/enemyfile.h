#ifndef enemyfile
#define enemyfile
#include "herostatistics.h"
#include<stdbool.h>

int waveamountgenerator(int);
// function which generates the amount of waves the player has to defeat during a single day
void newbattle(bool*, bool*, bool*, bool*, int*, herostats*, int);
// function called when the player leaves village to start the next battle. It starts the battleloop and calls waveamountgenerator function
void wavegenerator(int[], int*, int, herostats*);
// function which generates the amount and statistics of enemies
void enemiestablereset(int[]);
// function which sets all values of the enemies array to 0, must be run before wavegenerator to ensure there is no trash in enemies array

#endif
