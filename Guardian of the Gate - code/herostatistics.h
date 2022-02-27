#ifndef herostatistics
#define herostatistics

typedef struct herostatistics{
    char heroname[7];
    int level, experience, strength, agility, intellect, endurance;
    int maxhealth, maxenergy, resistance;
    int curhealth, curenergy;
}herostats;
// struct herostats - struktura zawierajaca statystyki bohatera

char inttext[100][100];
// global string array storing the interface text f.e. menu options
char storytext[100][100];
// global string array storing the story text f.e.
char instrtext[15][150];
// global string array storing the instructions text
#endif
