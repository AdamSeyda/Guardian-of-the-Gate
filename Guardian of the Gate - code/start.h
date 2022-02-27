#ifndef start
#define start
#include "herostatistics.h"
#include<stdbool.h>

void loadlanguage(int);
// function called at start of game and when language is changed. It switches the entire text of game to one of specific language depending on given value (0 - polish, 1 - english)
void changelanguage();
// function called from main menu. Allows the player to choose language.
void loadgame(herostats*, int*, int*, int*, int*);
// function which loads the progress of player from a binary file
void setbools(int, bool*, bool*, bool*, bool*, bool*);
// function which changes bools to their proper values based on information from loadgame function
// it is a separate function bc for some reason loadgame didnt want to change values of bools
void instructions();
// function which prints game instructions
void newgame(herostats*);
// function which starts a new game, creating new hero

#endif
