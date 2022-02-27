#ifndef optionsfile
#define optionsfile
#include "herostatistics.h"
#include<stdbool.h>

void options(bool*, herostats*, int, int, int, int);
// function which brings up and controls the options menu (saving, closing the game)
void savegame(herostats*, int, int, int, int);
// function which saves the progress of player to a binary file

#endif
